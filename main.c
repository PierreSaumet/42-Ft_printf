#include <stdio.h>
#include "includes/ft_printf.h"

int		main( void )
{
	int		*ret;
	char	*str;

	if (!(ret = malloc(sizeof(int *) * 20)))
		return (1);
	for (int i = 0; i < 20; i++)
		ret[i] = 0;
	str = "Hello World!";

	//	Empty string
	// printf("ret = %d\n", ft_printf("%s\n", NULL));
	// printf("ret = %d\n", printf("%s\n", NULL));
	// One string
	printf("ret = %d\n", ft_printf("The string 'str' contains: %s\n", str));
	printf("ret = %d\n", printf("The string 'str' contains: %s\n", str));
	// ret[0] = ft_printf("The string 'str' contains: %s\n", str);
	// ret[1] = printf("The string 'str' contains: %s\n", str);
	// // Multiple strings
	// ret[2] = ft_printf("The string 'str' contains: %s and %s and %s and %s\n", str, "Bonjour le monde", NULL, "Bless 42! I am a long and pointless sentence that just shows that the function works wonderfully and my favorite french book is the Count of Monte Cristo");
	// ret[3] = printf("The string 'str' contains: %s and %s and %s and %s\n", str, "Bonjour le monde", NULL, "Bless 42! I am a long and pointless sentence that just shows that the function works wonderfully and my favorite french book is the Count of Monte Cristo");

	// ret[4] = ft_printf("The number is: %d\n", 1052 + 955212174 - 485745);
	// ret[5] = printf("The number is: %d\n", 1052 + 955212174 - 485745);
	

	// Now we checks the returns
	printf("\n\n");
	for (int i = 0; i < 19; i += 2)
		printf("ret[%d] = %d and ret[%d] = %d\n", i, ret[i], i + 1, ret[i + 1]);
	return (0);
}
//gcc main.c -L. -lftprintf && ./a.out

// /* Example for printf() */
// #include <stdio.h>

// int main(){
//    printf ("Integers: %i %u \n", -3456, 3456);
//    printf ("Characters: %c %c \n", 'z', 80);
//    printf ("Decimals: %d %ld\n", 1997, 32000L);
//    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
//    printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
//    printf ("Preceding with empty spaces: %10d \n", 1997);
//    printf ("Preceding with zeros: %010d \n", 1997);
//    printf ("Width: %*d \n", 15, 140);
//    printf ("%s \n", "Educative");
//    return 0;
// }