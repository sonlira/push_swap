/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:18:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/08 23:49:12 by abaldelo         ###   ########.fr       */
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
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int		validate_input(int argc, char **argv);
int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		has_duplicates(char **argv);

t_stack	*init_stack(int argc, char **argv);

t_node	*new_node(int value);
void	free_stack(t_stack **stack);
int		find_min(t_stack *stack);
int		find_min_position(t_stack *stack, int min_value);
void	print_stack(t_stack *stack);

void	swap(t_stack *stack, char *operator);
void	push(t_stack *orig, t_stack *dest, char *operator);
void	rotate(t_stack *stack, char *operator);
void	reverse_rotate(t_stack *stack, char *operator);

void	sort_small(t_stack *stack);
void	sort_large(t_stack *stack);
void	move_chunks_to_b(t_stack *s_a, t_stack *s_b, int *chunks, int n_chun);
void	bubble_sort(int *values, int size);
int		get_num_chunks(int size);

#endif
