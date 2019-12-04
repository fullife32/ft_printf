#include "ft_printf.h"

int	main()
{
	printf("%d", printf("bonjour%s%ld\nsalut\n%sok", " toi\n", -2147483648, "it's "));
	return (0);
}