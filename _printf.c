#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printff function
 * @format: formaaat.
 * Return: Printed chaars.
 */
int _printf(const char *format, ...)
{
	int l, printeed = 0, printeed_chars = 0;
	int flaags, wid, pre, sz, buuff_ind = 0;
	va_list lst;
	char buuffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (l = 0; format && format[l] != '\0'; l++)
	{
		if (format[l] != '%')
		{
			buuffer[buuff_ind++] = format[l];
			if (buuff_ind == BUFF_SIZE)
				print_buffer(buuffer, &buuff_ind);
			printeed_chars++;
		}
		else
		{
			print_buffer(buuffer, &buuff_ind);
			flaags = get_flags(format, &l);
			wid = get_width(format, &l, lst);
			pre = get_precision(format, &l, lst);
			sz = get_size(format, &l);
			++l;
			printeed = handle_print(format, &l, lst, buuffer,
				flaags, wid, pre, sz);
			if (printeed == -1)
				return (-1);
			printeed_chars += printeed;
		}
	}

	print_buffer(buuffer, &buuff_ind);

	va_end(lst);

	return (printeed_chars);
}
/**
 * print_buffer - function that produces output
 * @buffer: Arraay
 * @buff_ind: Indeex
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
