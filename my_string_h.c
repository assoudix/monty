#include "monty.h"


/**
 * strtok_ - tokenizes string
 * @str: The string to be tokenized
 * @delim: delimeters (characters to be avoided)
 *
 * splits string into tokens and avoids delim characters
 *
 * Return: first token
 */

char *strtok_(char *str, const char *delim)
{
static char *nextToken = "\0";
char *tokenStart = NULL;
if (str != NULL)
{
nextToken = str;
}

if (nextToken == NULL || *nextToken == '\0')
{
return (NULL);
}

while (*nextToken != '\0' && strchr_(delim, *nextToken) != NULL)
{
nextToken++;
}

if (*nextToken == '\0')
{
return (NULL);
}

tokenStart = nextToken;

while (*nextToken != '\0' && strchr_(delim, *nextToken) == NULL)
{
nextToken++;
}

if (*nextToken != '\0')
{
*nextToken = '\0';
nextToken++;
}

return (tokenStart);
}


/**
 * strchr_ - find character in string
 * @str: The string to search
 * @c: The character to locate
 *
 * locates  first occurrence  the character @cin the string pointed to by @str
 *
 * Return: pointer to the c (NULL if failure)
 */

char *strchr_(const char *str, int c)
{
while (*str != '\0')
{
if (*str == c)
{
return ((char *)str);
}
str++;
}
return (NULL);
}

/**
 * strcmp_ - compare two strings
 * @str1: first string
 * @str2: second string
 *
 * compares the two strings @str1 and @str2
 *
 * Return: 0 if equal, non 0 if not equal
 */
int strcmp_(const char *str1, const char *str2)
{
while (*str1 != '\0' && *str2 != '\0')
{
if (*str1 != *str2)
{
return (*str1 - *str2);
}
str1++;
str2++;
}
return (*str1 - *str2);
}
