/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/15 14:43:10 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*set_stacks(t_stack *a, t_stack *b, int *values, int size)
{
	int i;
	t_stack	*a_head;

	a_head = a;
	i = 1;
	a->value = values[0];
	a->next = NULL;
	while (i < size)
	{
		t_stack* new = create(values[i], NULL);
		a->next = new;
		a = a->next;
		i++;
	}
	return (a_head);
}

t_stack	*initialise(t_stack *a, t_stack *b, char **init, int stack_size)
{
	int		i;
	int		j;
	int		k;
	int		*values;
	char	**arr;
	int		h;

	i = 1;
	j = 1;
	k = 0;
	values = (int *)malloc(sizeof(int) * stack_size - 1);
	arr = (char **)malloc(sizeof(char *) * stack_size);
	arr[0] = ft_strdup("Begin");
	if (stack_size < 2)
		error(0);
	if (stack_size == 2)
	{
		if (!ft_strcmp(init[1], "$ARG"))
			arr = ft_strsplit(init[1], ' ');
		else
			arr[1] = ft_strdup(init[1]);
	}
	else
		while (init[i])
		{
			arr[i] = ft_strdup(init[i]);
			i++;
		}
	i = 1;
	while (i < stack_size)
	{
		while (arr[j][h])
		{
			if (!ft_isdigit(arr[j][h]))
				error(1);
			h++;
		}
		h = 0;
		values[k] = ft_atoi(arr[j]);
		i++;
		j++;
		k++;
	}
	return (set_stacks(a, b, values, (stack_size - 1)));
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = (t_stack *)malloc(sizeof(t_stack));
	a_head = initialise(a_head, b_head, av, ac);
	while(a_head != NULL)
	{
		fprintf(stdout, "%d\n", a_head->value);
		fflush(stdout);
		a_head = a_head->next;
	}
	//Do operations in order
	return (0);
}
