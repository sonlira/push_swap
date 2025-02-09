/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/09 22:00:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap(stack, "sa\n");
}

void	sort_3(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = stack->top;
	b = a->next;
	c = b->next;
	if (a->value < c->value && b->value > c->value)
	{
		swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else if (a->value > b->value && a->value < c->value)
		swap(stack, "sa\n");
	else if (a->value < b->value && a->value > c->value)
		reverse_rotate(stack, "rra\n");
	else if (a->value > c->value && b->value < c->value)
		rotate(stack, "ra\n");
	else if (a->value > b->value && b->value > c->value)
	{
		swap(stack, "sa\n");
		reverse_rotate(stack, "rra\n");
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	rotations;

	min_value = find_min(stack_a);
	rotations = find_min_position(stack_a, min_value);
	if (rotations == -1)
		return ;
	while (stack_a->top->value != min_value)
	{
		if (rotations <= stack_a->size / 2)
			rotate(stack_a, "ra\n");
		else
			reverse_rotate(stack_a, "rra\n");
	}
	push(stack_a, stack_b, "pb\n");
	sort_3(stack_a);
	push(stack_b, stack_a, "pa\n");
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	rotations;

	min_value = find_min(stack_a);
	rotations = find_min_position(stack_a, min_value);
	if (rotations == -1)
		return ;
	while (stack_a->top->value != min_value)
	{
		if (rotations <= stack_a->size / 2)
			rotate(stack_a, "ra\n");
		else
			reverse_rotate(stack_a, "rra\n");
	}
	push(stack_a, stack_b, "pb\n");
	sort_4(stack_a, stack_b);
	push(stack_b, stack_a, "pa\n");
}

void	sort_small(t_stack *stack_a)
{
	t_stack	stack_b;

	stack_b.top = NULL;
	stack_b.size = 0;
	if (!is_an_ordered_list(stack_a))
		return ;
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, &stack_b);
	else
		sort_5(stack_a, &stack_b);
}
