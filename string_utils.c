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

/**
 * m_putchar - a function that writes one character
 * @c : the character
 * Return: the number of characters wroten
 **/
int m_putchar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}

/**
 * m_puts - a function that write a string
 * @string : the string we want to write
 * Return: the number of chars wrotten.
 **/
int m_puts(char *string)
{
	int i = 0, count = 0;

	while (string[i])
	{
		count = count + m_putchar(string[i]);
		i++;
	}
	return (count);
}

/**
 * m_getline - a custom getline function
 * will fill the string paramter
 * @string: the string we want to fill.
 **/
void m_getline(char *string)
{
	char character;
	int reader = 0, i = 0;

	while (character != '\n' && character != EOF)
	{
		reader = read(STDIN_FILENO, &character, 1);
		if (reader == 0)
		{
			break;
		}

		string[i] = character;
		i++;
	}
	string[i] = '\0';
}
