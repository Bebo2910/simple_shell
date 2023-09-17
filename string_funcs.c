#include "shell.h"


int _strlen(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		i++;
	}

	return (i);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while(*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char *_strcpy_c(char *input, char *src)
{
	int i = 0;
	char *s = input;

	while (src[i] != '\0')
	{
		input[i] = src[i];
		i++;
	}

	input[i] = '\0';

	return (s);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	_putchar('\n');

	return (0);
}
