#include "print_lib.h"
#include "stdio.h"

int	main(void)
{
	/*int a;
	a = 6;
	int *p = NULL;*/
	int lena;
	int lenb;
	//lena = printf(" Decimal %d", -10);
	//printf(": %zu \n ", lena);*/
	printf("original printf \n");
	lena = printf("%c\n", "c");
	printf("->tamaño %d\n", lena);
	ft_printf("mi printf\n");
	lenb = ft_printf("%c\n","c");
	printf("->tamaño %d\n", lenb);    

	

}