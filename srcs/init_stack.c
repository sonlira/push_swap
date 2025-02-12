/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:49:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 14:42:06 by abaldelo         ###   ########.fr       */
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
	node->index = 0;
	node->u_half = 0;
	node->cost = -1;
	node->total_cost = -1;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

static void	create_nodes(t_stack *stack, int size, char **values)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 2;
	while (i < size)
	{
		current->next = new_node(ft_atoi(values[i]));
		if (!current->next)
		{
			free_stack(&stack);
			return ;
		}
		current = current->next;
		stack->size++;
		i++;
	}
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = new_node(ft_atoi(argv[1]));
	if (!stack->top)
		return (free_stack(&stack), NULL);
	stack->size = 1;
	create_nodes(stack, argc, argv);
	return (stack);
}
