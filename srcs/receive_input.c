/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:02:17 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/21 11:31:14 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	receive_input(t_stack **a, t_stack **b)
{
	char *line;
	t_stack *test_a;
	t_stack *test_b;

	test_a = *a;
	test_b = *b;
	while (get_next_line(1, &line))
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
		else if (!(ft_strcmp(line, "rr")))
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
		else
			error(3);
		test_a = *a;
		while (test_a)
		{
			fprintf(stdout, "%d ", test_a->value);
			fflush(stdout);
			test_a = test_a->next;
		}
		fprintf(stdout, "\n");
		fflush(stdout);
		test_b = *b;
		while (test_b)
		{
			fprintf(stdout, "%d ", test_b->value);
			fflush(stdout);
			test_b = test_b->next;
		}
		fprintf(stdout, "\n");
		fflush(stdout);
	}
}
