#include <remiel/string.h>

int
strlen(char *str)
{
	int counter = 0;

	do
	{
		counter++;
	}
	while(*(str++));

	return counter;
}

void
strcpy(char *src, char *dst)
{
	for(int i = 0; i < strlen(src); i++)
	{
		*dst = *src;
		src++;
		dst++;
	}
}
