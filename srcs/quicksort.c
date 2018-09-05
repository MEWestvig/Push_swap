/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:39:51 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/05 15:43:35 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		median(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*temp;
	int		i;
	int		higher;
	int		lower;

	current = stack;
	higher = 0;
	lower = 5;
	while (higher - lower != 0 && higher - lower != -1)
	{
		higher = 0;
		lower = 0;
		i = -1;
		temp = stack;
		while (++i < size)
		{
			higher += (current->value < temp->value);
			lower += (current->value > temp->value);
			temp = temp->next;
		}
		temp = current;
		current = current->next;
	}
	return (temp->value);
}

int		is_sorted(t_stack *stack, int size, int a_b)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = stack;
	while (temp->next && ((a_b && temp->value < temp->next->value) ||
				(!a_b && temp->value > temp->next->value)))
	{
		i++;
		temp = temp->next;
	}
	return (i >= size);
}

void	sort3(t_stack **a_head, t_stack **b_head, int size, int stack)
{
	if (!is_sorted((stack) ? *(a_head) : *(b_head), size, stack))
	{
		if (!is_sorted((stack) ? *(a_head) : *(b_head), 2, stack))
			do_oper(a_head, b_head, (stack) ? "sa" : "sb");
		else
		{
			if (stack)
			{
				do_oper(a_head, b_head, "ra");
				do_oper(a_head, b_head, "sa");
				do_oper(a_head, b_head, "rra");
			}
			else
			{
				do_oper(a_head, b_head, "rb");
				do_oper(a_head, b_head, "sb");
				do_oper(a_head, b_head, "rrb");
			}
		}
		sort3(a_head, b_head, size, stack);
	}
}

int		pusher(t_stack **a, t_stack **b, int stack, int pivot)
{
	if ((stack && (*a)->value < pivot) || (!stack && (*b)->value >= pivot))
	{
		if (!stack)
			do_oper(a, b, "pa");
		else
			do_oper(a, b, "pb");
		return (1);
	}
	else
	{
		if (!stack)
			do_oper(a, b, "rb");
		else
			do_oper(a, b, "ra");
	}
	return (0);
}

void	quicksort(t_stack ***head, int size, int stack, int n)
{
	int	pivot;
	int	i;
	int	reset;

	reset = 0;
	i = 0;
	pivot = median((stack) ? *(head[0]) : *(head[1]), size);
	if (is_sorted((stack) ? *(head[0]) : *(head[1]), size, stack))
		return ;
	while (size > 3 && i < (size / 2) + (size % 2 && !stack) && ++reset)
		i += pusher(head[0], head[1], stack, pivot);
	while ((!n) && (reset--) - i)
		do_oper(head[0], head[1], (stack) ? "rra" : "rrb");
	if (i && !stack)
		quicksort(&(*head), i, !stack, 0);
	if (size - i <= 3)
		sort3(&(*head[0]), &(*head[1]), size - i, stack);
	else
		quicksort(&(*head), size - i, stack, (n == 2) ? 1 : n);
	if (i && stack)
		quicksort(&(*head), i, !stack, (n == 2) ? 1 : 0);
	while (i--)
		do_oper(head[0], head[1], (stack) ? "pa" : "pb");
}
