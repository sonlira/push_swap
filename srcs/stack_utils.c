/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 13:34:20 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		ft_putnbr_fd(node->value, 1);
		ft_putstr_fd(" -> ", 1);
		node = node->next;
	}
	ft_putendl_fd("NULL", 1);
}

void	free_stack(t_stack **stack)
{
	t_node	*node;

	if (!stack || !*stack)
		return ;
	while ((*stack)->top)
	{
		node = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		free(node);
	}
	free(*stack);
	*stack = NULL;
}

t_node	*find_min(t_stack *stack)
{
	t_node	*nodo;
	t_node	*min_value;

	if (!stack || !stack->top)
		return (NULL);
	nodo = stack->top;
	min_value = nodo;
	while (nodo)
	{
		if (min_value->value > nodo->value)
			min_value = nodo;
		nodo = nodo->next;
	}
	return (min_value);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*nodo;
	t_node	*max_value;

	if (!stack || !stack->top)
		return (NULL);
	nodo = stack->top;
	max_value = nodo;
	while (nodo)
	{
		if (max_value->value < nodo->value)
			max_value = nodo;
		nodo = nodo->next;
	}
	return (max_value);
}

int	find_value_position(t_stack *stack, int value)
{
	t_node	*current;
	int		rotations;

	if (!stack || !stack->top)
		return (-1);
	rotations = 0;
	current = stack->top;
	while (current->value != value)
	{
		current = current->next;
		rotations++;
	}
	return (rotations);
}
