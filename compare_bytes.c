#include <string.h>
#include <stdio.h>

/* so many pointer pointer to pointer of pointer, i love pointer :v */
void manual_cmp(void)
{
	const char buf[] = "HEAD";
	const char *methods[] = {"GET", "POST", "HEAD", "PATCH", "PUT", "DELETE", "OPTIONS", "CONNECT", "TRACE", NULL};
	char valid = 0;
	const char **ptr = methods;
	while (*ptr)
	{
		const char *method = *ptr;
		const char *first_bytes = buf;
		while (*method)
		{
			if (*first_bytes != *method)
				valid = 0;
			else
				valid = 1;
			first_bytes++;
			method++;
		}
		if (valid)
			break;
		ptr++;
	}

	if (valid)
		printf("%s is a valid HTTP method\n", buf);
	else
		printf("%s is not a valid HTTP method\n", buf);
}

void libc_cmp(void)
{
	char test1[] = "GET / HTTP/1.1\r\nHost: google.com\r\nUser-Agent: curl/8.13.0\r\nAccept: */*\r\n\r\n";
	char test2[] = "\r\n\r\n";
	for (size_t i = 0; i < strlen(test1); i++) {
		int result = strcmp(&test1[i], test2);
		if (result == 0) {
			printf("reached end of HTTP header\n");
		}
		
	}
}

int main(void)
{
	manual_cmp();
	libc_cmp();

	return 0;
}