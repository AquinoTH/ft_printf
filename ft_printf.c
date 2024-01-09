/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:13:17 by taquino-          #+#    #+#             */
/*   Updated: 2024/01/09 18:00:36 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(char type, va_list ap)
{
	int	bytes;

	bytes = 0;
	if (type == 'c')
		bytes += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		bytes += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		bytes += ft_ptr_base(va_arg(ap, unsigned long), HEXA_LOWER_BASE);
	else if (type == 'd' || type == 'i')
		bytes += ft_nbr_base(va_arg(ap, int), DECIMAL_BASE);
	else if (type == 'u')
		bytes += ft_nbr_base(va_arg(ap, unsigned int), DECIMAL_BASE);
	else if (type == 'x')
		bytes += ft_nbr_base(va_arg(ap, unsigned int), HEXA_LOWER_BASE);
	else if (type == 'X')
		bytes += ft_nbr_base(va_arg(ap, unsigned int), HEXA_UPPER_BASE);
	else if (type == '%')
		bytes += ft_putchar('%');
	return (bytes);
}

int ft_printf(char *format, ...)
{
    int num_args = strlen(format);
    
    va_list args;
    va_start (args, num_args);
    int i;

    i = 0;
    while (i < num_args)
    {
        if (format[i] == 'c')
        {    
            int x = va_arg (args, int);
            printf ("x: %d\n", x);
        }
        else if (format[i] == 'd')
        {
            double  x =  va_arg(args, double);
            printf ("x: %f\n", x);
        }
        i++;
    }
    va_end (args);

    return (0);
}

int main (void)
{
    ft_printf(5, 10, 15, 3, 45, 50);
    
    return (0);
}



#include "ft_printf.h"

int	ft_printf(const char *type, ...)
{
	va_list	ap;
	int		i;
	int		bytes;

	if (!type)
		return (-1);
	va_start(ap, type);
	i = 0;
	bytes = 0;
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1] != '\0')
			bytes += ft_parsing(type[++i], ap);
		else
			bytes += ft_putchar(type[i]);
		i++;
	}
	va_end(ap);
	return (bytes);
}
/*
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	char	t = 'T';
    char    name[] = "Thiago Aquino Costa";
	char	*pointer = NULL;
    int	age = 27;
	int height = 175;
		

    ft_printf("A inicial do meu nome é: %c. Meu nome é: %s. Minha idade é: %i. Minha altura é: %d. E %p.\n", t, name, age, height, pointer);
    printf("A inicial do meu nome é: %c. Meu nome é: %s. Minha idade é: %i. Minha altura é: %d. E %p.\n", t, name, age, height, pointer);
}
*/