#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%10.5d", atoi(av[1]));
	return (0);
}