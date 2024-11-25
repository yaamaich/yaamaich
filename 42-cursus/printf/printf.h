#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_putnbr(long n, int base , char type);
int ft_putunsnbr(unsigned int n);
int	ft_putptr(void *s);
int ft_putchar (char c);
int ft_putstr(char *str, int fd);
int	ft_printf(const char *format, ...);

#endif
