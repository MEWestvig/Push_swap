/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:13:01 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/21 13:29:11 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_a(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	algo(t_stack *a_head, t_stack *b_head, int max)
{
	t_stack	*a;
	t_stack	*b;

	a = a_head;
	b = b_head;
	while (!(check_a(a_head) && b == NULL))
	{
		if (a->value == max)
		{
			a = rotate(a);
			ft_putendl("ra");
		}
		if (a->value > a->next->value)
		{
			a = swap(a);
			ft_putendl("sa");
		}
		else
		{
			a = push(&b, a);
			ft_putendl("pb");
		}
		if (check_a(a))
		{
			if (b != NULL && b->next != NULL)
				if (b->next->value > b->value)
				{
					b = swap(b);
					ft_putendl("sb");
				}
			if (b != NULL)
			{
				b = push(&a, b);
				ft_putendl("pa");
			}
		}
	}
}
