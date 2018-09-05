/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:22:56 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/05 13:56:38 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

void	quicksort(t_stack **a, t_stack **b, int size, int stack, int n);
int		stacksize(t_stack *stack);
int		median(t_stack *stack, int size);
int		is_sorted(t_stack *stack, int size, int a_b);
void	sort3(t_stack **a_head, t_stack **b_head, int size, int stack);
int		pusher(t_stack **a, t_stack **b, int stack, int pivot);
void	do_oper(t_stack **a, t_stack **b, char *line);

#endif
