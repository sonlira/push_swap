/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:45 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/08 23:51:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack_to_array(t_stack *stack)
{
	t_node	*node;
	int		*arr;
	int		i;

	node = stack->top;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (arr);
}

int	*define_chuks(int *arr, int size, int num_chunks)
{
	int		chunks_size;
	int		*chunks;
	int		i;

	chunks_size = size / num_chunks;
	chunks = malloc(sizeof(int) * num_chunks);
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < num_chunks - 1)
	{
		chunks[i] = arr[(i + 1) * chunks_size - 1];
		i++;
	}
	chunks[num_chunks - 1] = arr[size - 1];
	return (chunks);
}

void	move_chunks_to_b(t_stack *s_a, t_stack *s_b, int *chunks, int n_chun)
{

}

void	sort_large(t_stack *stack_a)
{
	int		*arr;
	t_stack	stack_b;
	int		num_chunks;
	int		*chunks;

	stack_b.size = 0;
	stack_b.top = NULL;
	arr = copy_stack_to_array(stack_a);
	if (!arr)
		return ;
	bubble_sort(arr, stack_a->size);
	num_chunks = get_num_chunks(stack_a->size);
	chunks = define_chuks(arr, stack_a->size, num_chunks);
	if (!chunks)
		return ;
	move_chunks_to_b(stack_a, &stack_b, chunks, num_chunks);
	// int i = 0;
	// while (i < num_chunks)
	// {
	// 	printf("[%d]",chunks[i]);
	// 	i++;
	// }
	// printf("\n");
}
