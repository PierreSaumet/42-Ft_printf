#include <stdio.h>
#include "includes/ft_printf.h"

int		main( void )
{
	char	*str;

	str = "Hello World!";
	ft_printf("The string 'str' contains: %s\n", str);
	printf("The string 'str' contains: %s\n", str);
	return (0);
}
//gcc main.c -L. -lftprintf && ./a.out