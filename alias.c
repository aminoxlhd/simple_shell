#include "main.h"

void manage_aliases(void);
{

/**
*struct Alias - Represents an alias name-value pair.
*@name: The name of the alias.
*@value: The value of the alias.
*Description: This structure represents an alias, which consists of
*a name and its corresponding value.
*/

Alias aliases[100];
int alias_count = 0;

/**
*add_alias - Add a new alias to the aliases array.
*@name: The name of the alias.
*@value: The value of the alias.
*
*Description: This function adds a new alias with the specified name
*and value to the 'aliases' array.
*/

void add_alias(const char *name, const char *value)
{

	if (alias_count < 100)
	{
		strcpy(aliases[alias_count].name, name);
		strcpy(aliases[alias_count].value, value);
		alias_count++;
	} else
	{
		fprintf(stderr, "Error: Maximum number of aliases reached\n");
	}
}
/**
*print_aliases - Print all defined aliases.
*
*Description: This function prints all the defined aliases in the format:
*name='value'
*/

void print_aliases(void)
{
	if (alias_count == 0)
	{
		printf("No aliases defined\n");

		return;
	}

	for (int i = 0; i < alias_count; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
*remove_alias - Remove an alias from the aliases array.
*@name: The name of the alias to be removed.
*
*Description: This function removes the alias with the specified name
*from the 'aliases' array.
*/
void remove_alias(const char *name)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			for (int j = i; j < alias_count - 1; j++)
			{
				strcpy(aliases[j].name, aliases[j + 1].name);
				strcpy(aliases[j].value, aliases[j + 1].value);
			}
			alias_count--;
			printf("Alias '%s' removed\n", name);
			return;
		}
	}
	printf("Alias '%s' not found\n", name);
}
}

