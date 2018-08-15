/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:41:13 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/15 12:34:39 by mwestvig         ###   ########.fr       */
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

t_stack* create(int value, t_stack* next);
void	error(int status);

#endif
