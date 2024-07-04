#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	 ft_print_comb2(void)
{
	int a = '0';
	int b;
	int c;
	int d = '1';
	while(a <= '9')
	{
		b = '0';
		while(b <= '8')
		{
			c = '0';
			while(c <= '9')
			{
				while(d <= '9')
				{
					ft_putchar(a);
					ft_putchar(b);
					ft_putchar(' ');
					ft_putchar(c);
					ft_putchar(d);
					if (a < '9' || b < '8')
					{
						ft_putchar(',');
						ft_putchar(' ');
					}
					d++;
				}
				d = '0';
				c = b + 1;
				c++;
			}
			b++;
		}
		a++;
	}	
}
int main()
{
	 ft_print_comb2();
	 return 0;
}
