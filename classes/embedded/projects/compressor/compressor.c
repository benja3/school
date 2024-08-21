#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

#include "compressor.h"

void compress_rle(FILE* raw_file, FILE* compressed_file)
{
    uint8_t run_length; // assuming run_length will not exceed 255
    uint8_t* read_value_curr;
    uint8_t* read_value_prev;
    int compressing;
    int bytes_before_predict;
    char NULL_CHAR;

    run_length = 0;
    read_value_curr = calloc(1, sizeof(uint8_t));
    read_value_prev = NULL;
    compressing = 1;
    NULL_CHAR = (char) 0;

    // printf("%d\n", rle_run_detected(raw_file, RLE_DISABLE_PREDICT_BYTES));

    while(fread(read_value_curr, sizeof(uint8_t), 1, raw_file) > 0)
    {
      if(compressing)
      {
        if(read_value_prev == NULL) // first symbol
        {
            //printf("DEBUG: read_value_prev = NULL\n");
            run_length++;
            read_value_prev = calloc(1, sizeof(uint8_t));
        }
        else if(*read_value_curr == *read_value_prev && run_length < 255) // run continues
        {
            run_length++;
        }
        else // new run
        {
            fwrite((char *) (&run_length), sizeof(char), 1, compressed_file);
            fwrite(read_value_prev, sizeof(char), 1, compressed_file);

            run_length = 1;

            // predict whether to turn off compression
            // printf("DEBUG: run_detected = %d\n", rle_run_detected(raw_file, RLE_DISABLE_PREDICT_BYTES));
            if(DO_MARKERS && !rle_run_detected(raw_file, RLE_DISABLE_PREDICT_BYTES))
            {
              compressing = 0;
              bytes_before_predict = 3;
              fwrite(&NULL_CHAR, sizeof(char), 1, compressed_file); // mark compression disable

              if(*read_value_curr == (char) 0)
              {
                char escape_buffer[4];

                escape_buffer[0] = (char) 0;
                escape_buffer[1] = (char) 1;
                escape_buffer[2] = (char) 0;
                escape_buffer[3] = (char) 0;

                fwrite(escape_buffer, sizeof(char), 4, compressed_file);
              }
              else
              {
                fwrite(read_value_curr, sizeof(char), 1, compressed_file); // write first byte of non compressed seq
              }
            }


        }

        *read_value_prev = *read_value_curr;
      }
      else
      {
        // rle is disabled for bytes_before_predict more bytes

        if(*read_value_curr == (char) 0)
        {
          char escape_buffer[4];

          escape_buffer[0] = (char) 0;
          escape_buffer[1] = (char) 1;
          escape_buffer[2] = (char) 0;
          escape_buffer[3] = (char) 0;

          fwrite(escape_buffer, sizeof(char), 4, compressed_file);
        }
        else
          fwrite(read_value_curr, sizeof(char), 1, compressed_file);

        bytes_before_predict--;

        if(rle_run_detected(raw_file, RLE_DISABLE_PREDICT_BYTES))
        {
          compressing = 1;
          fwrite(&NULL_CHAR, sizeof(char), 1, compressed_file); // mark compression enable

          // prepare buffer for next compressed write
          fread(read_value_prev, sizeof(char), 1, raw_file);
          fseek(raw_file, -1, SEEK_CUR);

          run_length = 0;
        }

      }

    }

    if(compressing)
    {
      fwrite((char *) (&run_length), sizeof(char), 1, compressed_file);
      fwrite(read_value_prev, sizeof(char), 1, compressed_file);
    }


}

int rle_run_detected(FILE* raw_file, int look_ahead_bytes)
{
  char predict_buf[look_ahead_bytes];
  int match_found = 0;
  int orig_file_ptr = ftell(raw_file);

  fseek(raw_file, -1, SEEK_CUR); // move back 1 bc file ptr is ahead of first byte of new run
  int read_size = fread(predict_buf, sizeof(char), look_ahead_bytes, raw_file);
  fseek(raw_file, 1, SEEK_CUR);
  fseek(raw_file, -read_size, SEEK_CUR);

  for(int i = 0; i < look_ahead_bytes - 1; i++)
    if(predict_buf[i] == predict_buf[i + 1])
      match_found = 1;

  if(read_size < look_ahead_bytes)
    match_found = 0;

  assert(orig_file_ptr == ftell(raw_file));

  return match_found;
}


void decompress_rle(FILE* compressed_file, FILE* raw_file)
{
    uint8_t run_length;
    char* symbol;
    int rle_enabled;

    symbol = calloc(1, sizeof(char));
    rle_enabled = 1; // rle enabled at start

    while(fread((uint8_t *) (&run_length), sizeof(char), 1, compressed_file) > 0)
    {
      if (run_length == (char) 0) // marker detected
      {
          rle_enabled = !rle_enabled;
          continue;
      }


      if(rle_enabled)
      {
        fread(symbol, sizeof(char), 1, compressed_file); // if size read successfully, symbol guaranteed to follow
        for(int i = 0; i < run_length; i++)
            fwrite(symbol, sizeof(char), 1, raw_file);
      }
      else
      {
        fwrite((char *) (&run_length), sizeof(char), 1, raw_file);
      }
    }
}
