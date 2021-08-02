#if defined(__linux__)
#define convert_linux false
#endif

struct stream {
	int size;
	int mat[];};

struct vfstream {
	int size;
	struct stream stm;
};

void convert(struct vfstream *stream, char *type[]);

