/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:02:17 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/06 12:00:18 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	receive_input2(t_stack **a, t_stack **b, char *line)
{
	if (!(ft_strcmp(line, "rr")))
	{
		*a = rotate(*a);
		*b = rotate(*b);
	}
	else if (!(ft_strcmp(line, "rra")))
		*a = rev_rotate(*a);
	else if (!(ft_strcmp(line, "rrb")))
		*b = rev_rotate(*b);
	else if (!(ft_strcmp(line, "rrr")))
	{
		*a = rev_rotate(*a);
		*b = rev_rotate(*b);
	}
	else if (!(ft_strcmp(line, "")))
	{
		ft_putendl_fd("Nothing inputted, please input a command.", 2);
	}
	else
		error(3);
}

void	receive_input(t_stack **a, t_stack **b)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (!(ft_strcmp(line, "sa")))
			*a = swap(*a);
		else if (!(ft_strcmp(line, "sb")))
			*b = swap(*b);
		else if (!(ft_strcmp(line, "ss")))
		{
			*a = swap(*a);
			*b = swap(*b);
		}
		else if (!(ft_strcmp(line, "pa")))
			*b = push(&*a, *b);
		else if (!(ft_strcmp(line, "pb")))
			*a = push(&*b, *a);
		else if (!(ft_strcmp(line, "ra")))
			*a = rotate(*a);
		else if (!(ft_strcmp(line, "rb")))
			*b = rotate(*b);
		else
			receive_input2(a, b, line);
		free(line);
	}
}
