/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:42:21 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/15 22:22:07 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	temp->value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp->value;
	free(temp);
	return (stack);
}

t_stack	*push(t_stack **stack1, t_stack *stack2)
{
	if (*stack1 == NULL)
		*stack1 = create(stack2->value, NULL);
	else
		*stack1 = add_begin(*stack1, stack2->value);
	stack2 = del_begin(stack2);
	return (stack2);
}

t_stack	*rotate(t_stack *stack)
{
	int i;

	i = stack->value;
	stack = add_end(stack, i);
	stack = del_begin(stack);
	return (stack);
}

t_stack	*rev_rotate(t_stack *stack)
{
	int i;
	t_stack *temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	i = temp->value;
	stack = add_begin(stack, i);
	stack = del_end(stack);
	return (stack);
}
