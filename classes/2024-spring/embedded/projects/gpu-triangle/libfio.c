#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_io {
    char* name; // heap allocated
    FILE* fptr;
    int size;
    void* data;
    int offset;
} fio;

fio* create_fio(char* file_name, char *mode, int debug);

fio* create_fio(char* file_name, char *mode, int debug)
{
    if (debug) printf("Creating data structure for %s\n", file_name);

    fio* file = (fio *) calloc(1, sizeof(fio));

    file->fptr = fopen(file_name, mode);

    if (file->fptr == NULL)
    {
        if (debug) printf("libfio: error opening file %s\n", file_name);
        return NULL;
    }
    
    file->name = calloc(1, 256);
    strcpy(file->name, file_name);

    fseek(file->fptr, 0, SEEK_END);
    file->size = ftell(file->fptr);
    fseek(file->fptr, 0, SEEK_SET);

    if (debug) printf("File size: %d bytes\n", file->size);

    file->data = malloc(file->size);
    int read_size = fread(file->data, 1, file->size, file->fptr);

    if (debug) printf("Read %d bytes from %s\n", read_size, file->name);

    file->offset = 0;

    return file;
}