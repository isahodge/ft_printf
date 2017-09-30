#include "libftprintf.h"
#include <limits.h>
int		main(void)
{
	/*ft_printf("\\n");
	ft_printf("%%\\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	printf("%x\\n", 505);
	printf("\n");
	ft_printf("%x\\n", 505);
	ft_printf("%X\\n", 505);
	ft_printf("%p\\n", &ft_printf);*/

	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\\n", 3);
	ft_printf("%010d\\n", 1);
	ft_printf("%hhd\\n", 0);
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%hhd\\n", 0);
	ft_printf("%\\n");
	/*int d;
	d = -1;
	char *str = NULL;

	uintmax_t f = -125;
	unsigned long long g = -125;
	//figure out why error on ftprintf.com
	
	ft_printf("%.0x\n", 0);
	printf("%.0x\n", 0);
	printf("%.0o\n", 0);
	ft_printf("%#.0o\n", 0);
	printf("pf_printf: hello %% % 030d\n", d);
	ft_printf("ft_printf: hello %% % 030d\n", d);
	printf("pf_printf: hello %% %+010hhd\n", (char)d);
	ft_printf("ft_printf: hello %% %+010hhd\n", (char)d);
	printf("%+010hhd\n", (char)d);
	ft_printf("%+010hhd\n", (char)d);
	printf("%+010.20d\n", d);
	ft_printf("%+010.20d\n", d);
	printf("%+.20d\n", d);
	ft_printf("%+.20d\n", d);
	printf("%+20d\n", d);
	ft_printf("%+20d\n", d);
	printf("%+020.10d\n", d);
	ft_printf("%+020.10d\n", d);
	printf("pf_printf: %+010hhd\n", (char)d);
	ft_printf("ft_printf: %+010hhd\n", (char)d);
	printf("pf_printf: %+010.6d\n", d);
	ft_printf("ft_printf: %+010.6d\n", d);
	printf("pf_printf: %+.20d\n", d);
	ft_printf("ft_printf: %+.20d\n", d);
	printf("pf_printf: %+20d\n", d);
	ft_printf("ft_printf: %+20d\n", d);
	printf("pf_printf: %+020.10d\n", d);
	ft_printf("ft_printf: %+020.10d\n", d);
	ft_printf("ft_printf: %hx\n", (unsigned short)-1);
	printf("pf_printf: %hx\n", (unsigned short)-1);
	printf("pf_printf: %hhx\n", (unsigned char)-1);
	ft_printf("ft_printf: %hx\n", (unsigned char)-1);
	printf("pf_printf: %020x\n", (unsigned int)d);
	ft_printf("ft_printf: %020x\n", (unsigned int)d);
	//printf("pf_printf: % 20x\n", (unsigned int)d);undefined behavior
	//ft_printf("ft_printf: % 20x\n", (unsigned int)d);
	printf("pf_printf: %20x\n", (unsigned int)d);
	ft_printf("ft_printf: %+20x\n", (unsigned int)d);
	printf("pf_printf: %.30X\n", (unsigned int)d);
	ft_printf("ft_printf: %.30X\n", (unsigned int)d);
	printf("pf_printf: %020.10o\n", (unsigned int)d);
	ft_printf("ft_printf: %020.10o\n", (unsigned int)d);
	//printf("pf_printf: %+20.10o\n", (unsigned int)d);undefined
	//ft_printf("ft_printf: %+20.10o\n", (unsigned int)d);
	//printf("pf_printf: %+20.30o\n", (unsigned int)d);undefined
	//ft_printf("ft_printf: %+20.30o\n", (unsigned int)d);
	printf("pf_printf: %ju\n", (intmax_t)d);
	ft_printf("ft_printf: %ju\n", (intmax_t)d);
	//printf("pf_printf: %+ju\n", (intmax_t)d);undefined
	//ft_printf("ft_printf: %+ju\n", (intmax_t)d);
	//printf("pf_printf: % ju\n", (intmax_t)d);undefined
	//ft_printf("ft_printf: % ju\n", (intmax_t)d);
	//printf("pf_printf: %+hhu\n", (unsigned char)d);undefined
	//ft_printf("ft_printf: %+hhu\n", (unsigned char)d);
	printf("pf_printf: %.20ju\n", (intmax_t)d);
	ft_printf("ft_printf: %.20ju\n", (intmax_t)d);
	printf("pf_printf: %30.30ju\n", (intmax_t)d);
	ft_printf("ft_printf: %30.30ju\n", (intmax_t)d);
	printf("pf_printf: %30.30ju\n", (intmax_t)d);
	ft_printf("ft_printf: %30.30ju\n", (intmax_t)d);
	printf("pf_printf: %30.0zu\n", (size_t)d);
	ft_printf("ft_printf: %30.0zu\n", (size_t)d);
	printf("pf_printf: %30.0zu\n", (size_t)d);
	ft_printf("ft_printf: %30.0zu\n", (size_t)d);
	//printf("pf_printf: % u\n", (unsigned int)d);undefined
	//ft_printf("ft_printf: % u\n", (unsigned int)d);
	//printf("pf_printf: %-020u\n", (unsigned int)d);'0' ignored when '-' present
	//ft_printf("ft_printf: %-020u\n", (unsigned int)d);
	printf("pf_printf: %.20lx\n", (unsigned long)d);
	ft_printf("ft_printf: %.20lx\n", (unsigned long)d);
	printf("pf_printf: %.5hhX\n", (unsigned char)d);
	ft_printf("ft_printf: %.5hhX\n", (unsigned char)d);
	printf("pf_printf: %#020x\n", (unsigned int)d);
	ft_printf("ft_printf: %#020x\n", (unsigned int)d);
	printf("pf_printf: %#020X\n", (unsigned int)d);
	ft_printf("ft_printf: %#020X\n", (unsigned int)d);

	//passes everything
	printf("pf_printf: %#o\n", 50);
	ft_printf("ft_printf: %#o\n", 50);
	printf("pf_printf: %#020o\n", d);
	ft_printf("ft_printf: %#020o\n", d);
	printf("pf_printf: %#020hx\n", (unsigned short)d);
	ft_printf("ft_printf: %#020hx\n", (unsigned short)d);
	printf("pf_printf: %#020hhX\n", (unsigned char)d);
	ft_printf("ft_printf: %#020hhX\n", (unsigned char)d);
	printf("pf_printf: %#020zo\n", (size_t)d);
	ft_printf("ft_printf: %#020zo\n", (size_t)d);
	printf("pf_printf: %#llX\n", (unsigned long long)d);
	ft_printf("ft_printf: %#llX\n", (unsigned long long)d);
	printf("pf_printf: %#020X\n", d);
	ft_printf("ft_printf: %#020X\n", d);

	printf("1\n");//everything passes
	printf("pf_printf: %#020o\n", d);
	ft_printf("ft_printf: %#020o\n", d);
	printf("pf_printf: %020o\n", d);
	ft_printf("ft_printf: %020o\n", d);
	printf("pf_printf: %#20o\n", d);
	ft_printf("ft_printf: %#20o\n", d);
	printf("pf_printf: %#o\n", 1);
	ft_printf("ft_printf: %#o\n", 1);
	printf("pf_printf: %#03o\n", 1);
	ft_printf("ft_printf: %#03o\n", 1);
	printf("pf_printf: %#0.20hx\n", (unsigned short)d);
	ft_printf("ft_printf: %#0.20hx\n", (unsigned short)d);
	printf("pf_printf: %#020.30hhX\n", (unsigned char)d);
	ft_printf("ft_printf: %#020.30hhX\n", (unsigned char)d);

	printf("2\n");//everything passes
	printf("pf_printf: %#0.3zo\n", (size_t)1); 
	ft_printf("ft_printf: %#0.3zo\n", (size_t)1);
	printf("pf_printf: %0.3zo\n", (size_t)1);
	ft_printf("ft_printf: %0.3zo\n", (size_t)1);
	printf("pf_printf: %#0.4zo\n", (size_t)9); 
	ft_printf("ft_printf: %#0.4zo\n", (size_t)9);
	printf("pf_printf: %.3zo\n", (size_t)9); 
	ft_printf("ft_printf: %.3zo\n", (size_t)9);

	printf("3\n");
	printf("pf_printf: %.0u\n", 10);
	ft_printf("ft_printf: %.0u\n", 10);
	printf("pf_printf: %.0d\n", 10);
	ft_printf("ft_printf: %.0d\n", 10);
	printf("pf_printf: %.0u\n", 0);
	ft_printf("ft_printf: %.0u\n", 0);//fails 
	printf("pf_printf: %010.0d\n", -10);
	ft_printf("ft_printf: %010.0d\n", -10);
	printf("pf_printf: %1.0d\n", -10);
	ft_printf("pf_printf: %1.0d\n", -10);
	printf("pf_printf: %#.30llX\n", (unsigned long long)d);
	ft_printf("ft_printf: %#.30llX\n", (unsigned long long)d);
	printf("pf_printf: %#020.1X\n", d);
	ft_printf("ft_printf: %#020.1X\n", d);
	printf("pf_printf: %#020o\n", d);
	ft_printf("ft_printf: %#020o\n", d);
	printf("pf_printf: %020o\n", d);
	ft_printf("ft_printf: %020o\n", d);
	printf("pf_printf: %#20o\n", d);
	ft_printf("ft_printf: %#20o\n", d);
	printf("pf_printf: %.2o\n", 1);
	ft_printf("ft_printf: %.2o\n", 1);
	printf("pf_printf: %#03o\n", 1);
	ft_printf("ft_printf: %#03o\n", 1);

	ft_printf("%u\n", 42);
	ft_printf("Kashim a %u historires a %u raconter", 1001, 1);
	ft_printf("Il fait au moins %%u %u\n", -8000);
	ft_printf("%u", -0);
	ft_printf("%u", 0);
	ft_printf("%u", INT_MAX);
	ft_printf("%u", INT_MIN);
	ft_printf("%u", INT_MIN -1);
	ft_printf("%u", INT_MAX + 1);
	ft_printf("%%u 0000042 == |%u|\n", 0000042);
	ft_printf("%%u \t == |%u|\n", '\t');
	ft_printf("%%u Lydie == |%u|\n", 'L' +  'y' + 'd' + 'i' + 'e');

	//printf("%.20c\n", (char)d);undefined behavior
	//printf("% c\n", (char)d);undefined behavior
	printf("pf_printf: %10c\n", 'a');//undefined behavior with zero flag
	ft_printf("ft_printf: %10c\n", 'a');//undefined behavior with zero flag
	printf("pf_printf: %-10c\n", '$');
	ft_printf("ft_printf: %-10c\n", '$');
	printf("pf_printf: %c\n", 'a');
	ft_printf("ft_printf: %c\n", 'a');
	printf("pf_printf: %10c\n", '$');
	ft_printf("ft_printf: %10c\n", '$');
	ft_printf("1\n");
	printf("pf_printf: %s\n", "hello");
	ft_printf("ft_printf: %s\n", "hello");
	printf("pf_printf: %10s\n", "hello");
	ft_printf("ft_printf: %10s\n", "hello");
	//printf("% s\n", "hello");//undefined behavior
	printf("pf_printf: %.3s\n", "hello");
	ft_printf("ft_printf: %.3s\n", "hello");
	printf("pf_printf: %10.3s\n", "hello");
	ft_printf("ft_printf: %10.3s\n", "hello");
	printf("pf_printf: %-10.3s\n", "hello");
	ft_printf("ft_printf: %-10.3s\n", "hello");
	ft_printf("2\n");
	printf("pf_printf: %.0s\n", "hello");
	ft_printf("ft_printf: %.0s\n", "hello");
	printf("pf_printf: %.10s\n", "hello");
	ft_printf("ft_printf: %.10s\n", "hello");
	printf("pf_printf: %10.9s\n", "hello");
	ft_printf("ft_printf: %10.9s\n", "hello");
	printf("pf_printf: %10.3s\n", str);
	ft_printf("ft_printf: %10.3s\n", str);
	printf("pf_printf: %-10.3s\n", str);
	ft_printf("ft_printf: %-10.3s\n", str);
	//printf("%i\n", printf("%.0s", "hello"));
	//printf("pf_printf:%.0s\n", "hello");
	ft_printf("unintmax_t f= %ju sizeof f = %lu\n", f, sizeof(f));
	printf("unintmax_t f= %ju sizeof f = %lu\n", f, sizeof(f));
	ft_printf("unsigned long long g = %llu sizeof f = %lu\n", g, sizeof(g));
	printf("unsigned long long g = %llu sizeof f = %lu\n", g, sizeof(g));
	printf("pf_printf: %10d%% des gens %c\n", 100, 'a');
	ft_printf("ft_printf: %10d%% ies gens %c\n", 100, 'a');
	ft_printf("%i\n", ft_printf("%c\t%%%c%s\n", 'a', 'b', "hello"));
	ft_printf("ft_printf: %+020d\n", d * -1);
	ft_printf("ft_printf: % d\n", d * -1);
	ft_printf("ft_printf: % 010d\n", d);
	ft_printf("ft_printf: % 010d\n", d * -1);*/
	return (0);
}
