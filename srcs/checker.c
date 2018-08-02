/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/02 18:42:29 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack *a;
	t_stack *b;
	int		stack_size;
	int 	i;

	i = 0;
	stack_size = ac - 1;
	a_head = (t_stack *)malloc(sizeof(t_stack));
	b_head = (t_stack *)malloc(sizeof(t_stack));
	a = a_head;
	b = b_head;
	b = NULL;
	while (av[i])
	{
		//if it hits an invalid value, return ERROR.
		//malloc each list piece as it goes.
		a->value = ft_atoi(av[i]);
		a->next = NULL;
		a = a->next;
	}
}
