/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:23:59 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/14 12:29:30 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	error(int status)
{
	ft_putstr_fd(RED, 2);
	if (status == 0)
		ft_putendl_fd("Error: Too few arguments.", 2);
	if (status == 1)
		ft_putendl_fd("Error: Invalid input.", 2);
	ft_putstr_fd(WHITE, 2);
	exit(1);
}
