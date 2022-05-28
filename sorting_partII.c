/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_partII.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:16:04 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/28 01:16:07 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_position_condition1(t_stack *head_a, t_stack *head_b)
{
	int	i;

	i = 0;
	while (head_a->next && head_a->content < head_a->next->content)
	{
		head_a = head_a->next;
		i++;
	}
	if (head_a->next)
	{
		head_a = head_a->next;
		i++;
		while (head_a && head_b->content > head_a->content)
		{
			head_a = head_a->next;
			i++;
		}
		if (!head_a)
			i = 0;
	}
	else if (!head_a->next && head_b->content < head_a->content)
		i = 0;
	return (i);
}

int	calculate_position_condition2(t_stack *head_a, t_stack *head_b)
{
	int	i;

	i = 0;
	while (head_a->next && head_b->content > head_a->content)
	{
		head_a = head_a->next;
		i++;
	}
	if (!head_a->next && head_b->content > head_a->content)
	i = 0;
	return (i);
}

void	calculate_all_costs(t_stack **head_a, t_stack **head_b, t_ind *index)
{
	int			i;
	int			j;
	t_stack		*b;
	t_stack		*a;

	j = 0;
	b = *head_b;
	while (b)
	{
		i = 0;
		a = *head_a;
		if (b->content < a->content)
			i = calculate_position_condition1(a, b);
		else if (b->content > a->content)
			i = calculate_position_condition2(a, b);
		b->cost1 = calculate_cost_method1(i, j);
		b->cost2 = calculate_cost_method2(i, j, head_a, head_b);
		b->cost3 = calculate_cost_method3(i, j, head_b);
		b->cost4 = calculate_cost_method4(i, j, head_a);
		update_cost_part1(b, index, i, j);
		update_cost_part2(b, index, i, j);
		j++;
		b = b->next;
	}
	return ;
}

void	update_cost_part1(t_stack *head_b, t_ind *index, int i, int j)
{
	if (head_b->cost1 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost1;
		index->method_num = 1;
		index->index_b = j;
		index->index_a = i;
	}
	if (head_b->cost2 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost2;
		index->method_num = 2;
		index->index_b = j;
		index->index_a = i;
	}
	return ;
}

void	update_cost_part2(t_stack *head_b, t_ind *index, int i, int j)
{
	if (head_b->cost3 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost3;
		index->method_num = 3;
		index->index_b = j;
		index->index_a = i;
	}
	if (head_b->cost4 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost4;
		index->method_num = 4;
		index->index_b = j;
		index->index_a = i;
	}
	return ;
}
