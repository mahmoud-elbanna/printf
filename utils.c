#include "main.h"
/**
* is_printable - Evaluuates_if_char_is_printable
* @x: Chaaar evaluated.
* Return: 1 if x is printable and 0 otherwise
*/
int is_printable(char x)
{
if (x >= 32 && x < 127)
return (1);
return (0);
}
/**
* append_hexa_code - Append_ascciii_hexadecimal
* @buffer: Arraaay_chars.
* @i: Indeex.
* @ascii_code: ASSCI CODE.
* Return: Always 3
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}
/**
* is_digit - Verifies_digit
* @p: Char_evaluateeed
* Return: 1 if p is a digit and 0 otherwise
*/
int is_digit(char p)
{
if (p >= '0' && p <= '9')
return (1);
return (0);
}
/**
* convert_size_number - Casts_a_number_size
* @num: Number_casteeed.
* @size: Number_indicating_casted.
* Return: Casted_value_num
*/
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}
/**
* convert_size_unsgnd - Casts_number_to_specified size
* @num: Numbeer_casted
* @size: Numbeer_indicating_casted
* Return: Casted_value
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
