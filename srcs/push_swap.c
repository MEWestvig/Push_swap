/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:21:52 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/06 12:12:46 by mwestvig         ###   ########.fr       */
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
	t_stack	***head;
	t_stack	*lst;

	head = (t_stack ***)malloc(sizeof(t_stack **) * 2);
	a = initialise(a, av, ac);
	head[0] = &a;
	head[1] = &b;
	quicksort(head, stacksize(a), 1, 2);
	while (a)
	{
		lst = a;
		a = lst->next;
		free(lst);
	}
	free(head);
	return (0);
}
