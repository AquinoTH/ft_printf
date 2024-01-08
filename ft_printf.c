/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:13:17 by taquino-          #+#    #+#             */
/*   Updated: 2024/01/03 18:24:55 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char *placeholders, ...)
{
    int num_args = strlen(placeholders);
    
    va_list args;
    va_start (args, num_args);
    int i;

    i = 0;
    while (i < num_args)
    {
        if (placeholders[i] == 'c')
        {    
            int x = va_arg (args, int);
            printf ("x: %d\n", x);
        }
        else if (placeholders[i] == 'd')
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


