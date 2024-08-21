#include <stdlib.h>
#include <stdint.h>

#include "imgdisp.h"

void test_greyscale_file_disp()
    {
        uint8_t filepix;
        uint16_t disppix;

        filepix = 0b10101010;
        disppix = 0;

        disppix = cp_msbits_to_buffer(filepix, disppix, RED_SIZE_16BIT, RED_OFFSET_16BIT);
        disppix = cp_msbits_to_buffer(filepix, disppix, GREEN_SIZE_16BIT, GREEN_OFFSET_16BIT);
        disppix = cp_msbits_to_buffer(filepix, disppix, BLUE_SIZE_16BIT, BLUE_OFFSET_16BIT);
    }

void test_rgb_file_disp()
{
    uint8_t redpix = 0b11111111;
    uint8_t greenpix = 0b00000000;
    uint8_t bluepix = 0b10101010;
    uint16_t disppix = 0;

    disppix = cp_msbits_to_buffer(redpix, disppix, RED_SIZE_16BIT, RED_OFFSET_16BIT);
    disppix = cp_msbits_to_buffer(greenpix, disppix, GREEN_SIZE_16BIT, GREEN_OFFSET_16BIT);
    disppix = cp_msbits_to_buffer(bluepix, disppix, BLUE_SIZE_16BIT, BLUE_OFFSET_16BIT);
}

int main() 
    {
        test_greyscale_file_disp();      
        test_rgb_file_disp();  

    
    }
