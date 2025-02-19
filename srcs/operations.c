/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:41 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 14:06:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *operator)
{
	t_node	*new_top;

	if (!stack->top || stack->size < 2)
		return ;
	new_top = stack->top->next;
	stack->top->next = new_top->next;
	new_top->next = stack->top;
	stack->top = new_top;
	ft_putstr_fd(operator, 1);
}

void	push(t_stack *orig, t_stack *dest, char *operator)
{
	t_node	*new_top_dest;

	if (!orig || !orig->top)
		return ;
	new_top_dest = orig->top;
	orig->top = orig->top->next;
	new_top_dest->next = dest->top;
	dest->top = new_top_dest;
	orig->size--;
	dest->size++;
	ft_putstr_fd(operator, 1);
}

void	rotate(t_stack *stack, char *operator)
{
	t_node	*last_node;
	t_node	*new_node;

	if (!stack->top || stack->size < 2)
		return ;
	new_node = stack->top->next;
	last_node = stack->top;
	while (last_node->next)
		last_node = last_node->next;
	stack->top->next = NULL;
	last_node->next = stack->top;
	stack->top = new_node;
	ft_putstr_fd(operator, 1);
}

void	reverse_rotate(t_stack *stack, char *operator)
{
	t_node	*last_node;
	t_node	*penultimate_node;

	if (!stack || stack->size < 2)
		return ;
	last_node = stack->top;
	while (last_node->next)
	{
		penultimate_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = stack->top;
	stack->top = last_node;
	penultimate_node->next = NULL;
	ft_putstr_fd(operator, 1);
}
