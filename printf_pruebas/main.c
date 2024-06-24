#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	unsigned int b = 0xab10;
	int *p = &b;
	int *ptr = NULL;

	int lena;
	int lenb;
	
	printf("Imprimo un carácter con la original printf: ");
	lena = printf("%c", 'c');
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un carácter con mi printf: ");
	lenb = ft_printf("%c",'c');
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");

	printf("Imprimo un string con la original printf: ");
	lena = printf("%s", "Hola");
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un string con mi printf: ");
	lenb = ft_printf("%s","Hola");
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");

	/*printf("Imprimo un puntero con la original printf: ");
	lena = printf("%p", p);
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un puntero con mi printf: ");
	lenb = ft_printf("%p", p);
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");*/
	
	

	printf("Imprimo un decimal con la original printf: ");
	lena = printf("%d", 123);
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un decimal con mi printf: ");
	lenb = ft_printf("%d", 123);
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");

	printf("Imprimo un entero con la original printf: ");
	lena = printf("%i", -123);
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un entero con mi printf: ");
	lenb = ft_printf("%i", -123);
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");

	printf("Imprimo un hexadecimal en minúsculas con la original printf: ");
	lena = printf("%x", b);
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un hexadecimal en minúsculas con mi printf: ");
	lenb = ft_printf("%x", b);
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");

	printf("Imprimo un hexadecimal en mayúsculas con la original printf: ");
	lena = printf("%X", b);
	printf(" -> tamaño original: %d", lena);
	printf("\n");
	ft_printf("Imprimo un hexadecimal en mayúsculas con mi printf: ");
	lenb = ft_printf("%X", b);
	printf(" -> mi tamaño: %d", lenb);
	printf("\n");


}
