/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/11 20:08:18 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_matriz(char ***matriz)
{
	int	i;

	i = 0;
	if (!matriz || !*matriz)
		return ;
	while ((*matriz)[i])
	{
		free((*matriz)[i]);
		i++;
	}
	free(*matriz);
	*matriz = NULL;
}

static t_stack	*check_and_init_stack(int argc, char **argv)
{
	char	**new_argv;
	char	*str;
	t_stack	*stack;

	if (argc == 2)
	{
		str = ft_strjoin("skip ", argv[1]);
		if (!str)
			return (NULL);
		new_argv = ft_split(str, ' ');
		if (!new_argv)
			return (NULL);
		argc = 0;
		while (new_argv[argc])
			argc++;
		if (!validate_input(argc, new_argv))
			return (ft_putendl_fd("Error", 2), NULL);
		stack = init_stack(argc, new_argv);
		return (free(str), free_matriz(&new_argv), stack);
	}
	if (!validate_input(argc, argv))
		return (ft_putendl_fd("Error", 2), NULL);
	stack = init_stack(argc, argv);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = check_and_init_stack(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	if (stack_a->size <= 5)
		sort_small(stack_a);
	else
		sort_large(stack_a);
	print_stack(stack_a);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}
