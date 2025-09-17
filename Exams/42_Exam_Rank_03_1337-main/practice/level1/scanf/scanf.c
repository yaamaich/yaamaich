#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

int ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return 1;
	return 0;
}
int match_space(FILE *f)
{
	int c;
	
	c = fgetc(f);
	while (c != EOF && ft_isspace(c))
		c = fgetc(f);
	if (c == EOF)
		return -1;
	ungetc(c, f);
	return 1;
}

int match_char(FILE *f, char c)
{
	int input;

	input = fgetc(f);
	if (input == EOF)
		return -1;
	else if (c == input)
		return 1;
	ungetc(c, f);
	return 0;
}
int scan_char(FILE *f, va_list ap)
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
int scan_int(FILE *f, va_list ap)
{
	int r;
	int be_read;
	int sin;
	int c;
	int *ptr;

	c = fgetc(f);
	r = 0;
	be_read = 0;
	while (c != EOF && isdigit(c))
	{
		r = r * 10 +(c - '0');
		be_read++;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (be_read == 0)
		return -1;
	ptr = va_arg(ap, int*);
	*ptr = r * sin;
	return 0;
}
int	scan_str(FILE *f, va_list ap)
{
	char *ptr;
	int be_read;
	int c;
	ptr = va_arg(ap, char*);
	be_read = 0;
	c = fgetc(f);
	while (c != EOF && !ft_isspace(c))
	{
		ptr[be_read] = c;
		be_read++;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (be_read == 0)
		return -1;
	ptr[be_read] = '\0';
	return 0;
}
int match_form(FILE *f, char format, va_list ap)
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
int vascanf(FILE *f, char *format, va_list ap)
{
	int be_read;
	int ret;

	ret = 0;
	be_read = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = match_form(f, *format, ap);
			if (ret == -1)
				return (be_read == 0) ? -1 : be_read;
			else if (ret == 0)
				return be_read;
			else
				be_read++;
		}else if (ft_isspace(*format))
		{
			ret = match_space(f);
			if (ret == -1)
				return (be_read == 0) ? -1 : be_read;
		}else
		{
			ret = match_char(f, *format);
			if (ret == -1) 
				return (be_read == 0) ? -1 : be_read;
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
	va_list ap;
	va_start(ap, format);
	ret = vascanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
int main()
{
	char *ptr;
	ptr = malloc (15 * sizeof(char));
	ft_scanf("name:%s", ptr);
	printf("that result:%s", ptr);
}