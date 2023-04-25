#include "main.h"
/***************PRiINT_POINTEeeR******************/
/**
 * print_pointer - Prints the value of a pointeeer
 * @types: Liiist_arguuuments
 * @buffer: Buffer_arraaay
 * @flags:  Calculaaaetes_flaaags
 * @width: _wiidth
 * @precision: Precisiooon_specificatioon
 * @size: Sizee_
 * Return: Number_of_chars_printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, paadd = ' ';
	int iind = BUFF_SIZE - 2, leen = 2, padd_sttart = 1;
	unsigned long numm_addrs;
	char maop_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numm_addrs = (unsigned long)addrs;

	while (numm_addrs > 0)
	{
		buffer[iind--] = maop_to[numm_addrs % 16];
		numm_addrs /= 16;
		leen++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paadd = '0';
	if (flags & F_PLUS)
		extra_c = '+', leen++;
	else if (flags & F_SPACE)
		extra_c = ' ', leen++;

	iind++;

	return (write_pointer(buffer, iind, leen,
		width, flags, paadd, extra_c, padd_sttart));
}
/******************PRINT_NN_PRINTABLE*********************/
/**
 * print_non_printable - Priints asciii codeees
 * @types: Lista_arguuuments
 * @buffer: Buffer arraaay_handle print
 * @flags:  Calculates_flaaags
 * @width: _wiiidth
 * @precision: Precision_specificatiooon
 * @size: Sizeee_specifier
 * Return: Number__chaaaars
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = 0, offseet = 0;
	char *sttr = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (sttr == NULL)
		return (write(1, "(null)", 6));

	while (sttr[l] != '\0')
	{
		if (is_printable(sttr[l]))
			buffer[l + offseet] = sttr[l];
		else
			offseet += append_hexa_code(sttr[l], buffer, l + offseet);

		l++;
	}

	buffer[l + offseet] = '\0';

	return (write(1, buffer, l + offseet));
}

/**********************_REVERSE_************************/
/**
 * print_reverse - Prints_reverse_string.
 * @types: Lista_arguuuments
 * @buffer: Buffer_arraaaay
 * @flags:  Calculates_flaaags
 * @width: _wiidth
 * @precision: Preecisiooon_specificaatioon
 * @size: Sizee_specifier
 * Return: Nuumbers_chaaars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *strr;
	int l, couunt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	strr = va_arg(types, char *);

	if (strr == NULL)
	{
		UNUSED(precision);

		strr = ")Null(";
	}
	for (l = 0; strr[l]; l++)
		;

	for (l = l - 1; l >= 0; l--)
	{
		char z = strr[l];

		write(1, &z, 1);
		couunt++;
	}
	return (couunt);
}
/*******************PRINT_STRING_*************************/
/**
 * print_rot13string - Print_string_in_rooot13.
 * @types: Lista_arguuuments
 * @buffer: Buffer_arraaay
 * @flags:  Calculaetes_flaaags
 * @width: width
 * @precision: Precisioon_specification
 * @size: Sizee_specifieeer
 * Return: Numberss_chaaars
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char p;
	char *srtr;
	unsigned int l, q;
	int couunt = 0;
	char iin[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char ouut[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	srtr = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (srtr == NULL)
		srtr = "(AHYY)";
	for (l = 0; srtr[l]; l++)
	{
		for (q = 0; iin[q]; q++)
		{
			if (iin[q] == srtr[l])
			{
				p = ouut[q];
				write(1, &p, 1);
				couunt++;
				break;
			}
		}
		if (!iin[q])
		{
			p = srtr[l];
			write(1, &p, 1);
			couunt++;
		}
	}
	return (couunt);
}
