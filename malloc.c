#include <stdio.h>
#include <string.h>
#include "shared_lib.h"

void init_str(void);

int main(void)
{
	init_str();
	while (1) {
		printf("Type something: ");
		fflush(stdout);
		if (fgets(str, 1024, stdin) == 0) {
			puts("\nExiting...");
			break;
		}
		printf("You type: %s", str);
	}
	
	return 0;
}