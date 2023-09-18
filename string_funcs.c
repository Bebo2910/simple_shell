#include "shell.h"
/**
 * _strlen - returns the length of string
 * @s:pointer to string
 * Return:number of characters in the string 
 */

int _strlen(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		i++;
	}

	return (i);
}
/**
 * _strcmp - compare two strings
 * @s1:pointer to first string
 * @s2:pointer to second string
 * Description: this function compares characters 
 * of two strings
 * Return: the difference between the first mismatching
 * pair of characters or 0 if equal
 */

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
/**
 * _strcpy_c - copies the string pointed by src to the 
 * buffer pointed by input
 * @input: pointer to the destination string
 * @src:pointer to the source string
 * Return: pointer to the destination string input
 */
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
/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: 1 on success and -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - writes a string to stdout
 * @s: the string to print
 * Return: 0 on success
 */
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
