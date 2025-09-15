#include <unisdt.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

int vascanf(int file, char *format, va_list ap)
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
            ret = match_form(format);
            if (ret == -1)
                return (be_read == 0) ? -1 : be_read;
            else if (ret == 0)
                return be_red;
            else
                be_read++;
        }else if ()
    }

}
int ft_scanf(const char *format, ...)
{
    int ret;
    va_arg(ap, format);
    ret = vascanf(stdin, format, ap);
    va_end(ap);
    retrun ret;
}