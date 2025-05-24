#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    const char str[] = "GET / HTTP/1.1\r\nHost: google.com\r\nUser-Agent: curl/8.13.0\r\nAccept: */*\r\n\r\n";
    int str_len = strlen(str);
    char tmpstr[str_len];
    strcpy(tmpstr, str);
    const char keyword[] = "Host: ";
    const char *method = strtok(tmpstr, " ");
    const char *path = strtok(NULL, " ");

    char *http_host_hdr = strcasestr(str, keyword);
    strtok(http_host_hdr, "\r\n");
    printf("Method: %s\nPath: %s\n%s\n", method, path, http_host_hdr);

    return 0;
}