/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:39:51 by mwestvig          #+#    #+#             */
/*   Updated: 2018/09/05 12:16:34 by mwestvig         ###   ########.fr       */
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
		{
			if (stack)
			{
				*a_head = swap(*a_head);
				ft_putendl("sa");
			}
			else
			{
				*b_head = swap(*b_head);
				ft_putendl("sb");
			}
		}
		else
		{
			if (stack)
			{
				*a_head = rotate(*a_head);
				ft_putendl("ra");
				*a_head = swap(*a_head);
				ft_putendl("sa");
				*a_head = rev_rotate(*a_head);
				ft_putendl("rra");
			}
			else
			{
				*b_head = rotate(*b_head);
				ft_putendl("rb");
				*b_head = swap(*b_head);
				ft_putendl("sb");
				*b_head = rev_rotate(*b_head);
				ft_putendl("rrb");
			}
		}
		sort3(a_head, b_head, size, stack);
	}
}

int		pusher(t_stack **a_head, t_stack **b_head, int stack, int pivot)
{
	if ((stack && (*a_head)->value < pivot) || (!stack && (*b_head)->value >= pivot))
	{
		if (!stack)
		{
			*b_head = push(a_head, *b_head);
			ft_putendl("pa");
		}
		else
		{
			*a_head = push(b_head, *a_head);
			ft_putendl("pb");
		}
		return (1);
	}
	else
	{
		if (!stack)
		{
			*b_head = rotate(*b_head);
			ft_putendl("rb");
		}
		else
		{
			*a_head = rotate(*a_head);
			ft_putendl("ra");
		}
	}
	return (0);
}

int		stacksize(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	size = 0;
	temp = stack;
	while (temp && temp->sorted != 1)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	quicksort(t_stack **a_head, t_stack **b_head, int size, int stack, int n)
{
	int	pivot;
	int	i;
	int	reset;

	reset = 0;
	i = 0;
	pivot = median((stack) ? *(a_head) : *(b_head), size);
	if (is_sorted((stack) ? *(a_head) : *(b_head), size, stack))
		return ;
	while (size > 3 && i < (size / 2) + (size % 2 && !stack) && ++reset)
		i += pusher(a_head, b_head, stack, pivot);
	while ((!n) && (reset--) - i)
	{
		if (!stack)
		{
			(*b_head) = rev_rotate((*b_head));
			ft_putendl("rrb");
		}
		else
		{
			(*a_head) = rev_rotate((*a_head));
			ft_putendl("rra");
		}
	}
	if (i && !stack)
		quicksort(&(*a_head), &(*b_head), i, !stack, 0);
	if (size - i <= 3)
		sort3(&(*a_head), &(*b_head), size - i, stack);
	else
		quicksort(&(*a_head), &(*b_head), size - i, stack, (n == 2) ? 1 : n);
	if (i && stack)
		quicksort(&(*a_head), &(*b_head), i, !stack, (n == 2) ? 1 : 0);
	while (i--)
	{
		if (stack)
		{
			(*b_head) = push(a_head, (*b_head));
			ft_putendl("pa");
		}
		else
		{
			*a_head = push(b_head, (*a_head));
			ft_putendl("pb");
		}
	}
}
