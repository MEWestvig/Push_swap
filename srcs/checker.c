/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:37:18 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/21 17:20:06 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = initialise(a_head, b_head, av, ac);
	receive_input(&a_head, &b_head);
	check_stacks(a_head, b_head);
	return (0);
}
