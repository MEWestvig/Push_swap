/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/24 16:11:15 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b

	a = (t_stack *)malloc(sizeof(*a));
	b = (t_stack *)malloc(sizeof(*b));
	a->stack_size = ac - 1;
	a->stack = (int *)malloc(sizeof(int) * a->stack_size);
	b->stack = (int *)malloc(sizeof(int) * a->stack_size);
}
