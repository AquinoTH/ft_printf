/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:15:17 by clira-ne          #+#    #+#             */
/*   Updated: 2024/01/03 09:04:17 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	int	bytes;

	bytes = write(1, &c, 1);
	return (bytes);
}

int	ft_putstr(char *str)
{
	int	len_str;
	int	bytes;

	if (!str)
		return (write(1, "(null)", 6));
	len_str = ft_strlen(str);
	bytes = write(1, str, len_str);
	return (bytes);
}

int	ft_n_base(long long num, char *base)
{
	int	bytes;
	int	size_base;

	bytes = 0;
	size_base = ft_strlen(base);
	if (num < 0)
	{
		bytes += ft_putchar('-');
		num = -num;
	}
	if (num >= size_base)
		bytes += ft_n_base((num / size_base), base);
	bytes += ft_putchar(base[num % size_base]);
	return (bytes);
}

int	ft_ptr_base(unsigned long num, char *base)
{
	int	bytes;
	int	size_base;

	if (num == 0)
		return (ft_putstr("(nil)"));
	bytes = 0;
	size_base = ft_strlen(base);
	if (num >= (unsigned long)size_base)
		bytes += ft_ptr_base((num / size_base), base);
	else
		bytes += ft_putstr("0x");
	bytes += ft_putchar(base[num % size_base]);
	return (bytes);
}
