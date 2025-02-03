/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:49:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/03 19:03:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack ;
	t_node	*current;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = new_node(ft_atoi(argv[1]));
	if (!stack->top)
		return (free_stack(&stack), NULL);
	stack->size = 1;
	current = stack->top;
	i = 2;
	while (i < argc)
	{
		current->next = new_node(ft_atoi(argv[i]));
		if (!current->next)
			return (free_stack(&stack), NULL);
		current = current->next;
		stack->size++;
		i++;
	}
	return (stack);
}
