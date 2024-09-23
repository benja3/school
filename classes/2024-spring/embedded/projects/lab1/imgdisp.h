#define RED_OFFSET_16BIT 11
#define GREEN_OFFSET_16BIT 5
#define BLUE_OFFSET_16BIT 0

#define RED_SIZE_16BIT 5
#define GREEN_SIZE_16BIT 6
#define BLUE_SIZE_16BIT 5

uint16_t cp_msbits_to_buffer(uint8_t filepix, uint16_t disppix, int num_bits, int offset);
