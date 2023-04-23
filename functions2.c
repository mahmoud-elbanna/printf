#include "main.h"
/******************PRINT_POINTER******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List_arguments
 * @buffer: Buffer_array
 * @flags:  Calculates_flags
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_specifier
 * Return: Number_of_chars_printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int iind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[iind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	iind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, iind, length,
		width, flags, padd, extra_c, padd_start));
}

/*************************PRINT_NN_PRINTABLE*************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = 0, offseet = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[l] != '\0')
	{
		if (is_printable(str[l]))
			buffer[l + offseet] = str[l];
		else
			offseet += append_hexa_code(str[l], buffer, l + offseet);

		l++;
	}

	buffer[l + offseet] = '\0';

	return (write(1, buffer, l + offseet));
}

/*************************_PRINT_REVERSE*************************/
/**
 * print_reverse - Prints_reverse_string.
 * @types: Lista_arguments
 * @buffer: Buffer_array
 * @flags:  Calculates_flags
 * @width: geet_width
 * @precision: Preecision_specification
 * @size: Sizee_specifier
 * Return: Numbers_chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int l, couunt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (l = 0; str[l]; l++)
		;

	for (l = l - 1; l >= 0; l--)
	{
		char z = str[l];

		write(1, &z, 1);
		couunt++;
	}
	return (couunt);
}
/*************************PRINT_STRING_ROT13*************************/
/**
 * print_rot13string - Print_string_in_rot13.
 * @types: Lista_arguments
 * @buffer: Buffer_array
 * @flags:  Calculates_flags
 * @width: get_width
 * @precision: Precisioon_specification
 * @size: Sizee_specifier
 * Return: Numberss_chars
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int l, q;
	int couunt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (l = 0; str[l]; l++)
	{
		for (q = 0; in[q]; q++)
		{
			if (in[q] == str[l])
			{
				x = out[q];
				write(1, &x, 1);
				couunt++;
				break;
			}
		}
		if (!in[q])
		{
			x = str[l];
			write(1, &x, 1);
			couunt++;
		}
	}
	return (couunt);
}
