/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:54:32 by margarita         #+#    #+#             */
/*   Updated: 2024/09/24 22:40:09 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
	rather than value. */

void	sort_three(t_stack **stack)
{
	int	biggest;

	if (is_sorted(*stack))
		return ;
	biggest = biggest_index(*stack);
	if ((*stack)->index == biggest)
		do_ra(stack);
	else if ((*stack)->next->index == biggest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
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

/*	Sorting algorithm for a stack larger than 3.
	 Push everything but 3 numbers to stack B.
	 Sort the 3 numbers left in stack A.
	 Calculate the most cost-effective move.
	 Shift elements until stack A is in order. */

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_init(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack(stack_a);
}