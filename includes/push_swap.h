/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:22:56 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/21 18:10:16 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

int		check_a(t_stack *a);
void	algo(t_stack *a_head, t_stack *b_head, int max, int min);

#endif
