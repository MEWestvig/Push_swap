/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:32:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/20 17:44:30 by mwestvig         ###   ########.fr       */

/* ************************************************************************** */

#include "../includes/push_swap.h"

int *set_values(char **arr, int size)
{
	int i;
	int j;
	int	*values;

	i = 0;
	values = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				error(1);
			++j;
		}
		values[i] = ft_atoi(arr[i]);
		i++;
	}
	return (values);
}

t_stack	*set_stacks(t_stack *a, t_stack *b, int *values, int size)
{
	int i;
	t_stack	*a_head;

	i = 1;
	a = create(values[0], NULL);
	a_head = a;
	while (i < size)
	{
		a = add_end(a, values[i]);
		i++;
	}
	return (a_head);
}

t_stack	*initialise(t_stack *a, t_stack *b, char **init, int stack_size)
{
	int		i;
	int		*values;
	char	**arr;

	i = 1;
	arr = (char **)malloc(sizeof(char *) * stack_size);
	if (stack_size < 2)
		error(0);
	while (i < stack_size)
	{
		arr[i - 1] = ft_strdup(init[i]);
		i++;
	}
	values = set_values(arr, stack_size - 1);
	return (set_stacks(a, b, values, stack_size - 1));
}