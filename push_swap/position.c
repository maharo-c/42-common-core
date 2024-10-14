/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:53:40 by margarita         #+#    #+#             */
/*   Updated: 2024/10/14 23:21:15 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Calculates and assigns a target position for each element in stack B
	based on their index, relative to the position of elements in stack A */

//La posición objetivo indica dónde debería colocarse cada nodo de stack_b
//al moverlo a stack_a para que la pila stack_a se mantenga ordenada.

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target;

	tmp = *stack_b; //Inicialización puntero auxiliar
	get_position(stack_a); //Asignamos valor a las posiciones del stack A
	get_position(stack_b); //Asignamos valor a las posiciones del stack B
	target = 0; //Variable usada para llevar el seguimiento de la pos objetivo
	while (tmp)
	{
		target = get_target(stack_a, tmp->index, INT_MAX, target);
		//Buscamos la posición adecuada en el stack A del nodo del stack B
		tmp->target = target;
		tmp = tmp->next;
	}
}

/*	Assigns a position to each element of a stack from top to bottom
	is ascending order. It is used to calculate the cost of moving a certain
	number to a certain position. */

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*	Picks the best target position in stack A for the given index of
	an element in stack B. First checks if the index of the B element can
	be placed somewhere in between elements in stack A.
	If not, it finds the element with the smallest index in A and assigns 
	that as the target position. */
	
static int	get_target(t_stack **stack_a, int index_b, int target_i, int target)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_i)
		{
			target_i = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_i != INT_MAX)
		return (target);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_i)
		{
			target_i = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target);
}

/*	Gets the current position of the element with the lowest index. */

int	position_lowest_index(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_i;
	int		lowest_p;

	tmp = *stack;
	lowest_i = INT_MAX;
	get_position(stack);
	lowest_p = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_i)
		{
			lowest_i = tmp->index;
			lowest_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_p);
}
