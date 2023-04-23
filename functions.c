#include "main.h"
/*************************PRIINT CHAR*************************/

/**
 * print_char - Prints_a_char
 * @types: List_arguments
 * @buffer: Buffer_array_to_handle_print
 * @flags:  Calculates_active_flags
 * @width: Wiidth
 * @precision: Precision_specification
 * @size: Size_specifier
 * Return: Number_chars_printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char cc = va_arg(types, int);

	return (handle_write_char(cc, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List_a_of_arguments
 * @buffer: Buffeer_arrray_too_handle_print
 * @flags:  Calculates activee flaaags
 * @width: get_wiidth.
 * @precision: Precision_specification
 * @size: Siize_specifier
 * Return: Number_of_chars_printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, l;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (l = width - length; l > 0; l--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints_percent_sign
 * @types: Lista_of_arguments
 * @buffer: Buuffer_arrray_to_haandle print
 * @flags:  Calculatees_flaaags
 * @width: get_widtth.
 * @precision: Precisioon_specification
 * @size: Size_specifier
 * Return: Numbeer_of_chaars_printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print_int
 * @types: Lista_of_arguments
 * @buffer: Buffer_arraay_to_handle print
 * @flags:  Calculates_active_flags
 * @width: get_width.
 * @precision: Precision_specification
 * @size: Size_specifier
 * Return: Number_of_chaars_printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	int is_negativee = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[l--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negativee = 1;
	}

	while (num > 0)
	{
		buffer[l--] = (num % 10) + '0';
		num /= 10;
	}

	l++;

	return (write_number(is_negativee, l, buffer, flags, width, precision, size));
}

/*************************PRINT_BINARY*************************/
/**
 * print_binary - Prints_an_unsigned_number
 * @types: Listaa_arguments
 * @buffer: Buffer_array
 * @flags:  Calculates_activee_flaags
 * @width: get_wiidth.
 * @precision: Precisionn_specification
 * @size: Sizee_specifier
 * Return: Numbeers_of_char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int q, w, e, suum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	q = va_arg(types, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	a[0] = q / w;
	for (e = 1; e < 32; e++)
	{
		w /= 2;
		a[e] = (q / w) % 2;
	}
	for (e = 0, suum = 0, count = 0; e < 32; e++)
	{
		suum += a[e];
		if (sum || e == 31)
		{
			char z = '0' + a[e];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
