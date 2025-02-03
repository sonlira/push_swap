/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/03 19:05:22 by abaldelo         ###   ########.fr       */
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
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack **stack)
{
	t_node	*node;

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
		printf("%d -> ", node->value);
		node = node->next;
	}
	printf("NULL\n");
}
