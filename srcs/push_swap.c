/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:21:52 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/10 15:53:47 by mwestvig         ###   ########.fr       */
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

int		is_rev(t_stack *a_head)
{
	t_stack	*tmp;
	
	tmp = a_head;
	while(tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	***head;
	t_stack	*lst;

	a = initialise(a, av, ac);
	head = (t_stack ***)malloc(sizeof(t_stack **) * 2);
	head[0] = &a;
	head[1] = &b;
	if (stacksize(a) < 5)
		mini_sort(a, b);
	else if (is_rev(a))
		rev_sort(a, b);
	else
		quicksort(head, stacksize(a), 1, 2);
	return (0);
}
