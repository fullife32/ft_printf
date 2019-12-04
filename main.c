#include "ft_printf.h"

int	main(int ac, char **av)
{
	ft_printf("bonjour%s%dsalut\n\n", " toi\n", -2147483648);
	return (0);
}