#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int match_space(FILE *f)
{
	int c = fgetc(f);
	while (c != EOF && isspace(c))
		c = fgetc(f);
	if (c == EOF)
		return -1;
	ungetc(c, f);
	return 1;
}
int match_char(FILE *f, char format)
{
	int c = fgetc(f);
	if (c == EOF)
		return -1;
	if (c == format)
		return 1;
	ungetc(c, f);
	return 0;
}
int scan_char(FILE *f, va_list ap)
{
	int c = fgetc(f);
	char *ptr = va_arg(ap, char*);
	if (c == EOF)
		return -1;
	*ptr = c;
	return 1;
}
int scan_str(FILE *f, va_list ap)
{
	int progres = 0;
	char *ptr = va_arg(ap, char*);
	int c = fgetc(f);
	while (c != EOF && !isspace(c))
	{
		ptr[progres] = c;
		progres++;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (progres == 0)
		return -1;
	ptr[progres] = '\0';
	return 1;
}
int scan_int(FILE *f, va_list ap)
{
	int c = fgetc(f);
	int ret;
	int r = 0;
	int sine = 1;
	int progres;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sine *= -1;
		fgetc(f);
	}
	while (c != EOF && isdigit(c))
	{
		r = r * 10 + (c - '0');
		c = fgetc(f);
		progres++;
	}
	if (c != EOF)
		ungetc(c, f);
	if (progres == 0)
		return -1; 
	int *ptr = va_arg(ap, int*);
	*ptr = r * sine;
	return 1;
}
int match_conv(FILE *f, char format, va_list ap)
{
	switch (format)
	{
		case 'c' :
			return scan_char(f, ap);
		case 's' :
			return scan_str(f, ap);
		case 'd' :
			return scan_int(f, ap);
		default:
			return -1;
	}
}
int ft_vscan(FILE *f, const char *format, va_list ap)
{
	int progres;
	int ret;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = match_conv(f, *format, ap);
			if (ret == -1)
				return (progres == 0) ? -1 : progres;
			else if (ret == 0)
				return progres;
			else
				progres++;
		}else if (isspace(*format))
		{
			ret = match_space(f);
			if (ret == -1)
				return (progres == 0) ? -1 : progres;
		}else
		{
			ret = match_char(f, *format);
			if (ret == -1)
				return (progres == 0) ? -1 : progres;
			else if (ret == 0)
				return progres;
		}
		format++;
	}
	if (ferror(f))
		return -1;
	return progres;
}
int ft_scanf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret = ft_vscan(stdin, format, ap);
	va_end(ap);
	return ret;
}
int main()
{
	char *ptr;
	ptr = malloc (15 * sizeof(char));
	ft_scanf("name:%s", ptr);
	printf("that result:%s", ptr);
	free(ptr);
}