
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main (void)
{
	char	*name = "Thiago Aquino Costa";
	char	c = 'T';
	int	age = 27;
	int	count;
	char	*ptr = NULL;

	count = ft_printf("Meu nome é %s, a minha inicial é %c e eu tenho %d\n", name, c, age);
	ft_printf("%i\n", count);
	count = printf("Meu nome é %s, a minha inicial é %c e eu tenho %d\n", name, c, age);
	printf("%i\n", count);
	count = ft_printf("%p\n", ptr);
	ft_printf("%i\n", count);
	count = printf("%p\n", ptr);
	printf("%i\n", count);
	ft_printf("%x\n", INT_MIN);
	printf("%x\n", INT_MIN);
	
	return (0);
}

