/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/04 22:46:06 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap(stack);
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
		swap(stack);
		rotate(stack);
	}
	else if (a->value > b->value && a->value < c->value)
		swap(stack);
	else if (a->value < b->value && a->value > c->value)
		reverse_rotate(stack);
	else if (a->value > c->value && b->value < c->value)
		rotate(stack);
	else if (a->value > b->value && b->value > c->value)
	{
		swap(stack);
		reverse_rotate(stack);
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;

	min_value = find_min(stack_a);
	while (stack_a->top->value != min_value)
		rotate(stack_a);
	push(stack_a, stack_b);
	sort_3(stack_a);
	push(stack_b, stack_a);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min_valu;

	min_valu = find_min(stack_a);
	while (stack_a->top->value != min_valu)
		rotate(stack_a);
	push(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push(stack_b, stack_a);
}

void	sort_small(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else
	{
		stack_b = malloc(sizeof(stack_b));
		if (!stack_b)
			return ;
		stack_b->top = NULL;
		stack_b->size = 0;
		if (stack_a->size == 4)
			sort_4(stack_a, stack_b);
		else
			sort_5(stack_a, stack_b);
		free_stack(&stack_b);
	}
}
