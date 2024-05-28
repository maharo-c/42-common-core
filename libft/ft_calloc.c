/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:49:08 by maharo-c          #+#    #+#             */
/*   Updated: 2024/05/28 16:15:47 by maharo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void*	ptr;
		 
    total_size = num * size;// Calcular el tamaño total de memoria a asignar
    ptr = malloc(total_size);// Asignar la memoria
    if (ptr == NULL) {
        return NULL;
    }
    ft_memset(ptr, 0, total_size);// Inicializar la memoria a cero
    return (ptr);
}

int main() {
    int *arr;
    int n, i;

    printf("Introduce el número de elementos: ");
    scanf("%d", &n);

    // Asignar memoria para n elementos de tipo int e inicializarla a cero
    arr = (int*) calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Mostrar el arreglo inicializado
    printf("El arreglo inicializado a cero:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arr);

    return 0;
}
