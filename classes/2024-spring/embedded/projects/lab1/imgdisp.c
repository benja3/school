#include <stdlib.h>
#include <stdint.h>

#include "imgdisp.h"

// This function will take the most significant num_bits bits from filepix
// and copy them to disppix with the least significant copied bit being at
// position offset

uint16_t cp_msbits_to_buffer(uint8_t filepix, uint16_t disppix, int num_bits, int offset)
{
    // set up bit mask
    uint16_t mask = filepix >> (8 - num_bits);
    mask = mask << (offset);

    // set bits in disppix
    disppix |= mask;

    return disppix;

}


