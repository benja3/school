typedef struct file_io {
    char* name; // heap allocated
    FILE* fptr;
    int size;
    void* data;
} fio;

fio* create_fio(char* file_name, int debug);