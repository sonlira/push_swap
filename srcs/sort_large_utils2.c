/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:04:14 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 13:30:38 by abaldelo         ###   ########.fr       */
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

void	move_up_with_b(t_stack *sa, t_stack *sb, t_node *no)
{
	t_node	*ta;
	t_node	*tsb;

	if (!validate_arguments(sa, sb, no))
		return ;
	ta = no->target;
	while (sa->top->value != no->value)
	{
		tsb = sb->top;
		if ((!no->is_mid_top && !ta->is_mid_top) && tsb->value != ta->value)
			rr(sa, sb);
		else if ((no->is_mid_top && ta->is_mid_top) && tsb->value != ta->value)
			rrr(sa, sb);
		else if (no->is_mid_top)
			rotate(sa, "ra\n");
		else
			reverse_rotate(sa, "rra\n");
	}
	while (sb->top->value != ta->value)
	{
		if (ta->is_mid_top)
			rotate(sb, "rb\n");
		else
			reverse_rotate(sb, "rrb\n");
	}
}

/*
	sa = stack_a
	sb = stack_b
	no = node;
	ta = target;
	tsb = top_stack_b
*/