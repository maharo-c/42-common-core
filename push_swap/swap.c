/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:26:14 by margarita         #+#    #+#             */
/*   Updated: 2024/09/24 07:41:51 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the top 2 elements of a stack.
	Does nothing if there is only one or no elements. */

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	// Check if the stack is empty or has only one element
	if(!*stack || (*stack)->next == NULL)
		return ;

	// Perform the swap
	temp = *stack;					// Store the first node
	*stack = (*stack)->next;		// Move the second node to the top
	temp->next = (*stack)->next;	// Link the first node to the third node
	(*stack)->next = temp;			// Link the second node to the first node
}

/*	Swaps the top 2 elements of stack a. Prints "sa" to the standard output*/

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

/*Swaps the top 2 elements of stack b. Prints "sb" to the standard output*/

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

/*	Swaps the top 2 elements of the stack a and the top 2 elements of
	the stack b. Prints "ss" to the standard output. */

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
