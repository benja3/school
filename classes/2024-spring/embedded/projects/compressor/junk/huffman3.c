#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
typedef struct Meta_data
{
	char *file_name;
	int size, ele_size;
	FILE *fpt;
	void *data;
}meta_data;
int get_file_size(char *filename)
{
	struct stat file_status;
	if (stat(filename, &file_status) < 0) return -1;
	return file_status.st_size;
}
void read_data(meta_data *meta_d)
{
	meta_d->data = (void*)malloc(meta_d->size*meta_d->ele_size);
	meta_d->fpt = fopen(meta_d->file_name, "r");
	fread(meta_d->data, meta_d->ele_size, meta_d->size/meta_d->ele_size, meta_d->fpt);
	fclose(meta_d->fpt);
}
void write_data(meta_data *meta_d)
{
	meta_d->fpt = fopen(meta_d->file_name, "w");
	fwrite(meta_d->data, meta_d->ele_size, meta_d->size, meta_d->fpt);
	fclose(meta_d->fpt);
}
typedef struct Node
{
	char data;
	unsigned int freq;
	struct Node *left, *right;
}node;
typedef struct Min_heap
{
	unsigned int size, capcity, height;
	node **arr;
}min_heap;
typedef struct Data_codes
{
	unsigned int *code_length;
	unsigned int stride;
	unsigned char *codes;
}data_codes;
void print_arr(unsigned int *arr, int n)
{
	for(int i=0;i<n;i++) printf("%d", arr[i]);
	printf("\n");
}
node *create_node(unsigned char data, int freq)
{
	node *_node = (node*)malloc(sizeof(node));
	_node->data = data;
	_node->freq = freq;
	_node->left = _node->right = NULL;
	return _node;
}
void swap(node **a, node **b)
{
	node *t = *a;
	*a = *b;
	*b = t;
}
void shift_down(min_heap *m_heap, int idx)
{
	int l,r,s=idx;
	do {
		idx = s; l = 2*idx+1; r = l+1;
		if(l<m_heap->size && m_heap->arr[l]->freq < m_heap->arr[s]->freq) s = l;
		if(r<m_heap->size && m_heap->arr[r]->freq < m_heap->arr[s]->freq) s = r;
		if(s!=idx) swap(&(m_heap->arr[s]), &(m_heap->arr[idx]));
	} while (s != idx);
}
unsigned int* create_freq_table(unsigned char *data, int n)
{
	int i, table_size = 0;
	unsigned int *freq_table = (unsigned int*)calloc(256, sizeof(unsigned int));
	for(i=0;i<n;i++) freq_table[data[i]]++;
	return freq_table;
}
min_heap* create_min_q(unsigned int *freq_table)
{
	int i, table_size = 0;
	for(i=0;i<256;i++) if(freq_table[i])table_size++;
	min_heap *m_heap = (min_heap*)calloc(sizeof(min_heap), 1);
	m_heap->capcity = table_size;
	m_heap->arr = (node**)malloc(sizeof(node*)*m_heap->capcity);
	for(i=0;i<256;i++) if(freq_table[i]) m_heap->arr[m_heap->size++] = create_node(i, freq_table[i]);
	for(int i=m_heap->size/2;i>=0;i--) shift_down(m_heap, i);
	return m_heap;
}
node *extract_min(min_heap *m_heap)
{
	swap(&(m_heap->arr[0]), &(m_heap->arr[--m_heap->size]));
	shift_down(m_heap, 0);
	return m_heap->arr[m_heap->size];
}
void insert_node(min_heap *m_heap, node *new_node)
{
	int i = m_heap->size++, p = (i-1)/2;
	while(i && new_node->freq < m_heap->arr[p]->freq)
	{
		m_heap->arr[i] = m_heap->arr[p];
		i = p;
		p = (i-1)/2;
	}
	m_heap->arr[i] = new_node;
}
node *huffman_tree(min_heap *m_heap)
{
	node *l, *r, *t;
	while(m_heap->size != 1)
	{
		l = extract_min(m_heap);
		r = extract_min(m_heap);
		t = create_node('$', l->freq+r->freq);
		t->left = l;
		t->right = r;
		insert_node(m_heap, t);
	}
	return m_heap->arr[0];
}
int tree_height(node *root)
{
	if(!root) return 0;
	int l = tree_height(root->left), r = tree_height(root->right);
	return 1 + (l>r?l:r);
}
void print_codes(node *root, unsigned int *arr, unsigned int idx)
{
	if(root)
	{
		if(root->left) {arr[idx] = 0; print_codes(root->left, arr, idx+1);}
		if(root->right) {arr[idx] = 1; print_codes(root->right, arr, idx+1);}
		if(!root->left && !root->right) {printf("%c [%d]: ", root->data, root->data); print_arr(arr, idx);}
	}
}
void write_code(data_codes *d_codes, unsigned int *arr, unsigned int n, unsigned char c)
{
	unsigned int i, idx = c*d_codes->stride;
	unsigned char data=0, s = sizeof(unsigned char)*8;
	for(i=0;i<n;i++)
	{
		data |= arr[i];
		if(!((i+1)%s)) 
		{
			d_codes->codes[idx+i/s] = data;
			data = 0;
		}
		else data <<= 1;
	}
	if(i%s) d_codes->codes[idx+i/s] = data<<(s-i%s-1);
	d_codes->code_length[c] = n;
}
void save_codes(node *root, unsigned int *arr, int idx, data_codes *d_codes)
{
	if(root)
	{
		if(root->left) {arr[idx] = 0; save_codes(root->left, arr, idx+1, d_codes);}
		if(root->right) {arr[idx] = 1; save_codes(root->right, arr, idx+1, d_codes);}
		if(!root->left && !root->right) write_code(d_codes, arr, idx, root->data);
	}
}
void print_bits(unsigned char *arr, unsigned int n)
{
	int i, s = sizeof(unsigned char)*8, m;
	unsigned char data=0, mask = 1, c=0;
	unsigned int elems = (n-1)/s+1, idx;
	for(idx=0;idx<elems;idx++)
	{
		data=arr[idx];
		m = idx==elems-1?n-idx*s:s;
		for(i=s-1;i>=s-m;i--)
		{
			c = (mask<<i) & data;
			c = c>>i;
			printf("%d", c);	
		}
	}
	printf("\n");
}
void print_data_codes(data_codes *d_codes)
{
	for(unsigned int i=0;i<256;i++)
	{
		if(d_codes->code_length[i])
		{
			printf("(%c): ", i);
			print_bits(&d_codes->codes[i*d_codes->stride], d_codes->code_length[i]);
		}
	}
}
data_codes* init_data_codes(min_heap *m_heap)
{
	data_codes *d_codes = (data_codes*)calloc(1, sizeof(data_codes));
	d_codes->stride = (m_heap->height-1)/(sizeof(unsigned char)*8)+1;
	d_codes->codes = (unsigned char*)calloc(256, sizeof(unsigned char)*d_codes->stride);
	d_codes->code_length = (unsigned int*)calloc(256, sizeof(unsigned int));
	unsigned int arr[m_heap->height];
	save_codes(m_heap->arr[0], arr, 0, d_codes);
	return d_codes;
}
int get_size(data_codes *d_code, unsigned char *data, int n)
{
	int size = 0;
	for(int i=0;i<n;i++) size += d_code->code_length[data[i]];
	return size;
}
unsigned char* encode_data(data_codes *d_codes, unsigned char *data, int n, int n_bits)
{
	int s = sizeof(unsigned char)*8, size = (n_bits-1)/s+1,
		i, m, j;
	unsigned char *arr, pack_data, code_data, c,
		*comp_data = (unsigned char*)calloc(size, sizeof(unsigned char)), mask = 1;
	unsigned int code_len, stride = d_codes->stride, curr_idx = 0, num_bits = 0, elems, idx, b;
	for(i=0;i<n;i++)
	{
		code_len = d_codes->code_length[data[i]];
		arr = &d_codes->codes[((int)data[i])*stride];
		elems = (code_len-1)/s+1;
		for(idx=0;idx<elems;idx++)
		{
			code_data = arr[idx];
			m = idx==elems-1?code_len-idx*s:s;
			for(j=s-1;j>=s-m;j--)
			{
				c = (mask<<j) & code_data;
				b = s-1-num_bits++;
				c = b>j?c<<(b-j):c>>(j-b);
				pack_data |= c;
				if(num_bits == s)
				{
					comp_data[curr_idx++] = pack_data;
					pack_data = 0;
					num_bits = 0;
				}
			}
		}
	}
	if(num_bits) comp_data[curr_idx++] = pack_data;
	return comp_data;
}
void* write_bytes(void *dest, void *src, int n)
{
	memcpy(dest, src, n);
	return dest+n;
}
void* read_bytes(void *dest, void *src, int n)
{
	memcpy(dest, src, n);
	return src+n;
}
void save_data(unsigned int *freq_table, unsigned char *data, int n, meta_data *out_data, int in_size, int n_bits)
{
	int i, count = 0;
	unsigned char c;
	size_t size;
	for(i=0;i<256;i++) if(freq_table[i])count++;
	size =  sizeof(unsigned char)*(count+n)+sizeof(int)*(count+3);
	const unsigned char* comp_data = (unsigned char*)malloc(size);
	unsigned char *t = (unsigned char*)comp_data;
	t = write_bytes(t, &count, sizeof(int));
	t = write_bytes(t, &in_size, sizeof(int));
	t = write_bytes(t, &n_bits, sizeof(int));
	for(i=0;i<256;i++)
	{
		c = (unsigned char)i;
		if(freq_table[i])
		{
			t = write_bytes(t, &c, sizeof(unsigned char));
			t = write_bytes(t, &freq_table[i], sizeof(unsigned int));
		}
	}
	t = write_bytes(t, data, sizeof(unsigned char)*n);
	out_data->data = (void*)comp_data;
	out_data->size = size;
	out_data->ele_size = sizeof(unsigned char);
	write_data(out_data);
	free((void*)comp_data);
}
void huffman_encoding(meta_data *in_data, meta_data *out_data)
{
	read_data(in_data);
	unsigned int *freq_table = create_freq_table(in_data->data, in_data->size);
	min_heap *m_heap = create_min_q(freq_table);
	node *h_tree = huffman_tree(m_heap);
	m_heap->height = tree_height(h_tree);
	data_codes *d_codes = init_data_codes(m_heap);
	int n_bits = get_size(d_codes, in_data->data, in_data->size), n = (n_bits-1)/(sizeof(unsigned char)*8)+1;
	unsigned char *data = encode_data(d_codes, in_data->data, in_data->size, n_bits);
	save_data(freq_table, data, n, out_data, in_data->size, n_bits);
	free(freq_table);
}
void decode_data(min_heap *m_heap, meta_data *out_data, unsigned char *data, int n_bits)
{
	int s = sizeof(unsigned char)*8, size = (n_bits-1)/s+1,
		i, m, curr_idx = 0, j;
	unsigned char code_data, c, mask = 1, 
		*decomp_data = (unsigned char*)calloc(out_data->size, sizeof(unsigned char));
	node *temp = m_heap->arr[0];
	for(i=0;i<size;i++)
	{
		code_data = data[i];
		m = i==size-1?n_bits-i*s:s;
		for(j=s-1;j>=s-m;j--)
		{
			c = (mask<<j) & code_data;
			c = c>>j;
			temp = c?temp->right:temp->left;
			if(!temp->left && !temp->right)
			{
				decomp_data[curr_idx++] = temp->data;
				temp = m_heap->arr[0];
			}
		}
	}
	if(temp != m_heap->arr[0]) exit(-1);
	out_data->data = decomp_data;
	out_data->ele_size = sizeof(unsigned char);
	write_data(out_data);
	free(decomp_data);
}
void huffman_decoding(meta_data *in_data, meta_data *out_data)
{
	read_data(in_data);
	unsigned char *data = in_data->data, c;
	int table_size, i, n_bits;
	data = read_bytes(&table_size, data, sizeof(int));
	data = read_bytes(&out_data->size, data, sizeof(int));
	data = read_bytes(&n_bits, data, sizeof(int));
	unsigned int *freq_table = (unsigned int*)calloc(256, sizeof(unsigned int));
	for(i=0;i<table_size;i++)
	{
		data = read_bytes(&c, data, sizeof(unsigned char));
		data = read_bytes(&freq_table[c], data, sizeof(unsigned int));
	}
	min_heap *m_heap = create_min_q(freq_table);
	node *h_tree = huffman_tree(m_heap);
	m_heap->height = tree_height(h_tree);
	decode_data(m_heap, out_data, data, n_bits);
}
int main(int argc, char **argv)
{
	meta_data in_data, out_data;
	int comp = 1;
	if(argc != 4)
	{
		printf("usage: %s input_file_name, compressed_file_name, 1(compress) or 0(decompress)\n", argv[0]);
		exit(0);
	}
	in_data.file_name = strdup(argv[1]);
	out_data.file_name = strdup(argv[2]);
	comp = argc == 4?atoi(argv[3]):1;
	in_data.size = get_file_size(in_data.file_name);
	in_data.ele_size = sizeof(unsigned char);
	if(comp) huffman_encoding(&in_data, &out_data);
	else huffman_decoding(&in_data, &out_data);
	printf("in data size: %d bytes\n", in_data.size);
	printf("out data size: %d bytes\n", out_data.size*out_data.ele_size);
	return 0;
}