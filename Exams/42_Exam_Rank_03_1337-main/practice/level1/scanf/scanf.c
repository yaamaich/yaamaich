#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

int match_space(FILE *f)
{
	int c = fgetc(f);
	while (c != EOF && isspace(c))
		c = fgetc(f);
	if (c == EOF)
		return -1;
	if (c != EOF)
		ungetc(c, f);
	return 0;
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
	if (c == EOF)
		return -1;
	char *ptr = va_arg(ap, char*);
	*ptr = c; 
	return 1;
}
int scan_int(FILE *f, va_list ap)
{
	int c = fgetc(f);
	int r = 0;
	int sin = 1;
	int progress = 0;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sin *= -1;
		ungetc(c, f);
	}
	while (c != EOF && isdigit(c))
	{
		r  = r * 10 + (c - '0');
		progress++;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (progress == 0)
		return -1;
	int *ptr = va_arg(ap, int*);
	*ptr = r * sin;
	return 1;
}
int scan_str(FILE *f, va_list ap)
{
	int c = fgetc(f);
	int progress = 0;
	char *ptr = va_arg(ap, char*);
	while (c != EOF && !isspace(c))
	{
		ptr[progress] = c;
		c = fgetc(f);
		progress++;
	}
	if (progress == 0)
		return -1;
	if (c != EOF)
		ungetc(c, f);
	ptr[progress] = '\0';
	return 1;
}
int match_form(FILE *f, char format, va_list ap)
{
	switch (format)
	{
		case 'c':
			return scan_char(f, ap);
		case 's':
			return scan_str(f, ap);
		case 'd':
			return scan_int(f, ap);
		default:
			return -1;
	}
}
int ft_vscanf(FILE *f, const char *format, va_list ap)
{
	int ret;
	int progress = 0;
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			ret = match_form(f, *format, ap);
			if (ret == -1)
				return (progress == 0) ? -1 : progress;
			else if (progress == 0)
				return -1;
			else
				progress++;
		}else if (isspace(*format))
		{
			ret = match_space(f);
			if (ret == -1)
				return (progress == 0) ? -1 : progress;
			else if (ret == 0)
				return -1;
		}else 
		{
			ret = match_char(f, *format);
			if (ret == -1)
				return (progress == 0) ? -1 : progress;
		}
		format++;
	}
	if (ferror(f))
		return  -1;
	return progress;
}
int ft_scanf(const char *format, ...)
{
	va_list(ap);
	va_start(ap, format);
	int ret = ft_vscanf(stdin, format, ap);
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