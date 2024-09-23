#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/stat.h>

#include "compressor.h"

int get_file_size(char *filename)
{
	struct stat file_status;
	if (stat(filename, &file_status) < 0) return -1;
	return file_status.st_size;
}

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
        printf("Encodings available: RLE, LZW, huffman\n");
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
            printf("Compressing %s with %s encoding ...\n", argv[3], encoding);
            lzw_compress(input_file, output_file);
        }
        else if(strcmp(mode, "decompress") == 0)
        {
            printf("Decompressing %s with %s encoding ...\n", argv[3], encoding);
            lzw_decompress(input_file, output_file);
        }
        else
            goto bad_input;
    else if(strcmp(encoding, "huffman") == 0)
        if(strcmp(mode, "compress") == 0)
        {
            printf("Compressing %s with %s encoding ...\n", argv[3], encoding);

            meta_data in_data, out_data;

            in_data.file_name = strdup(argv[3]);
            out_data.file_name = strdup(argv[4]);

            in_data.file_size = get_file_size(in_data.file_name);
            huffman_compress(&in_data, &out_data);
        }
        else if(strcmp(mode, "decompress") == 0)
        {
            printf("Decompressing %s with %s encoding ...\n", argv[3], encoding);

						meta_data in_data, out_data;

            in_data.file_name = strdup(argv[3]);
            out_data.file_name = strdup(argv[4]);

            in_data.file_size = get_file_size(in_data.file_name);
            huffman_decompress(input_file, output_file);

        }
        else
            goto bad_input;

    else
        goto bad_input;



}
