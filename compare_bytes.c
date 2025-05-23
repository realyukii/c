#include <string.h>
#include <stdio.h>

int main(void)
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
end:
	if (valid)
		printf("%s is a valid HTTP method\n", buf);
	else
		printf("%s is not a valid HTTP method\n", buf);

	return 0;
}