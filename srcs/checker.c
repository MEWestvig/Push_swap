/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/14 11:11:14 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	initialise(t_stack *a, t_stack *b, char **init, int stack_size)
{
	//stack_size is ac because av includes the ./ so it needs to start from 1.
	i = 1;

	while (i < stack_size)
	{
		
	}
	//set each value of the stack.
	//malloc each node and set next to NULL
	//Do this for both a and b, but only assign values to a
	//if it hits an invalid value, print out error message and exit
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack *a;
	t_stack *b;

	a_head = (t_stack *)malloc(sizeof(t_stack));
	b_head = (t_stack *)malloc(sizeof(t_stack));
	a = a_head;
	b = b_head;
	initialise(a, b, av, ac);
	//if argc == 2, either 1 number or $ARG (use split to get the variables)
	//if argc > 2, use argv to get each stack value.
}
