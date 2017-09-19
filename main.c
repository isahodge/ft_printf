#include "libftprintf.h"

int		main(void)
{
	unsigned int d;
	d = 100;
	//printf("pf_printf: hello %06d\n", d);
	printf("pf_printf: hello %+20.10d\n", d);
	ft_printf("ft_printf: hello %% %+20.10d\n", d);
	return (0);
}
