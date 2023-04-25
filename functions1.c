#include "main.h"
/*******************UNSIGNeeED_NuuUMBER************************/
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
/*************PRINTUNSIGNeeE__OCTaAL*************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista_of_arguments
 * @buffer: Buffer_arraay
 * @flags:  Calculatees_activee
 * @width: get_wiidth
 * @precision: Precisioon
 * @size: Sizeee
 * Return: Number_of_chaars
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
 * @types: Lista_arguuuments
 * @buffer: Buffeer_arraaay
 * @flags:  Calculates flags
 * @width: wiidth
 * @precision: Precision_speeecification
 * @size: Sizee
 * Return: Number of chaars
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*************PRINT_UNSIGNeeED_NUMBeeER_IN_UPPER_HEXA***********/
/**
 * print_hexa_upper - Prints_unsigneeed_number
 * @types: Lista_arguments
 * @buffer: Buffer_arraaay
 * @flags:  Calculates_active_flaaags
 * @width: _wiidth
 * @precision: Precisioon_specification
 * @size: Size_specifieeer
 * Return: Numbeer_of_chaaars
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**************print_hex_num***********/
/**
 * print_hexa - Prints_hexadecimal
 * @types: Lista_arguuuuments
 * @map_to: Arraaay_valuuue
 * @buffer: Buffeer_arraay
 * @flags:  Calculaaates_activee_flaags
 * @flag_ch: Calculates_flags
 * @width: wiiidth
 * @precision: Precision_specificatioooon
 * @size: Size specifieeer
 * @size: Size specificatioon
 * Return: Number_chaaar
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int nuum = va_arg(types, unsigned long int);
	unsigned long int init_num = nuum;

	UNUSED(width);

	nuum = convert_size_unsgnd(nuum, size);

	if (nuum == 0)
		buffer[l--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nuum > 0)
	{
		buffer[l--] = map_to[nuum % 16];
		nuum /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[l--] = flag_ch;
		buffer[l--] = '0';
	}

	l++;

	return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}
