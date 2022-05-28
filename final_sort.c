/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:03:02 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/28 00:03:12 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_costs_index(t_stack **head_b, t_ind *index)
{
	t_stack	*b;

	b = *head_b;
	while (b)
	{
		b->cost1 = -1;
		b->cost2 = -1;
		b->cost3 = -1;
		b->cost4 = -1;
		b = b->next;
	}
	index->lowest_cost = 2147483647;
	index->method_num = -1;
	index->index_a = -1;
	index->index_b = -1;
	return ;
}

void	final_sort_odd(t_stack **head_a, int position, int len)
{
	int	count;

	count = 0;
	if (position > len / 2)
	{
		while (count != (len - position))
		{
			reverse_rotate(head_a, "rra");
			count++;
		}
	}
	else
	{
		while (count != position)
		{
			rotate(head_a, "ra");
			count++;
		}
	}
	return ;
}

void	final_sort_even(t_stack **head_a, int position, int len)
{
	int	count;

	count = 0;
	if (position >= len / 2)
	{
		while (count != (len - position))
		{
			count++;
			reverse_rotate(head_a, "rra");
		}
	}
	else
	{
		while (count != position)
		{
			rotate(head_a, "ra");
			count++;
		}
	}
	return ;
}

void	final_check(t_stack **head_a, t_struct *tab)
{
	t_stack	*a;
	int		position;
	int		len;

	a = *head_a;
	position = 0;
	len = ft_lstsize(*head_a);
	if ((a)->content != tab->min)
	{
		while ((a) && (a)->content != tab->min)
		{
			position++;
			(a) = (a)->next;
		}
		if (len % 2 != 0)
			final_sort_odd(head_a, position, len);
		else
			final_sort_even(head_a, position, len);
	}
	return ;
}
