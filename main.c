#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%s%s", av[1], av[2]);
	return (0);
}