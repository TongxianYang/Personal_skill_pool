
#define _GNU_SOURCE
#include <dlfcn.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#if 0

int global = 0;

#define ENABLE_MEMLEAK 1


void *_malloc(size_t size, const char  *filename, int line) { // ++

#if ENABLE_MEMLEAK
	global++;  //atomic
#endif

	void *p = malloc(size);

	char buff[128] = {0};
	sprintf(buff, "./memleak/%p.mem", p);

	FILE *fp = fopen(buff, "w");
	fprintf(fp, "[+%s:%d]_malloc: %ld, ptr: %p\n", filename, line, size, p);
	fflush(fp);

	fclose(fp);

	
	return p;
}

void _free(void *p, const char  *filename, int line) { // --

	//printf("[-%s:%d]_free: %p\n", filename, line, p);
#if ENABLE_MEMLEAK
	global--;
#endif

	
    char buff[128] = {0};
    sprintf(buff, "./memleak/%p.mem", p);

	if (unlink(buff) < 0) { // 
		printf("double free: %p\n", p);
		return ;
	}

	free(p);
}

// __LINE__, __FILE__

#if ENABLE_MEMLEAK

#define malloc(size) _malloc(size, __FILE__, __LINE__)

#define free(ptr)   _free(ptr, __FILE__, __LINE__)

#endif



#else

// hook
// .c --> .cpp
typedef void *(*malloc_t)(size_t size);
malloc_t malloc_f = NULL;

typedef void (*free_t)(void *ptr);
free_t free_f = NULL;

int enable_malloc_hook = 1;

// dlsym --> 

// __builtin_return_address();
// a() --> b() --> c() --> __builtin_return_address()

void *malloc(size_t size) {

	void *p = NULL;
	if (enable_malloc_hook) {
		enable_malloc_hook = 0;
		
		void *caller = __builtin_return_address(0);

		printf("caller: %p\n", caller);
		p = malloc_f(size);

		enable_malloc_hook = 1;
	} else {
		p = malloc_f(size);
	}

	return p;

}


void free(void *p) {
	printf("free");
	
	return free_f(p);
}


static void init_hook(void) {

	if (malloc_f == NULL) {
		malloc_f = dlsym(RTLD_NEXT, "malloc");
	}

	if (free_f == NULL) {
		free_f = dlsym(RTLD_NEXT, "free");
	}

}

#endif

// dladdr

int main() {

	init_hook();

	void *p1 = malloc(5);   //_malloc(size, __FILE__, __LINE__)
	void *p2 = malloc(15);

	free(p1);

	//printf("p1: %p, p2: %p\n", p1, p2);
	//printf("global : %d\n", global);
 // -->
	//getchar();

	return 0;
}





