/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:45 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 12:58:00 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_cost_and_target_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	t_node	*current;
	t_node	*target;
	t_node	*min_prox;

	current = stack_a->top;
	while (current)
	{
		node = stack_b->top;
		target = find_max(stack_b);
		min_prox = find_min(stack_b);
		while (node)
		{
			if (node->value < current->value && node->value >= min_prox->value)
			{
				min_prox = node;
				target = min_prox;
			}
			node = node->next;
		}
		current->target = target;
		current = current->next;
	}
	get_cost_to_move(stack_a);
	get_cost_to_move(stack_b);
}

static void	get_cost_and_target_to_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*node;
	t_node	*current;
	t_node	*target;
	t_node	*max_prox;

	current = stack_b->top;
	while (current)
	{
		node = stack_a->top;
		target = find_min(stack_a);
		max_prox = find_max(stack_a);
		while (node)
		{
			if (node->value > current->value && node->value <= max_prox->value)
			{
				max_prox = node;
				target = max_prox;
			}
			node = node->next;
		}
		current->target = target;
		current = current->next;
	}
	get_cost_to_move(stack_a);
	get_cost_to_move(stack_b);
}

static void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*low_cost;

	push(stack_a, stack_b, "pb\n");
	push(stack_a, stack_b, "pb\n");
	while (stack_a->size > 3)
	{
		get_cost_and_target_to_b(stack_a, stack_b);
		get_total_cost(stack_a);
		low_cost = get_the_lowest_cost(stack_a);
		move_up_with_b(stack_a, stack_b, low_cost);
		push(stack_a, stack_b, "pb\n");
	}
}

static void	push_to_a(t_stack *stack_b, t_stack *stack_a)
{
	sort_3(stack_a);
	while (stack_b->size > 0)
	{
		get_cost_and_target_to_a(stack_b, stack_a);
		get_total_cost(stack_a);
		while (stack_a->top->value != stack_b->top->target->value)
		{
			if (stack_b->top->target->is_mid_top)
				rotate(stack_a, "ra\n");
			else
				reverse_rotate(stack_a, "rra\n");
		}
		push(stack_b, stack_a, "pa\n");
	}
	while (stack_a->top->value != find_min(stack_a)->value)
	{
		if (find_min(stack_a)->is_mid_top)
			rotate(stack_a, "ra\n");
		else
			reverse_rotate(stack_a, "rra\n");
	}
}

void	sort_large(t_stack *stack_a)
{
	t_stack	stack_b;

	if (is_an_ordered_list(stack_a))
		return ;
	if (!stack_a || !stack_a->top)
		return ;
	stack_b.size = 0;
	stack_b.top = NULL;
	push_to_b(stack_a, &stack_b);
	push_to_a(&stack_b, stack_a);
}
