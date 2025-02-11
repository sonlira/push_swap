/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->target = 0;
	node->index = 0;
	node->is_mid_top = 0;
	node->cost = -1;
	node->total_cost = -1;
	node->next = NULL;
	return (node);
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

int	find_min(t_stack *stack)
{
	t_node	*nodo;
	int		min_value;

	if (!stack || !stack->top)
		return (-1);
	nodo = stack->top;
	min_value = nodo->value;
	while (nodo)
	{
		if (min_value > nodo->value)
			min_value = nodo->value;
		nodo = nodo->next;
	}
	return (min_value);
}

int	find_max(t_stack *stack)
{
	t_node	*nodo;
	int		max_value;

	if (!stack || !stack->top)
		return (-1);
	nodo = stack->top;
	max_value = nodo->value;
	while (nodo)
	{
		if (max_value < nodo->value)
			max_value = nodo->value;
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
