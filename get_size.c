#include "main.h"
/**
 * get_size - Calculates_the_size_cast_the_arguument
 * @format: Formatted_striing
 * @i: List_of_arguuuuments
 * Return: Precisiooon.
 */
int get_size(const char *format, int *i)
{
	int cuurr_i = *i + 1;
	int siize = 0;

	if (format[cuurr_i] == 'l')
		siize = S_LONG;
	else if (format[cuurr_i] == 'h')
		siize = S_SHORT;

	if (siize == 0)
		*i = cuurr_i - 1;
	else
		*i = cuurr_i;

	return (siize);
}
