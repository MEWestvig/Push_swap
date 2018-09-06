/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/06 12:13:01 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = initialise(a_head, av, ac);
	receive_input(&a_head, &b_head);
	check_stacks(a_head, b_head);
	return (0);
}
