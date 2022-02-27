#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#ifdef FT_PRINTF
# include "ft_printf.h"
# define F(...) ft_printf(__VA_ARGS__)
#endif
#ifdef PRINTF
# define F(...) printf(__VA_ARGS__)
#endif

void printf_test1()
{
	int num;
	int res;
	int *addr;

	num = 1234;
	addr = 0x4242424242424;
	F("---test1(regular)---\n");
	res = F("character:%c\n", 'A');
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("string:%s\n", "abcde");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("pointer:%p\n", addr);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("decimal:%d\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("integer:%i\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("unsigned:%u\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("hexadecimal:%x\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("hexadecimal:%x\n", -num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("hexadecimal:%X\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("percent:%%\n");
	printf("res=%d\n", res);
	fflush(stdout);
}
void printf_test2()
{
	int num;
	int res;
	
	num = -1234;
	F("---test2(irregular)---\n");
	res = F("no chara:%c\n", 0);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("blank:%s\n", "");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%s\n", NULL);
	printf("res=%d\n", res);
	fflush(stdout);
//	res = F(NULL);
//	printf("res=%d\n", res);
//	fflush(stdout);
	res = F("null:%p\n", NULL);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("INT_MAX:%d\n", INT_MAX);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("INT_MIN:%d\n", INT_MIN);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("INT_MAX:%x\n", INT_MAX);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("INT_MIN:%X\n", INT_MIN);
	printf("res=%d\n", res);
	fflush(stdout);
}
void printf_test3()
{
	int num;
	int res;

	num = -42;
	F("---test3(field width)---\n");
	res = F("[%15c]\n", 'c');
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%15s]\n", "abcde");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%15p]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%15d]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%15x]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%15X]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
}
void printf_test4()
{
	int num;
	int res;
	
	num = 42;
	F("---test4(precision)---\n");
	res = F("[%.3s]\n", "abcde");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%10.5p]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%10.5d]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%10.5x]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%10.5X]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%10.5X]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("[%10.5X]\n", num);
	printf("res=%d\n", res);
	fflush(stdout);
}

void printf_test5()
{
	int num;
	int res;
	
	num = -1234;
	F("---test5(flag sharp/plus/spase/minus/zero)---\n");
	res = F("sharp+x:%#x\n", num);
	res = F("sharp+X:%#X\n", -num);
	res = F("sharp+X:%#X\n", 0);
	res = F("plus+d:%+d\n", num);
	res = F("plue+d:%+d\n", -num);
	res = F("plus+d:%+d\n", 0);
	res = F("space+d:% d\n", num);
	res = F("space+d:% d\n", -num);
	res = F("space+d:% d\n", 0);
	res = F("[%-10d]\n", num);
	res = F("[%010d]\n", num);
	res = F("[%-10d]\n", num);
}

void printf_test6()
{
	int num;
	int res;
	
	num = -1234;
	F("---test6(corner case)---\n");
	res = F("%%013X\n", ULONG_MAX);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%-1c %-2c %-3c", '0', 0, '1');
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%013x\n", 15);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%%013X\n", UINT_MAX);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%.3X\n", -99);
	printf("res=%.3d\n", res);
	fflush(stdout);
	res = F("%.s\n", "-");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F(" %s \n", "-");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%.11X\n", LONG_MIN);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%1s\n", "a");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%1p\n", (void *)0);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%20d\n", -42000);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%.9s\n", "hi there");
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%.1s\n", NULL);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%+i\n", 42);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%1d\n", -4);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%-.d\n", 0);
	printf("res=%d\n", res);
	fflush(stdout);
}

void 	printf_test7()
{
	int res;

	F("---test7(wrong syntax)---\n");
	res = F("%");
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%%");
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%%%");
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%", 0);
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%%", 0);
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%%%", 0);
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("percent:%%%", 0);
	printf("\nres=%d\n", res);
	fflush(stdout);
}

void	printf_test8()
{
	int	num;
	int	res;
	
	num = -1234;
	F("---test8(lunatic case)---\n");

	res = F("%0+10d\n", 4200);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%.0d\n", 4200);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%*.*d\n", 10, 20, 4200000);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%020.3d\n", 420);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%-.d\n", 0);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%-10.d\n", 0);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%020.10d\n", -42000);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%d\n", 1844674407370955160);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("% u\n", 1234);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%*d\n", -10, 1234);
	printf("res=%d\n", res);
	fflush(stdout);	
}

void	printf_test9()
{
	int	num;
	int	res;
	
	num = -1234;
	F("---test9(bug fix)---\n");
	res = F("%5%");
	printf("\nres=%d\n", res);
	fflush(stdout);
	res = F("%-10.d\n", 0);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%y\n", 4200);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%10@d\n", 4200);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%.-10d\n", 1234);
	printf("res=%d\n", res);
	fflush(stdout);
}

void	printf_test10()
{
	int res;

	puts("---test10(review fix)---");
	res = F("%.*d\n", -10, 1234);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%+u\n", 1234);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("% +x\n", 1234);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%+x\n", 1234);
	printf("res=%d\n", res);
	fflush(stdout);
	res = F("%+p\n", 1234);
	printf("res=%d\n", res);
	fflush(stdout);
}

int main (void)
{	
#ifdef FT_PRINTF
	puts("=======ft_printf=======");
	fflush(stdout);
#endif
#ifdef PRINTF
	puts("=======printf=======");
	fflush(stdout);
#endif

	printf_test1();
	printf_test2();
	printf_test3();
	printf_test4();
	printf_test5();
	printf_test6();
	printf_test7();
	printf_test8();
	printf_test9();
	printf_test10();
	return (0);
}	
