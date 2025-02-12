/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:04:14 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_arguments(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	if (!node)
		return (0);
	if (!stack_a || !stack_a->top || stack_a->size < 2)
		return (0);
	else if (!stack_b || !stack_b->top || stack_b->size < 2)
		return (0);
	return (1);
}

void	move_up_with_b(t_stack *a, t_stack *b, t_node *n)
{
	t_node	*t;
	t_node	*f;

	if (!validate_arguments(a, b, n))
		return ;
	t = n->target;
	while (a->top->value != n->value)
	{
		f = b->top;
		if ((n->u_half == 1 && t->u_half == 1) && f->value != t->value)
			rr(a, b);
		else if ((n->u_half == 0 && t->u_half == 0) && f->value != t->value)
			rrr(a, b);
		else if (n->u_half)
			rotate(a, "ra\n");
		else
			reverse_rotate(a, "rra\n");
	}
	while (b->top->value != t->value)
	{
		if (t->u_half)
			rotate(b, "rb\n");
		else
			reverse_rotate(b, "rrb\n");
	}
}

/*
	a = stack_a
	b = stack_b
	n = node;
	t = target;
	f = first_node_to_b
*/