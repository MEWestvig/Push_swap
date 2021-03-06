/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:58:28 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/10 15:52:42 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_dup(int *values)
{
	int temp;
	int i;
	int	j;

	i = 0;
	while (values[i])
	{
		temp = values[i];
		j = 0;
		while (values[j])
		{
			if (values[j] == temp && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		*set_values(char **arr, int size)
{
	int i;
	int j;
	int	*values;

	i = 0;
	values = (int *)malloc(sizeof(int) * size + 1);
	while (i < size)
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				error(1);
			++j;
		}
		if (ft_longatoi(arr[i]) > MAXINT)
			error(6);
		else
			values[i] = ft_atoi(arr[i]);
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	return (values);
}

char	*set_str(char **init, int size)
{
	int		i;
	char const	*temp;
	char const	*str;

	i = 1;
	str = ft_strdup((const char *)init[i]);
	while (i < size - 1)
	{
		temp = ft_strjoin(str, " ");
		str = ft_strjoin(temp, init[i + 1]);
		i++;
	}
	return ((char *)str);
}
t_stack	*set_stacks(t_stack *a, int *values, int size)
{
	int		i;
	t_stack	*a_head;

	i = 1;
	a = create(values[0], NULL);
	a_head = a;
	while (i < size)
	{
		a = add_end(a, values[i]);
		i++;
	}
	free(values);
	return (a_head);
}

t_stack	*initialise(t_stack *a, char **init, int size)
{
	int		*values;
	char	**arr;
	char	*str;
	int		lst_size;

	lst_size = 0;
	if (size < 2)
		error(0);
	str = set_str(init, size);
	arr = ft_strsplit(str, ' ');
	ft_strdel(&str);
	while (arr[lst_size])
		lst_size++;
	values = set_values(arr, lst_size);
	if (!check_dup(values))
		error(5);
	return (set_stacks(a, values, lst_size));
}
