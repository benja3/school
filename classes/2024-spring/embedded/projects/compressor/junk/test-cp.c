#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// copy size bits from src to dst starting at offset in dst buffer
unsigned int cp_to_buf(unsigned int src, unsigned int dst, unsigned int src_offset, unsigned int dst_offset, unsigned int size)
{
    src = src >> src_offset;
    src &= (1 << size) - 1; // clear bits outside of range

    unsigned int mask = src << dst_offset;

    return dst | mask;
}

unsigned int bit_at_offset(unsigned int read_buf, int offset)
{
	unsigned int bit = read_buf << offset;

	unsigned int mask = 0x1;
	bit &= mask; // clear all accept last bit

	return bit;
}

int main()
{
  assert(cp_to_buf(0b111100001010, 0, 8, 0, 4) == 0b1111);

  printf("%d\n", bit_at_offset(0b101010, 5));
  printf("%d\n", bit_at_offset(0b101010, 4));
  assert(bit_at_offset(0b101010, 5) == 1);
  assert(bit_at_offset(0b101010, 4) == 0);

}
