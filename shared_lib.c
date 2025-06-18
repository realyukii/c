#include <stdlib.h>

char *str = NULL;

void init_str(void)
{
	// type in the terminal: getconf PAGESIZE
	str = malloc(1024 * 134);
	/*
	* print the pointer address returned by malloc
	* and locate where it resides by gdb's info proc mapping
	*/
	asm volatile("int3");
}
