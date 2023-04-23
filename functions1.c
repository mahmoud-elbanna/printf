#include "main.h"
/*************************PRINTUNSIGNEDNUMBER*************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[l--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[l--] = (num % 10) + '0';
		num /= 10;
	}

	l++;

	return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}
/*************PRINTUNSIGNE_NUMBERIN_OCTAL****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista_of_arguments
 * @buffer: Buffer_arraay
 * @flags:  Calculatees_activee
 * @width: get_wiidth
 * @precision: Precisioon_specification
 * @size: Size_specifier
 * Return: Number_of_chaars_printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int l = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[l--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[l--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[l--] = '0';

	l++;

	return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}

/**************PRINT_UNSIGNED_NUMBER_IN_HEXADECIMAL**************/
/**
 * print_hexadecimal - Prints_an_unsigned_number_ hexadecimal
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chaars
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*************PRINT_UNSIGNED_NUMBER_IN_UPPER_HEXADECIMAL**************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista_arguments
 * @buffer: Buffer_array
 * @flags:  Calculates_active_flags
 * @width: get_width
 * @precision: Precision_specification
 * @size: Size_specifier
 * Return: Number_of_chars_printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[l--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[l--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[l--] = flag_ch;
		buffer[l--] = '0';
	}

	l++;

	return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}
