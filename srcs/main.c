/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/06 18:51:31 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void free_matriz(char **matriz)
{
	int i;
	i = 0;
	while(matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char *str;

	if(argc == 2)
	{
		str = ft_strjoin("ignore ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = 0;
		while(argv[argc])
			argc++;
	}
	if (!validate_input(argc, argv))
		return (ft_putendl_fd("Error",2),EXIT_FAILURE);
    stack_a = init_stack(argc, argv);
	free_matriz(argv);
	if (stack_a->size <= 5)
		sort_small(stack_a);
	else
		sort_large(stack_a);
	return (EXIT_SUCCESS);
}
