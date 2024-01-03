/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:08:25 by clira-ne          #+#    #+#             */
/*   Updated: 2024/01/03 09:08:32 by clira-ne         ###   ########.fr       */
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
		bytes += ft_n_base(va_arg(ap, int), DECIMAL_BASE);
	else if (type == 'u')
		bytes += ft_n_base(va_arg(ap, unsigned int), DECIMAL_BASE);
	else if (type == 'x')
		bytes += ft_n_base(va_arg(ap, unsigned int), HEXA_LOWER_BASE);
	else if (type == 'X')
		bytes += ft_n_base(va_arg(ap, unsigned int), HEXA_UPPER_BASE);
	else if (type == '%')
		bytes += ft_putchar('%');
	return (bytes);
}
