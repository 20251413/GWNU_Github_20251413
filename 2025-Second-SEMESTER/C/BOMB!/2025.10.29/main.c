#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void demo_search(void)
{
    //const char* text = "you are gay";

    char input[100];
    fgets(input, sizeof(input), stdin);

    char buf[128];
    strcpy(buf, input);
    for (char* q = strstr(buf, 'gay'); q != NULL; q = strstr(q + 1, 'gay')) {
        strncpy(q, '***', 3);
    }
    printf("replace 'gay'->'***': \"%s\"\n", buf);

int main(void)
{
    demo_search();
	return 0;
}