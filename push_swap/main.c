/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:32:01 by margarita         #+#    #+#             */
/*   Updated: 2024/10/01 17:22:48 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Chooses a sorting method depending on the number of values to be sorted. */

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* Checks if the input is correct, in which case it initializes stacks a and b,
   assigns each value indexes and sorts the stacks. When sorting is done, frees
   the stacks and exits.
   system("leaks push_swap");  */

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	i = 1;
	stack_b = NULL;
	stack_a = NULL;
	while (i < argc)
	{
		get_numbers(argv[i], &stack_a); 
		i++;
	}
	if (is_duplicated(stack_a)) //Verifica si hay duplicados
		error_exit(&stack_a, NULL);
	stack_size = get_stack_size(stack_a); //Obtiene el tamaño de la pila
	get_index(stack_a, stack_size + 1); //Asigna índice a cada nodo
	push_swap(&stack_a, &stack_b, stack_size); //Ordena la pila
	free_stack(&stack_a); //Libera la pila A
	free_stack(&stack_b); //Libera la pila B
	return (0);
}
