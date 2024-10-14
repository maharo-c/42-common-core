/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:32 by margarita         #+#    #+#             */
/*   Updated: 2024/10/14 16:28:23 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Sorting algorithm for a stack larger than 3.
	 Push everything but 3 numbers to stack B.
	 Sort the 3 numbers left in stack A.
	 Calculate the most cost-effective move.
	 Shift elements until stack A is in order. */

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_init(stack_a, stack_b); //Movemos todos los elementos (excepto 3 al stack B)
	sort_three(stack_a); //Ordenamos los 3 elementos restantes en A
	while (*stack_b) //Mientras existan elementos en B
	{
		get_target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack(stack_a);
}

/*	Pushes all the elements of stack a into stack b, except the three last.
	Smaller values first, then the larger values to help with efficiency.*/
	
void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushes++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		do_pb(stack_a, stack_b);
		pushes++;
	}
}

/*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
	rather than value. */

void	sort_three(t_stack **stack)
{
	int	biggest;

	if (is_sorted(*stack)) //Return si está ordenado
		return ;
	biggest = biggest_index(*stack); //Buscamos el índice mayor
	if ((*stack)->index == biggest) //Si el índice del primer nodo es el mayor
		do_ra(stack); //Rotamos stack A, pasando el primer elemento a la última posición
	else if ((*stack)->next->index == biggest) //Si el índice del segundo nodo es el mayor
		do_rra(stack); //Rotamos al revés el stack A, pasando el segundo nodo a la última posición
	if ((*stack)->index > (*stack)->next->index) //Comparamos los índices del primer y segundo nodo
		do_sa(stack); //Intercambiamos si el índice del primer nodo es mayor al del segundo nodo
}

/*	The stack a is almost sorted, rotate stack a until the lowest
	value is at the top. If it is in the bottom half of the stack, reverse
	rotate, otherwise rotate until it is at the top. */

static void	sort_stack(t_stack **stack_a)
{
	int	lowest_p;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_p = position_lowest_index(stack_a);
	if (lowest_p > stack_size / 2)
	{
		while (lowest_p < stack_size)
		{
			do_rra(stack_a);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			do_ra(stack_a);
			lowest_p--;
		}
	}
}

/* Returns the highest index in a stack. */

static int	biggest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}
