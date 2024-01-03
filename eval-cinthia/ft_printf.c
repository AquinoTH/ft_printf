/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:19 by clira-ne          #+#    #+#             */
/*   Updated: 2024/01/03 14:30:10 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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