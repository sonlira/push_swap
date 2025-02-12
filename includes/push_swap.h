/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:18:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/12 14:42:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				u_half;
	int				cost;
	int				total_cost;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Functions of utils.c
int		validate_input(int argc, char **argv);
int		is_an_ordered_list(t_stack *stack);
// Functions of init_stack.c
t_node	*new_node(int value);
t_stack	*init_stack(int argc, char **argv);
// Functions of stack_utils.c
void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);
t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
int		find_value_position(t_stack *stack, int min_value);
// Functions of operations.c
void	swap(t_stack *stack, char *operator);
void	push(t_stack *orig, t_stack *dest, char *operator);
void	rotate(t_stack *stack, char *operator);
void	reverse_rotate(t_stack *stack, char *operator);
// Functions of sort_small.c
void	sort_small(t_stack *stack);
void	sort_3(t_stack *stack);
// Functions of sort_large.c
void	sort_large(t_stack *stack);
// Functions of sort_large_utils.c
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	get_total_cost(t_stack *stack);
void	get_cost_to_move(t_stack *stack);
t_node	*get_the_lowest_cost(t_stack *stack);
// Functions of sort_large_utils2.c
void	move_up_with_b(t_stack *stack_a, t_stack *stack_b, t_node *node);

#endif
