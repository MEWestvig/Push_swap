/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:42:21 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/14 10:03:12 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(t_stack *stack)
{
	t_stack	temp;

	temp = stack->stack;
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = temp;
}

void	push(int *stack1, int *stack2)
{
	int *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	temp = (int *)malloc(sizeof(int) * a->stack_size);
	while (i < a->stack_size)
	{
		temp[i] = stack1[i];
		i++;
	}
	i = 1;
	stack1[0] = stack2[0];
	while (i < a->stack_size)
	{
		stack1[i] = temp[i];
		i++;
	}
	while (j < a->stack_size)
	{
		stack2[j] = stack2[j + 1];
		j++;
	}
	free(temp);
}

//push
	//push a (top of b to top of a)
	//push b (top of a to top of b)

//rotate
	//rot a (shift all of a up 1, first element becomes last)
	//rot b (shift all of b up 1, first element becomes last)
	//rot both

//reverse rotate
	//rev rot a (shift all of a down 1, last element becomes first)
	//rev rot b (shift all of b down 1, last element becomes first)
	//rev rot both
