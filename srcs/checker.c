/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/15 22:23:24 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	t_stack	*a;

	a_head = initialise(a_head, b_head, av, ac);
	a = a_head;
	while(a != NULL)
	{
		fprintf(stdout, "%d\n", a->value);
		fflush(stdout);
		a = a->next;
	}
	fprintf(stdout, "\n");
	fflush(stdout);
	a = a_head;
	a = rev_rotate(a);
	while(a != NULL)
	{
		fprintf(stdout, "%d\n", a->value);
		fflush(stdout);
		a = a->next;
	}
	fprintf(stdout, "\n");
	fflush(stdout);
	while (b_head != NULL)
	{
		fprintf(stdout, "%d\n", b_head->value);
		fflush(stdout);
		b_head = b_head->next;
	}
	return (0);
}
