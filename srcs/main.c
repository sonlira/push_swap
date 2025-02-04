/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/04 18:43:48 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;

	if (!validate_input(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
    stack_a = init_stack(argc, argv);
	print_stack(stack_a);
	if (stack_a->size <= 5)
		sort_small(stack_a);
	print_stack(stack_a);
	
    // stack_b = malloc(sizeof(t_stack));
    // stack_b->top = NULL;
    // stack_b->size = 0;

	return (0);
}
