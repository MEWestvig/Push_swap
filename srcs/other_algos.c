/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_algos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:13:01 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/10 14:41:22 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_a(t_stack *a)
{
	t_stack	*a_head;

	a_head = a;
	if (a && a->next == NULL)
		return (2);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	a = a_head;
	return (1);
}

void	rev_sort(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		do_oper(&a, &b, "rra");
		do_oper(&a, &b, "pb");
	}
	while (b)
		do_oper(&a, &b, "pa");
}

int		find_max(t_stack *a)
{
	t_stack	*temp;
	int		max;

	temp = a;
	max = 0;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

void	mini_sort(t_stack *a, t_stack *b)
{
	int max;

	max = find_max(a);
	while (!(check_a(a) && !b))
	{
		if (a->value == max)
			do_oper(&a, &b, "ra");
		if (a->value > a->next->value)
			do_oper(&a, &b, "sa");
		else if (!check_a(a))
			do_oper(&a, &b, "pb");
		if (check_a(a))
		{
			if (b && b->next)
				if (b->next->value > b->value)
					do_oper(&a, &b, "sb");
			if (b)
				do_oper(&a, &b, "pa");
		}
	}
}
