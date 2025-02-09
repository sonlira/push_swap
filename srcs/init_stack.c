/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:49:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/09 20:36:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_nodes(t_stack *stack, int size, char **values)
{
	t_node	*current;
	t_node	*previous;
	int		i;
	int		index;

	current = stack->top;
	previous = current->prev;
	i = 2;
	index = 1;
	while (i < size)
	{
		current->next = new_node(ft_atoi(values[i]), index);
		if (!current->next)
		{
			free_stack(&stack);
			return ;
		}
		current = current->next;
		current->prev = previous;
		previous = current;
		stack->size++;
		index++;
		i++;
	}
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = new_node(ft_atoi(argv[1]), 0);
	if (!stack->top)
		return (free_stack(&stack), NULL);
	stack->size = 1;
	create_nodes(stack, argc, argv);
	return (stack);
}
