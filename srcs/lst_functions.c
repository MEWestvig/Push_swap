/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:14:05 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/29 12:20:44 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create(int value, t_stack* next, int sorted)
{
	t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error(2);
    new->value = value;
	new->sorted = sorted;
    new->next = next;
    return (new);
}

t_stack	*add_begin(t_stack *head, int value)
{
    t_stack	*new;

	new = create(value, head, head->sorted);
	head = new;
	return (head);
}

t_stack	*del_begin(t_stack *head)
{
	t_stack *front;

	if (head == NULL)
		return (NULL);
	front = head;
	head = head->next;
	front->next = NULL;
	if (front == head)
		head = NULL;
	free(front);
	return (head);
}

t_stack	*add_end(t_stack *head, int value)
{
	t_stack *cursor;
	t_stack *new;

	cursor = head;
	new = create(value, NULL, head->sorted);
	while(cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = new;
	return (head);
}

t_stack	*del_end(t_stack *head)
{
	t_stack	*cursor;
	t_stack	*back;

	if (head == NULL)
		return (NULL);
	cursor = head;
    back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
    if (back != NULL)
        back->next = NULL;
	if (cursor == head)
		head = NULL;
	free(cursor);
	return (head);
}
