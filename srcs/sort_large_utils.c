/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:14:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 14:42:06 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "rr\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "");
	reverse_rotate(stack_b, "rrr\n");
}

void	get_total_cost(t_stack *stack)
{
	t_node	*target;
	t_node	*current;

	current = stack->top;
	while (current)
	{
		target = current->target;
		current->total_cost = current->cost + target->cost;
		current = current->next;
	}
}

void	get_cost_to_move(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		current->index = find_value_position(stack, current->value);
		if (current->index <= stack->size / 2)
		{
			current->u_half = 1;
			current->cost = current->index;
		}
		else
		{
			current->u_half = 0;
			current->cost = stack->size - current->index;
		}
		current = current->next;
	}
}

t_node	*get_the_lowest_cost(t_stack *stack)
{
	t_node	*low_cost;
	t_node	*current;

	current = stack->top;
	low_cost = current;
	while (current)
	{
		if (current->total_cost == 0)
			return (current);
		else if (current->total_cost < low_cost->total_cost)
			low_cost = current;
		current = current->next;
	}
	return (low_cost);
}
