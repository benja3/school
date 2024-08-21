#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "compressor.h"

// may need function to concat bytes


void lzw_compress(FILE* raw_file, FILE* compressed_file)
{

    uint8_t curr;
    uint8_t prev[ENTRY_BUFFER];
    uint8_t prev_length;
    int prev_code_index; 
    uint8_t prev_cat_curr[ENTRY_BUFFER];
    short table[MAX_ENTRIES][ENTRY_BUFFER]; // must be short because codes are 2 bytes
    uint8_t length[MAX_ENTRIES]; // stores lengths of patterns in table

    // initialize the table with the symbols of the alphabet

    for(int i = 0; i <= 255; i++)
        table[i][0] = (uint8_t) i; // set first byte

    for(int i = 0; i <= MAX_ENTRIES; i++)
        if(i <= 255)
            length[i] = 1;
        else 
            length[i] = 0; // table entries that are not initalized have length 0
        
    // reading the buffer bytes from left to right to interpret code

    // handle first character
    fread(&curr, sizeof(uint8_t), 1, raw_file);

    // first byte guaranteed to be in table due to intialization

    prev[0] = curr;
    prev_length = 1; 

    while(fread(&curr, sizeof(uint8_t), 1, raw_file) > 0)
    {
        // concatenate prev with curr
        memcpy(prev_cat_curr, prev, prev_length);
        prev_cat_curr[prev_length] = curr;

        // search for prev_cat_curr in table
        int code_index = lzw_search_table(table, prev_cat_curr, length, prev_length + 1);
        if(code_index != INT_MAX) // found in table
        {
            prev_length++;
            memcpy(prev, prev_cat_curr, prev_length);
        }
        else // prev_cat_curr not in table
        {
            prev_code_index = lzw_search_table(table, prev, length, prev_length);
            fwrite((short *) &prev_code_index, sizeof(short), 1, compressed_file);

            // add prev_cat_curr to table
            lzw_add_table_entry(table, prev_cat_curr, prev_length + 1, length);

            // set value of prev to curr
            memset(prev, 0, ENTRY_BUFFER);
            memset(prev_cat_curr, 0, ENTRY_BUFFER);
            memset(prev, (int) curr, 1);
            prev_length = 1;
        }

    }
    
    prev_code_index = lzw_search_table(table, prev, length, prev_length);
    fwrite((short *) &prev_code_index, sizeof(short), 1, compressed_file);

    // lzw_debug_print_table(table, length);
} 

void lzw_add_table_entry(short table[][ENTRY_BUFFER], uint8_t entry[], uint8_t entry_length, uint8_t length[])
{
    // find last entry in table
    int index = 0;
    while(length[index] > 0)
        index++;

    assert(index < MAX_ENTRIES);

    memcpy(table[index], entry, MAX_ENTRIES);
    length[index] = entry_length; 
}

// returns the location in the table if prev found in table and INT_MAX otherwise
int lzw_search_table(short table[][ENTRY_BUFFER], uint8_t search_key[], uint8_t length[], uint8_t buffer_length)
{
    for(int i = 0; length[i] != 0 && i < MAX_ENTRIES; i++)
        if(lzw_buffer_compare((uint8_t *) table[i], search_key, length[i], buffer_length) == 1)
            return i;

    return INT_MAX;
}

// iterate through table buffer and prev to compare 
//
// this function is intended to loop through the table and compare a search key buffer to 
// other buffers in the table
//
// if the lengths of the buffers are different, then they are guaranteed to not be the same
// and the function returns false
int lzw_buffer_compare(uint8_t buf1[], uint8_t buf2[], uint8_t length1, uint8_t length2)
{
    if (length1 != length2)
        return 0;

    for(int i = 0; i < length1; i++)
        if(buf1[i] != buf2[i])
            return 0;
    
    return 1;
}

void lzw_debug_print_table(short table[][ENTRY_BUFFER], uint8_t length[])
{
    int i = 0;
    while(length[i] > 0)
    {
        printf("%d\t%s\n", i, (char *) table[i]);
        i++;
    }
}

void lzw_decompress(FILE* compressed_file, FILE* raw_file)
{
    // var declarations
    short table[MAX_ENTRIES][ENTRY_BUFFER]; // must be short because codes are 2 bytes
    uint8_t length[MAX_ENTRIES]; // stores lengths of patterns in table
    short curr;
    short prev;
    uint8_t X_cat_Y[ENTRY_BUFFER];
    uint8_t X_cat_Z[ENTRY_BUFFER];

    // initialize
    for(int i = 0; i <= 255; i++)
        table[i][0] = (uint8_t) i; // set first byte

    for(int i = 0; i <= MAX_ENTRIES; i++)
        if(i <= 255)
            length[i] = 1;
        else 
            length[i] = 0; // table entries that are not initalized have length 0

    // table will have same structure as in compression

    // first case

    fread(&curr, sizeof(short), 1, compressed_file);
    fwrite(&table[curr][0], sizeof(uint8_t), 1, raw_file);

    prev = curr;

    while(fread(&curr, sizeof(short), 1, compressed_file) > 0)
    {
        if(length[curr] > 0) // if pattern defined
        {
            fwrite(table[curr], sizeof(uint8_t), length[curr], raw_file);

            memcpy(X_cat_Y, table[prev], length[prev]);
            X_cat_Y[length[prev]] = table[curr][0];

            lzw_add_table_entry(table, X_cat_Y, length[prev] + 1, length);  

            memset(X_cat_Y, 0, ENTRY_BUFFER);
            
        }
        else // pattern not defined
        {
            memcpy(X_cat_Z, table[prev], length[prev]);
            X_cat_Z[length[prev]] = table[prev][0];
            fwrite(X_cat_Z, sizeof(uint8_t), length[prev] + 1, raw_file);
            
            lzw_add_table_entry(table, X_cat_Z, length[prev] + 1, length);

            memset(X_cat_Z, 0, ENTRY_BUFFER);

        }

        prev = curr;
    }

    // lzw_debug_print_table(table, length);
}

int lzw_next_free_index(uint8_t length[MAX_ENTRIES])
{
    int i = 0;

    while(length[i] > 0)
        i++;

    return i;
}