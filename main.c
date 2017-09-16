#include "libftprintf.h"

int		main(void)
{
	unsigned int d;

	d = -100;
	printf("pf_printf: hello %10d\n", d);
	return (ft_printf("ft_printf: hello %10d\n", 100));
}
