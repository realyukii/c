/*
* compile and examine it on GDB to see the difference.
* https://stackoverflow.com/questions/3047530/flexible-array-member-in-c-structure
*/
struct arr {
	int item;
	char flex_array[];
};

struct arr2nd {
	int item;
	char *arr;
};

int main(void)
{
	__attribute__((__unused__))
	struct arr2nd a;
	__attribute__((__unused__))
	struct arr b;

	return 0;
}