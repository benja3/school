./compressor compress huffman $1 $1.h > test-input/huffman/compress.log
./compressor decompress huffman $1.h $1.d > test-input/huffman/decompress.log
cmp $1 $1.d
# diff $1 $1.d
# diff test-input/lzw/compress.log test-input/lzw/decompress.log
