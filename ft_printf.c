#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void ft_putstr(char *str, int *len)
{
	if(!str)
	{
		str = "(null)";
	}
	while(*str)
	{
		*len += write(1, str++, 1);
	}
}

void putdigit(long long int nb, int base, int *len)
{
	char *hexa = "01234r56789abcdef";
	if(nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if(nb > base)
	{
		putdigit((nb / base), base, len);
	}
	*len += write(1, &hexa[nb % base], 1);
}

int ft_printf(char *format, ...)
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while(*format)
	{
		if((*format == '%') && *(format + 1))
		{
			format++;
			if(*format == 's')
				putstr(va_arg(ptr, char *), &len);
			else if(*format == 'd')
				putdigit((long long int)va_arg(ptr, int), 10, &len);
			else if(*format == 'x')
				putdigit((long long int)va_arg(ptr, unsigned int), 16, &len);		
		}
		else
			write(1, format, 1);
		format++;	
	}
	return (va_end(ptr), len);
}
