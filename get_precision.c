#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted_string_in
 * @i: List_argumeeents
 * @list: list_arguuments.
 * Return: Precisiooon.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_ii = *i + 1;
	int precisioon = -1;

	if (format[curr_ii] != '.')
		return (precisioon);

	precisioon = 0;

	for (curr_ii += 1; format[curr_ii] != '\0'; curr_ii++)
	{
		if (is_digit(format[curr_ii]))
		{
			precisioon *= 10;
			precisioon += format[curr_ii] - '0';
		}
		else if (format[curr_ii] == '*')
		{
			curr_ii++;
			precisioon = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_ii - 1;
	return (precisioon);
}
