#include "libftprintf.h"
#include <limits.h>
int		main(void)
{
	int d;
	d = 1025;
	//needs to exit if number given is not immediately followed by conversion or length
	printf("pf_printf: hello %% %.20x\n", d);
	printf("pf_printf: hello %% %.20o\n", d);
	//printf("pf_printf: hello %% %2 d\n", d);
	ft_printf("ft_printf: hello %%d \t == |%d|\n", 0000042);
	printf("pf_printf: hello %%d \t == |%d|\n", 0000042);
	//ft_printf("ft_printf: hello %% %hhd\n", d);
	return (0);
}
