#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int	g_var = 0;

void	ft_put_number(long digits, int length, char *sign)
{
	if (digits >= length)
		ft_put_number(digits / length, length, sign);
	write(1, &sign[digits % length], 1);
	g_var++;
}

void	ft_put_hexadecimal(unsigned digits, unsigned length, char *sign)
{
	if (digits >= length)
		ft_put_hexadecimal(digits / length, length, sign);
	write(1, &sign[digits % length], 1);
	g_var++;
}

int	ft_printf(const char *format, ...)
{
    int i = 0;
	int length = 0;
	g_var = 0;
	
	va_list ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				char *string = va_arg(ap, char *);
				if (!string)
					string = "(null)";
				while (string[length])
					length++;
				g_var += length;
				write(1, string, length);
			}
			else if (*format == 'd')
			{
				long long decimal = va_arg(ap, int);
				if (decimal < 0)
				{
					write(1, "-", 1);
					g_var++;
					decimal = -decimal;
				}
				ft_put_number(decimal, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				int hexadecimal = va_arg(ap, int);
				ft_put_hexadecimal(hexadecimal, 16, "0123456789abcdef");
			}
            else if(*format == '%')
                g_var += write(1, &format[i], 1);
			format++;
            i++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(ap);
	return (g_var);
}


int main()
{
    int c;
    int d;
    char *s = "toto";
    d = 2948090;
    c = ft_printf("ft_printf%% int = %d\n", d);
    ft_printf("printf count = %d\n", c);
    c = ft_printf("ft_printf string = %s\n", s);
    ft_printf("printf count = %d\n", c);
    c = ft_printf("ft_printf hexa = %x\n", d);
    printf("=========printf=========\n");
    c = printf("ft_printf%% int = %d\n", d);
    printf("printf count = %d\n", c);
    c = printf("ft_printf string = %s\n", s);
    printf("printf count = %d\n", c);
    c = printf("ft_printf hexa = %x\n", d);
}