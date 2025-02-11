/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:45 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/11 18:26:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*copy_stack_to_array(t_stack *stack)
// {
// 	t_node	*node;
// 	int		*arr;
// 	int		i;

// 	node = stack->top;
// 	arr = malloc(sizeof(int) * stack->size);
// 	if (!arr)
// 		return (NULL);
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		arr[i] = node->value;
// 		node = node->next;
// 		i++;
// 	}
// 	return (arr);
// }

// int	*define_chuks(int *arr, int size, int num_chunks)
// {
// 	int		chunks_size;
// 	int		*chunks;
// 	int		i;

// 	chunks_size = size / num_chunks;
// 	chunks = malloc(sizeof(int) * num_chunks);
// 	if (!chunks)
// 		return (NULL);
// 	i = 0;
// 	while (i < num_chunks - 1)
// 	{
// 		chunks[i] = arr[(i + 1) * chunks_size - 1];
// 		i++;
// 	}
// 	chunks[num_chunks - 1] = arr[size - 1];
// 	return (chunks);
// }

// void	move_chunks_to_b(t_stack *s_a, t_stack *s_b, int *chunks, int n_chun)
// {

// }
void	get_total_cost(t_stack *orig, t_stack *dest)
{
	t_node *node;
	t_node *current;

	current = orig->top;
	while(current)
	{
		node = dest->top;
		while(node->value != current->target)
			node = node->next;
		current->total_cost = current->cost + node->cost;
		current = current->next;
	}
}

void	get_cost_to_move(t_stack *stack)
{
	t_node *current;
	
	current = stack->top;
	while (current)
	{
		current->index = find_value_position(stack, current->value);
		if(current->index <= stack->size / 2)
		{
			current->is_mid_top = 1;
			current->cost = current->index;
		}
		else
			current->cost = stack->size - current->index;
		current = current->next;
	}
}

void	get_cost_and_target_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node *node;
	t_node *current;
	int		target;
	int		min_prox;

	current = stack_a->top;
	while(current)
	{
		node = stack_b->top;
		target = find_max(stack_b);
		min_prox = find_min(stack_b);
		while(node)
		{
			if(node->value < current->value && node->value >= min_prox)
			{
				min_prox = node->value;
				target = min_prox;
			}
			node = node->next;
		}
		current->target = target;
		current = current->next;
	}
	get_cost_to_move(stack_a);
	get_cost_to_move(stack_b);
}

void push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a);
	print_stack(stack_b);
	// push(stack_a, stack_b, "pb\n");
	// push(stack_a, stack_b, "pb\n");
	//get_cost_and_target_to_b(stack_a, stack_b);
	//get_total_cost(stack_a, stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);
	t_node *node = stack_a->top;
	while(node)
	{
		printf("node_a %d -> target %d\n",node->value, node->target);
		printf("cost node_a %d -> total_cost %d\n",node->cost, node->total_cost);
		node = node->next;
		// printf("value next_node %d\n", node->value);
	}
	// while (stack_a->size > 3)
	// {

	// }
}

void	sort_large(t_stack *stack_a)
{
	t_stack	stack_b;
	if (!is_an_ordered_list(stack_a))
		return ;
	if (!stack_a || !stack_a->top)
		return ;
	stack_b.size = 0;
	stack_b.top = NULL;
	print_stack(stack_a);
	print_stack(&stack_b);
	push_to_b(stack_a, &stack_b);
}
