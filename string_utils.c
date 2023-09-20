#include "main.h"

/**
* m_strtok - a function that will tokenize a string
* by a delimeter
* @string: the string we want to tokineze
* @delim: the delimeter we want to use.
* Return: a toknized string
**/
char *m_strtok(char *string, const char *delim)
{
	static char *temp_ptr;
	char *start;

	if (string != NULL)
		temp_ptr = string;

	if (temp_ptr == NULL)
		return (NULL);

	temp_ptr += strspn(temp_ptr, delim);

	if (*temp_ptr == '\0')
	{
		temp_ptr = NULL;
		return (temp_ptr);
	}
	else
	{
		start = temp_ptr;
		temp_ptr += strcspn(temp_ptr, delim);
		if (*temp_ptr == '\0')
		{
			temp_ptr = NULL;
		}
		else
		{
			*temp_ptr++ = '\0';
		}
		return (start);
	}
}
