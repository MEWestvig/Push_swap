/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:41:13 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/15 22:22:04 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

# define RED "\x1B[31m"
# define WHITE "\x1B[0m"

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

t_stack			*create(int value, t_stack* next);
void			error(int status);
t_stack 		*swap(t_stack *stack);
t_stack			*push(t_stack **stack1, t_stack *stack2);
t_stack			*add_begin(t_stack *head, int value);
t_stack			*del_begin(t_stack *head);
t_stack			*add_end(t_stack *head, int value);
t_stack			*del_end(t_stack *head);
t_stack			*rotate(t_stack *stack);
t_stack			*rev_rotate(t_stack *stack);

#endif
