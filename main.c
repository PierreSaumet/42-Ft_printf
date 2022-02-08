#include <stdio.h>
#include "includes/ft_printf.h"

int		main( void )
{
	char	*str;

	str = "Hello World!";
	ft_printf("The string 'str' contains: %s\n", str);
	printf("The string 'str' contains: %s\n", str);

	ft_printf("The number is: %d\n", 1052 + 955212174 - 485745);
	printf("The number is: %d\n", 1052 + 955212174 - 485745);
	
	return (0);
}
//gcc main.c -L. -lftprintf && ./a.out