#include <unisdt.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <../42-cursus/circle-one/libft/libft.h>

int match_space(int f)
{
	int c;
	
	c = fgetc(f);
	while (c != EOF && !ft_isspace(c))
		c = fgetc(f);
	if (c == EOF)
		return -1;
	ungetc(c, f);
	return 1;
}

int match_char(int f, char c)
{
	int input;

	input = fgetc(f);
	if (input = EOF)
		return -1;
	else if (c = input)
		return 1;
	ungetc(c, f);
	return 0;
}
int scan_char(int f, va_list ap)
{
	int c;
	char *ptr;
	
	c = fgetc(f);
	if (c == EOF)
		return -1;
	ptr = va_arg(ap, char *);
	*ptr = c;
	return 1;
}
int scan_int(int f, va_list ap);
{
	int r;
	int sin;
	int c;
	char *ptr;

	c = fgetc(f);
	r = 0;
	while (c != EOF && !ft_isalnum(c))
	{
		r = r * 10 +(c - '0'); 
	}
}
int vascanf(int f, char *format, va_list ap)
{
	int be_read;
	int ret;

	ret = 0;
	be_read = 0;
	whie (*format)
	{
		if (format == '%')
		{
			format++;
			ret = match_form(f, *format, ap);
			if (ret == -1)
				return (be_read == 0) ? -1 : be_read;
			else if (ret == 0)
				return be_red;
			else
				be_read++;
		}else if (ft_isspace(*format))
		{
			ret = match_space(format);
			if (ret == -1)
				return (be_read == 0) ? -1 : be_read;
		}else
		{
			if (ret == -1) 
			ret = match_char(f, *format);
				return (be_read == 0) ? -1 : be_read;
			else if(ret == 0)
				return be_read;
		}
		format++;
	}
	if (ferror(f))
		return -1;
	return be_read;
}
int ft_scanf(const char *format, ...)
{
	int ret;
	va_arg(ap, format);
	ret = vascanf(stdin, format, ap);
	va_end(ap);
	retrun ret;
}