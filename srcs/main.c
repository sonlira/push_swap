/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/03 20:09:15 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (!validate_input(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
    stack_a = init_stack(argc, argv);
    stack_b = malloc(sizeof(t_stack));  // Pila `b` vacía
    stack_b->top = NULL;
    stack_b->size = 0;

    // Imprimir pila inicial
    printf("Stack A antes de las operaciones:\n");
    print_stack(stack_a);
    printf("Stack B antes de las operaciones:\n");
    print_stack(stack_b);

    // Aplicar operaciones
    printf("\nAplicando swap a Stack A:\n");
    swap(stack_a);
    print_stack(stack_a);

    printf("\nAplicando push de A a B:\n");
    push(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    printf("\nAplicando rotate a Stack A:\n");
    rotate(stack_a);
    print_stack(stack_a);

    printf("\nAplicando reverse rotate a Stack A:\n");
    reverse_rotate(stack_a);
    print_stack(stack_a);

    // Liberar memoria
    free_stack(&stack_a);
    free_stack(&stack_b);
	return (0);
}
