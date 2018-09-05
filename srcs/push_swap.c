/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:21:52 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/05 14:02:54 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_oper(t_stack **a, t_stack **b, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		*a = swap(*a);
	if (!(ft_strcmp(line, "sb")))
		*b = swap(*b);
	if (!(ft_strcmp(line, "ra")))
		*a = rotate(*a);
	if (!(ft_strcmp(line, "rb")))
		*b = rotate(*b);
	if (!(ft_strcmp(line, "pa")))
		*b = push(&*a, *b);
	if (!(ft_strcmp(line, "pb")))
		*a = push(&*b, *a);
	if (!(ft_strcmp(line, "rra")))
		*a = rev_rotate(*a);
	if (!(ft_strcmp(line, "rrb")))
		*b = rev_rotate(*b);
	ft_putendl(line);
}

int		stacksize(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
	int		maxnum;
	int		minnum;

	maxnum = 0;
	minnum = MAXINT;
	a = initialise(a, b, av, ac);
	temp = a;
	while (temp)
	{
		if (temp->value > maxnum)
			maxnum = temp->value;
		if (temp->value < minnum)
			minnum = temp->value;
		temp = temp->next;
	}
	quicksort(&a, &b, stacksize(a), 1, 2);
	return (0);
}
