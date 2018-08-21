/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:40:01 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/21 11:38:19 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_stacks(t_stack *a, t_stack *b)
{
	if (b != NULL)
	{
		ft_putstr_fd(RED, 2);
		ft_putendl_fd("KO", 2);
		ft_putstr_fd(WHITE, 2);
		exit(1);
	}
	else
	{
		while (a->next)
		{
			if (a->value > a->next->value)
			{
				ft_putstr_fd(RED, 2);
				ft_putendl_fd("KO", 2);
				ft_putstr_fd(WHITE, 2);
				exit(1);
			}
			a = a->next;
		}
		ft_putstr_fd(GREEN, 2);
		ft_putendl_fd("OK", 2);
	}
	ft_putstr_fd(WHITE, 2);
	exit(1);
}
