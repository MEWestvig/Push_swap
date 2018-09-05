/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:40:01 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/05 16:04:48 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}

void	check_stacks(t_stack *a, t_stack *b)
{
	if (b != NULL)
	{
		ft_putstr_fd(RED, 2);
		ft_putendl_fd("KO", 2);
		ft_putstr_fd(WHITE, 2);
		if (a)
			free_stack(a);
		if (b)
			free_stack(b);
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
				if (a)
					free_stack(a);
				if (b)
					free_stack(b);
				exit(1);
			}
			a = a->next;
		}
		ft_putstr_fd(GREEN, 2);
		ft_putendl_fd("OK", 2);
	}
	ft_putstr_fd(WHITE, 2);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}
