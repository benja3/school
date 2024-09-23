#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "compressor.h"

typedef struct freq_node_ 
{
    uint8_t symbol;
    unsigned int freq;
} freq_node;

typedef struct heap_node_
{
	uint8_t symbol;
	unsigned int freq;
	struct heap_node_ *left;
    struct heap_node_ *right;
} heap_node;

typedef struct min_heap_
{
	unsigned int curr_size;
    unsigned int max_size;
	heap_node **arr;
} min_heap;

typedef struct freq_table_
{
	int size;
	unsigned int* data; // index represents symbol
} freq_table;

void print_freq_table(freq_table* freq_table)
{
	for(int i = 0; i < NUM_SYMBOLS; i++)
		printf("%d: %d\n", i, freq_table->data[i]);
}

unsigned int* create_freq_table(unsigned char *data, int n)
{
	int i, table_size = 0;
	unsigned int *freq_table = (unsigned int*)calloc(sizeof(unsigned int), NUM_SYMBOLS);
	for(i=0;i<n;i++) freq_table[data[i]]++;
	return freq_table;
}

min_heap* create_min_heap(int size)
{
    min_heap* heap = (min_heap *) calloc(1, sizeof(min_heap));
    heap->max_size = size;
    heap->curr_size = 0;
    heap->arr = (heap_node **) calloc(heap->max_size, sizeof(heap_node *));

    return heap;
    
}

void fill_min_heap(min_heap* heap, freq_node freq_table[])
{
    for(int i = 0; i < heap->max_size; i++)
        if(freq_table[i].freq > 0)
        {
            heap->arr[i] = (heap_node *) malloc(sizeof(heap_node));
            heap->arr[i]->symbol = freq_table[i].symbol;
            heap->arr[i]->freq = freq_table[i].freq;
            heap->curr_size++;
        }
}

void swap(heap_node **node1, heap_node **node2)
{
	heap_node *tmp = *node1;
	*node1 = *node2;
	*node2 = tmp;
}

void shift_down(min_heap *heap, int idx)
{
    int this, left, right;

    do 
    {
        idx = this; 
        left = 2 * idx + 1;
        right = left + 1;

		if(left < heap->curr_size && heap->arr[left]->freq < heap->arr[this]->freq) 
			this = left;
		if(right < heap->curr_size && heap->arr[right]->freq < heap->arr[this]->freq) 
			this = right;
		if(this != idx) 
			swap(&(heap->arr[this]), &(heap->arr[idx]));

    } while(this != idx);

}

heap_node *extract_min(min_heap *heap)
{
    
	swap(&(heap->arr[0]), &(heap->arr[heap->curr_size]));
    heap->curr_size--;

	shift_down(heap, 0);

	return heap->arr[heap->curr_size];
}

void insert_node(min_heap *heap, heap_node *new_node)
{
	int i = heap->curr_size++;
    int p = (i-1)/2;

	while(i && new_node->freq < heap->arr[p]->freq)
	{
		heap->arr[i] = heap->arr[p];
		i = p;
		p = (i-1)>>2;
	}

	heap->arr[i] = new_node;
}

// extract all nodes from the min heap of frequencies, and add them to the huffman tree
// by summing the two minimums 
min_heap* create_huffman_tree(min_heap* heap)
{
    heap_node *left;
    heap_node *right;
    heap_node *new;

	while(heap->curr_size > 1)
	{
		left = extract_min(heap);
		right = extract_min(heap);

		new = (heap_node *) malloc(sizeof(heap_node));
        new->freq = right->freq + left->freq;
        new->symbol = 0xFF;
		
        new->left = left;
		new->right = right;

		insert_node(heap, new);
	}

	return heap;
}

int tree_height(heap_node *root)
{
	if(!root) return 0;
	int l = tree_height(root->left), r = tree_height(root->right);
	return 1 + (l>r?l:r);
}
void print_arr(int *arr, int n)
{
	for(int i=0;i<n;i++) printf("%d", arr[i]);
	printf("\n");
}
void print_codes(heap_node *root, int *arr, int idx)
{
	if(root)
	{
		if(root->left) {arr[idx] = 0; print_codes(root->left, arr, idx+1);}
		if(root->right) {arr[idx] = 1; print_codes(root->right, arr, idx+1);}
		if(!root->left && !root->right) {printf("%c: ", root->symbol); print_arr(arr, idx);}
	}	
}

heap_node *create_node(unsigned char data, int freq)
{
	heap_node *_heap_node = (heap_node*)malloc(sizeof(heap_node));
	_heap_node->symbol = data;
	_heap_node->freq = freq;
	_heap_node->left = _heap_node->right = NULL;
	return _heap_node;
}

min_heap* create_min_q(unsigned char *data, int n)
{
	int i, table_size = 0;
	unsigned int *freq_table = (unsigned int*)calloc(sizeof(unsigned int), 256);

	// create freq table
	for(i=0;i<n;i++) freq_table[data[i]]++;
	for(i=0;i<256;i++) if(freq_table[i])table_size++;
	printf("table size: %d\n", table_size);


	min_heap *m_heap = (min_heap*)calloc(sizeof(min_heap), 1);
	m_heap->max_size = table_size;
	m_heap->arr = (heap_node**)malloc(sizeof(heap_node*) * m_heap->max_size);

	for(i=0;i<256;i++) if(freq_table[i]) m_heap->arr[m_heap->size++] = create_node(i, freq_table[i]);


	for(int i=m_heap->curr_size/2;i>=0;i--) shift_down(m_heap, i);
	free(freq_table);

	return m_heap;
}

unsigned int code_concat(unsigned int code, unsigned int new_bit)
{
	code = code << 1;

    if(new_bit == 1)
    {
        return code ^ 0x1;
    }
    else
    {
        return code;
    }
}

void fill_huffman_table(code_node* table[], node* tree, node* node, unsigned int code, int code_length)
{
	if (node->left == NULL && node->right == NULL) // base: leaf node
	{
        table[(uint8_t) node->data]->code = code;
        table[(uint8_t) node->data]->symbol = node->data;
        table[(uint8_t) node->data]->length = code_length;

        printf("[DEBUG] Added table node (symbol: %c, byte value: %d, code length: %d, code: ", table[(uint8_t) node->data]->symbol, (uint8_t) table[(uint8_t) node->data]->symbol, code_length);
        for (int i = code_length - 1; i >= 0; i--)
            if ((table[(uint8_t) node->data]->code >> i ) & 1)
                printf("1");
            else
                printf("0");
        printf(")\n");


	}
	else // interior node
	{
        code_length++;
		fill_huffman_table(table, tree, node->right, code_concat(code, 1), code_length);
		fill_huffman_table(table, tree, node->left, code_concat(code, 0), code_length);
	}

}

void print_table(code_node* huffman_table[])
{
    for(int i = 0; i < NUM_SYMBOLS; i++)
    {
        printf("%d: %d\t%c\n", i, huffman_table[i]->code, huffman_table[i]->symbol);
    }
}

// copy size bits from src to dst starting at offset in dst buffer
// dst_offset is the first bit to be updated when counting up from position 0
unsigned int cp_to_buf(unsigned int src, unsigned int dst, unsigned int src_offset, unsigned int dst_offset, unsigned int size)
{
    src = src >> src_offset;
    src &= (1 << size) - 1; // clear bits outside of range

    unsigned int mask = src << dst_offset;

    return dst | mask;
}

void huffman_compress(meta_data *in_data, meta_data *out_data)
{
	uint8_t read_buffer;
    min_heap* huffman_tree;

    // step 1: calculate frequencies

    // create frequency table
    freq_node freq_table[256];
    
    for(int i = 0; i <= 255; i++)
        freq_table[i].symbol = (uint8_t) i; // initialize symbols

    // read from file into freq table
    while (fread(&read_buffer, sizeof(uint8_t), 1, raw_file) > 0)
        freq_table[read_buffer].freq++;

    // set up min heap

    min_heap* min_heap = create_min_heap(256);
    fill_min_heap(min_heap, freq_table);

    for(int i = min_heap->curr_size / 2; i >= 0; i--)
        shift_down(min_heap, i);

    min_heap = create_min_q()

    huffman_tree = create_huffman_tree(min_heap);

	// huffman tree is assembled. now must create table with codes

	code_node* huffman_table[NUM_SYMBOLS];

	// initialize huffman table
    for(int i = 0; i < NUM_SYMBOLS; i++)
    {
        huffman_table[i] = calloc(1, sizeof(code_node));
    }

	fill_huffman_table(huffman_table, h_tree, h_tree, 0, 0);

    // print_table(huffman_table);

    // write codes to output file in replacement of the original byte

    int write_buf = 0;
    uint8_t read_buf;

    int offset = WRITE_BUF_BITS - 1;
    unsigned int code;
    unsigned int length;

    uint8_t OL_code;
    int OL_remainder = 0;
	int code_bits_in_last_buffer;

    in_data->fpt = fopen(in_data->file_name, "r");
    out_data->fpt = fopen(out_data->file_name, "w");

	// write freq table as first sizeof(int) * 256 compressed file
	fwrite(&freq_table->size, sizeof(int), 1, out_data->fpt);
	fwrite(freq_table->data, sizeof(unsigned int), NUM_SYMBOLS, out_data->fpt);

    fseek(in_data->fpt, 0, SEEK_SET);

    while(fread(&read_buf, sizeof(uint8_t), 1, in_data->fpt))
    {
        code = huffman_table[read_buf]->code;
        length = huffman_table[read_buf]->length;


        if(offset + 1 > length) // code fits in write buffer
        {
            write_buf = cp_to_buf(code, write_buf, 0, offset - length + 1, length);
            offset -= length; // update offset to next free bit position
        }
        else // entire code cannot fit in buffer, so split across this and the next buf
        {
            // OL_code = code;
            OL_remainder = length - (offset + 1);

						// start copying bits at OL_remainder offset in src for correct portion of code
						// src, dst, src_off, dst_off, size
            write_buf = cp_to_buf(code, write_buf, OL_remainder, 0, offset + 1);

            offset -= length;
        }

        // check if write buffer full
        if (offset < 0)
            {
                fwrite(&write_buf, sizeof(int), 1, out_data->fpt);

                memset(&write_buf, 0, sizeof(int));

                // handle writing the remainder before next symbol read, if applicable
                if(OL_remainder > 0)
                {
										offset = WRITE_BUF_BITS - 1;
                    write_buf = cp_to_buf(code, write_buf, 0, offset - OL_remainder + 1, OL_remainder);

                    offset -= OL_remainder;
                    OL_remainder = 0;

                }
				else
				{
					offset = WRITE_BUF_BITS - 1;
				}



            }
    }

    // write final buffer value
    fwrite(&write_buf, sizeof(int), 1, out_data->fpt);

	FILE* cringe_ptr = fopen("./cringe", "w");
	unsigned int cringe_int = NUM_SYMBOLS - 1 - offset;
	fwrite(&cringe_int, sizeof(int), 1, cringe_ptr);

	// need to write number of bits in the last buffer
	// that are codes
	// can detect last buffer by 

}



unsigned int bit_at_offset(unsigned int read_buf, int offset)
{
	unsigned int bit = read_buf >> offset;

	unsigned int mask = 0x1;
	bit &= mask; // clear all accept last bit

	return bit;
}


void huffman_decompress(FILE* compressed_file, FILE* raw_file)
{

	freq_table* freq_table = calloc(1, sizeof(freq_table));
	freq_table->data = (unsigned int *) calloc(NUM_SYMBOLS, sizeof(unsigned int));


	// read in frequency table from compressed file
	int size;
	unsigned int data[256];
	fread(&size, sizeof(int), 1, compressed_file);
	fread(&data, NUM_SYMBOLS, sizeof(unsigned int), compressed_file);

	freq_table->data = data;
	freq_table->size = size;

	print_freq_table(freq_table);

	int cringe_int;
	FILE* cringe_ptr = fopen("./cringe", "r");
	fread(&cringe_int, sizeof(int), 1, cringe_ptr);
	printf("%d\n", cringe_int);

	// reconstruct tree from freq_table
	min_heap *m_heap = create_min_q(freq_table);
	node *h_tree = huffman_tree(m_heap);

	unsigned int read_buf;
	int offset;
	unsigned int bit;
	unsigned int code;
	int OL = 0; // flag for code that spands multiple buffers

	node* node;

	while(fread(&read_buf, sizeof(unsigned int), 1, compressed_file) > 0)
	{
		offset = WRITE_BUF_BITS - 1;
		while(offset >= 0) // process buffer
		{
			if(!OL) // if overloaded, resume searching at current node
				node = h_tree; // start at root

			OL = 0;

			while(!(node->right == NULL && node->left == NULL)) // process code
			{
				// traverse heap adding bits to code

				bit = bit_at_offset(read_buf, offset);

				if(bit == 1) //
				{
					node = node->right;
				}
				else
				{
					node = node->left;
				}

				offset--; // offset may go below 0

				if(offset < 0)
				{
					OL = 1;
					break;
				}
				// stop descending if at end of buffer

				// break the loop and continue descending at start of next buffer
			}

			// now at leaf

			if(!OL) // do not write if overflow
				fwrite(&node->data, sizeof(uint8_t), 1, raw_file);
		}
	}
}
