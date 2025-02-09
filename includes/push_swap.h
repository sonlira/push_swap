/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:18:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/09 21:55:37 by abaldelo         ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
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
int		is_an_ordered_list(t_stack *stack);

t_stack	*init_stack(int argc, char **argv);

t_node	*new_node(int value, int index);
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

#endif
