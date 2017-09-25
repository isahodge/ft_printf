#include "libftprintf.h"
#include <limits.h>
int		main(void)
{
	int d;
	d = 150;
	//does not work with int negatives
	printf("pf_printf: hello %% % 030d\n", d);
	ft_printf("ft_printf: hello %% % 030d\n", d);
	printf("1\n");
	//printf("pf_printf: hello %% %+010hhd\n", d);
	ft_printf("ft_printf: hello %% %+010hhd\n", d);
	ft_printf("%+010hhd\n", d);
	return (0);
}
