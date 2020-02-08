#include <stdio.h>

int main()
{
	printf("|%*.*d|\n", 4, 3, -12);
	ft_printf("|%*.*d|\n", 4, 3, -12);
	printf("%2.p\n", NULL);
	ft_printf("%2.p\n", NULL);
}
