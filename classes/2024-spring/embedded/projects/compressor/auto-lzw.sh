./compressor compress LZW $1 $1.lzw > test-input/lzw/compress.log
./compressor decompress LZW $1.lzw $1.d > test-input/lzw/decompress.log
cmp $1 $1.d
# diff $1 $1.d
# diff test-input/lzw/compress.log test-input/lzw/decompress.log