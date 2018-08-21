/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:21:52 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/21 18:10:00 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
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
	algo(a, b, maxnum, minnum);
	return (0);
}
