#include <stdint.h>

#define DO_MARKERS 0
#define RLE_DISABLE_PREDICT_BYTES 3

#define MAX_ENTRIES 65536
#define ENTRY_BUFFER 256

typedef struct meta_data_
{
	char *file_name;
	int file_size;
    int elem_size;
	FILE *fpt;
	void *data;
} meta_data;

// compressors
void rle_compress(FILE* raw_file, FILE* compressed_file);
void rle_decompress(FILE* compressed_file, FILE* raw_file);

void lzw_compress(FILE* raw_file, FILE* compressed_file);
void lzw_decompress(FILE* compressed_file, FILE* raw_file);

void huffman_compress(meta_data *in_data, meta_data *out_data);
void huffman_decompress(FILE* compressed_file, FILE* raw_file);

// helper functions

// rle
int rle_run_detected(FILE* raw_file, int look_ahead_bytes);

// lzw
int lzw_search_table(short table[][ENTRY_BUFFER], uint8_t search_key[], uint8_t length[], uint8_t buffer_length);
int lzw_buffer_compare(uint8_t buf1[], uint8_t buf2[], uint8_t length1, uint8_t length2);
void lzw_add_table_entry(short table[][ENTRY_BUFFER], uint8_t entry[], uint8_t entry_length, uint8_t length[]);
void lzw_debug_print_table(short table[][ENTRY_BUFFER], uint8_t length[]);
int lzw_next_free_index(uint8_t length[MAX_ENTRIES]);
