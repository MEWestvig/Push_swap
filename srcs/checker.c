/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/14 14:50:45 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	set_stacks(t_stack *a, t_stack *b, int *values, int size)
{
	//malloc each node and set next to NULL
	//Do this for both a and b, but only assign values to a
}

void	initialise(t_stack *a, t_stack *b, char **init, int stack_size)
{
	int		i;
	int		j;
	int		k;
	int		*values;
	char	**arr;

	i = 1;
	j = 1;
	k = 0;
	arr[0] = ft_strdup("Begin");
	values = (int *)malloc(sizeof(int) * stack_size - 1);
	arr = (char **arr)malloc(sizeof(char **) * stack_size);
	if (stack_size < 2)
		error(0);
	if (stack_size == 2)
	{
		if (!ft_strcmp(av[1], "$ARG"))
			arr = ft_strsplit($ARG, ' ');
		else
			arr[1] = ft_strdup(av[1]);
	}
	else
		while (av[i])
		{
			arr[i] = ft_strdup(av[i]);
			i++;
		}
	i = 1;
	while (i < stack_size)
	{
		if (!ft_isdigit(arr[j]))
			error(1);
		values[k] = ft_atoi(arr[j]);
		i++;
		j++;
		k++;
	}
	set_stacks(a, b, values, (stack_size - 1))
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack *a;
	t_stack *b;

	a_head = (t_stack *)malloc(sizeof(t_stack));
	b_head = (t_stack *)malloc(sizeof(t_stack));
	a = a_head;
	b = b_head;
	initialise(a, b, av, ac);
	//if argc == 2, either 1 number or $ARG (use split to get the variables)
	//if argc > 2, use argv to get each stack value.
}
