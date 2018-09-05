/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:13:01 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/31 12:28:02 by mwestvig         ###   ########.fr       */
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

/*void	algo(t_stack *a_head, t_stack *b_head, int max, int min)
{
	t_stack	*a;
	t_stack	*b;

	a = a_head;
	b = b_head;
	while (!(check_a(a) && b == NULL))
	{
		if (a->value == max)
		{
			if (b != NULL && b->next != NULL)
			{
				if (b->value == min)
				{
					a = rotate(a);
					b = rotate(b);
					ft_putendl("rr");
				}
			}
			else
			{
				a = rotate(a);
				ft_putendl("ra");
			}
		}
		if (a->value > a->next->value)
		{
			if (b != NULL && b->next != NULL)
			{
				if (b->next->value > b->value)
				{
					a = swap(a);
					b = swap(b);
					ft_putendl("ss");
				}
				else
				{
					a = swap(a);
					ft_putendl("sa");
				}
			}
			else
			{
				a = swap(a);
				ft_putendl("sa");
			}
		}
		else if (!check_a(a))
		{
			a = push(&b, a);
			ft_putendl("pb");
		}
		if (check_a(a))
		{
			if (b != NULL && b->next != NULL)
			{
				if (b->value == min)
				{
					b = rotate(b);
					ft_putendl("rb");
				}
				if (b->next->value > b->value)
				{
					b = swap(b);
					ft_putendl("sb");
				}
			}
			if (b != NULL)
			{
				b = push(&a, b);
				ft_putendl("pa");
			}
		}
	}
}*/
