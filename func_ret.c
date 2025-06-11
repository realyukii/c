#include <stdio.h>

/*
* when the string literal is returned,
* it is stored on the static storage (ro/rw segment?), not on the stack.
*
* C11 §6.4.5: “It is unspecified whether these arrays are distinct provided
* their elements have the appropriate values. … If the program attempts
* to modify such an array, the behavior is undefined.”
*
* C99 §6.4.5: “… String literals are not modifiable. …
* The type of a string literal is “array of n const char”.”
*/
static const char *translate_method(int m)
{
	switch (m) {
	case 1: return "GET";
	case 2: return "POST";
	case 3: return "PUT";
	case 4: return "DELETE";
	case 5: return "HEAD";
	case 6: return "OPTIONS";
	case 7: return "PATCH";
	case 8: return "TRACE";
	case 9: return "CONNECT";
	default: return "UNKNOWN";
	}
}

int main(void)
{
	const char *c = translate_method(1);
	printf("address %p point to %s\n", c, c);

	return 0;
}