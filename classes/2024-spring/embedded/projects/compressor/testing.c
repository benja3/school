#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "compressor.h"

int LZWEncodeFile(FILE *fpIn, FILE *fpOut);

int main(int argc, char* argv[])
{
    char* encoding;
    char* mode;
    FILE* input_file;
    FILE* output_file;

    // process user input
    if(argv[1] == NULL || strcmp(argv[1], "-h") == 0 || argc != 5)
    {
        bad_input: 

        printf("Usage: ./compressor <compress/decompress> <encoding> <raw_file> <compressed_file>\n");
        printf("Encodings available: RLE, LZW\n");
        exit(1);
    }

    encoding = argv[2];
    mode = argv[1];

    input_file = fopen(argv[3], "r");

    if(input_file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    output_file = fopen(argv[4], "w");

    if(strcmp(encoding, "RLE") == 0)
        if(strcmp(mode, "compress") == 0)
        {
            printf("Compressing %s with %s encoding ...\n", argv[3], encoding);
            rle_compress(input_file, output_file);
        }
        else if(strcmp(mode, "decompress") == 0)
        {
            printf("Decompressing %s with %s encoding ...\n", argv[3], encoding);
            rle_decompress(input_file, output_file);
        }
        else 
            goto bad_input;
    else if(strcmp(encoding, "LZW") == 0)
        if(strcmp(mode, "compress") == 0)
        {

            uint8_t buf1[] = {0, 22, 33, 44, 93};
            uint8_t buf2[] = {0, 22, 33, 44, 93};

            assert(lzw_buffer_compare(buf1, buf2, 5));

            uint8_t buf3[] = {0, 22, 33, 44, 94};
            uint8_t buf4[] = {0, 22, 33, 44, 93};

            assert(!lzw_buffer_compare(buf3, buf4, 5));

            uint8_t buf5[] = {1, 22, 33, 44, 93};
            uint8_t buf6[] = {0, 22, 33, 44, 93};

            assert(!lzw_buffer_compare(buf5, buf6, 5));

            uint8_t prev_cat_curr[] = {1, 22, 33, 44, 93};

            
        }
        else if(strcmp(mode, "decompress") == 0)
        {
            printf("Decompressing %s with %s encoding ...\n", argv[3], encoding);
            lzw_decompress(input_file, output_file);
        }
        else 
            goto bad_input;

    else 
        goto bad_input;


    
}