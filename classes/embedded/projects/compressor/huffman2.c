#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include <stdint.h>

#define NUM_SYMBOLS 256
#define WRITE_BUF_BITS 32

typedef struct meta_data
{
	char *file_name;
	int size, ele_size;
	FILE *fpt;
	void *data;
}meta_data;

void read_data(meta_data *meta_d)
{
	meta_d->data = (void*)calloc(meta_d->size, meta_d->ele_size);
	meta_d->fpt = fopen(meta_d->file_name, "r");
	fread(meta_d->data, meta_d->ele_size, meta_d->size/meta_d->ele_size, meta_d->fpt);
	fclose(meta_d->fpt);
}
void write_data(meta_data *meta_d)
{
	meta_d->fpt = fopen(meta_d->file_name, "w");
	fwrite(meta_d->data, meta_d->ele_size, meta_d->size, meta_d->fpt);
	fclose(meta_d->fpt);
}

typedef struct Node
{
	char data;
	unsigned int freq;
	struct Node *left, *right;
}node;

typedef struct Min_heap
{
	unsigned int size, capcity;
	node **arr;
}min_heap;

typedef struct code_node_
{
	uint8_t symbol;
	unsigned int code;
	unsigned int length;
} code_node;

typedef struct freq_table_
{
	int size;
	unsigned int* data; // index represents symbol
} freq_table;


/*
void print_table(unsigned int *freq_table)
{
	char c = 0;
	for(int i=0;i<NUM_SYMBOLS;i++, c++) printf("%d (%c), %d\n", i, c, freq_table[i]);
	printf("\n");
}
*/

void print_data(unsigned char *data, int n)
{
	for(int i=0;i<n;i++, data++) printf("%c", *data);
	printf("\n");
}
void print_min_q(node **arr, int n)
{
	for(int i=0;i<n;i++) printf("%c - %d\n", arr[i]->data, arr[i]->freq);
	printf("\n");
}
node *create_node(unsigned char data, int freq)
{
	node *_node = (node*)malloc(sizeof(node));
	_node->data = data;
	_node->freq = freq;
	_node->left = _node->right = NULL;
	return _node;
}
void swap(node **a, node **b)
{
	node *t = *a;
	*a = *b;
	*b = t;
}
void shift_down(min_heap *m_heap, int idx)
{
	int l,r,s=idx;
	do {
		idx = s; l = 2*idx+1; r = l+1;
		if(l<m_heap->size && m_heap->arr[l]->freq < m_heap->arr[s]->freq) s = l;
		if(r<m_heap->size && m_heap->arr[r]->freq < m_heap->arr[s]->freq) s = r;
		if(s!=idx) swap(&(m_heap->arr[s]), &(m_heap->arr[idx]));
	} while (s != idx);
}

void print_freq_table(freq_table* freq_table)
{
	for(int i = 0; i < NUM_SYMBOLS; i++)
		printf("%d: %d\n", i, freq_table->data[i]);
}

freq_table* create_f_table(unsigned char *data, int n)
{
	freq_table* f_table = (freq_table *) calloc(1, sizeof(freq_table));

	f_table->size = 0;
	int i = 0;

	f_table->data = (unsigned int*)calloc(sizeof(unsigned int), NUM_SYMBOLS);
	for(i=0;i<n;i++) f_table->data[data[i]]++;
	for(i=0;i<NUM_SYMBOLS;i++) if(f_table->data[i]) f_table->size++;
	printf("table size: %d\n", f_table->size);

	print_freq_table(f_table);

	return f_table;
}

min_heap* create_min_q(freq_table* f_table)
{
	int i = 0;
	min_heap *m_heap = (min_heap*)calloc(sizeof(min_heap), 1);
	m_heap->capcity = f_table->size;
	m_heap->arr = (node**)malloc(sizeof(node*)*m_heap->capcity);
	for(i=0;i<NUM_SYMBOLS;i++) if(f_table->data[i]) m_heap->arr[m_heap->size++] = create_node(i, f_table->data[i]);
	for(int i=m_heap->size/2;i>=0;i--) shift_down(m_heap, i);
	return m_heap;
}
unsigned int* create_freq_table(unsigned char *data, int n)
{
	int i, table_size = 0;
	unsigned int *freq_table = (unsigned int*)calloc(sizeof(unsigned int), NUM_SYMBOLS);
	for(i=0;i<n;i++) freq_table[data[i]]++;
	return freq_table;
}
node *extract_min(min_heap *m_heap)
{
	swap(&(m_heap->arr[0]), &(m_heap->arr[--m_heap->size]));
	shift_down(m_heap, 0);
	return m_heap->arr[m_heap->size];
}
void insert_node(min_heap *m_heap, node *new_node)
{
	int i = m_heap->size++, p = (i-1)/2;
	while(i && new_node->freq < m_heap->arr[p]->freq)
	{
		m_heap->arr[i] = m_heap->arr[p];
		i = p;
		p = (i-1)>>2;
	}
	m_heap->arr[i] = new_node;
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		if(root->data != '$') printf("%c :: %d\n", root->data, root->freq);
		inorder(root->right);
	}
}
node *huffman_tree(min_heap *m_heap)
{
	node *l, *r, *t;
	while(m_heap->size != 1)
	{
		l = extract_min(m_heap);
		r = extract_min(m_heap);
		t = create_node('$', l->freq+r->freq);
		t->left = l;
		t->right = r;
		insert_node(m_heap, t);
	}
	return m_heap->arr[0];
}
int tree_height(node *root)
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
void print_codes(node *root, int *arr, int idx)
{
	if(root)
	{
		if(root->left) {arr[idx] = 0; print_codes(root->left, arr, idx+1);}
		if(root->right) {arr[idx] = 1; print_codes(root->right, arr, idx+1);}
		if(!root->left && !root->right) {printf("%c: ", root->data); print_arr(arr, idx);}
	}
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
	in_data->ele_size = sizeof(unsigned char);
	read_data(in_data);
	freq_table* freq_table = create_f_table(in_data->data, in_data->size);
	min_heap *m_heap = create_min_q(freq_table);
	node *h_tree = huffman_tree(m_heap);
	// printf("height: %d\n", tree_height(h_tree));
	// printf("capcity: %d\n", m_heap->capcity);
	int arr[tree_height(h_tree)];

	print_codes(h_tree, arr, 0);

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

    in_data->fpt = fopen(in_data->file_name, "r");
    out_data->fpt = fopen(out_data->file_name, "w");

	// write freq table as first sizeof(int) * 256 compressed file
	fwrite(&in_data->size, sizeof(int), 1, out_data->fpt);
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
	int num_codes = 0;
	unsigned int data[256];

	fread(&num_codes, sizeof(int), 1, compressed_file);
	fread(&size, sizeof(int), 1, compressed_file);
	fread(&data, NUM_SYMBOLS, sizeof(unsigned int), compressed_file);

	freq_table->data = data;
	freq_table->size = size;

	print_freq_table(freq_table);

	// reconstruct tree from freq_table
	min_heap *m_heap = create_min_q(freq_table);
	node *h_tree = huffman_tree(m_heap);

	unsigned int read_buf;
	int offset;
	unsigned int bit;
	unsigned int code;
	int OL = 0; // flag for code that spands multiple buffers
	int symbols_written = 0;

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
			{
				fwrite(&node->data, sizeof(uint8_t), 1, raw_file);
				symbols_written++;
			}

			if(symbols_written >= num_codes)
				exit(0);

		}
	}
}
