#include "main.h"

/**
* get_flags - Calculates active flags
* @format: Formatted string in which to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int get_flags(const char *format, int *i)
{
int k, index;
int flags = 0;
const char FLAGS_CH[] = "-+0# ";
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (index = *i + 1; format[index] != '\0'; index++)
{
for (k = 0; FLAGS_CH[k] != '\0'; k++)
{
if (format[index] == FLAGS_CH[k])
{
flags |= FLAGS_ARR[k];
break;
}
}

if (FLAGS_CH[k] == '\0')
break;
}

*i = index - 1;
return (flags);
}
