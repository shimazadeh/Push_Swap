/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:13:27 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/28 01:13:36 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stack **head_a)
{
	t_stack	*a;
	t_stack	*a_iteri;

	a = *head_a;
	while (a)
	{
		a_iteri = a->next;
		while (a_iteri)
		{
			if (a->content > a_iteri->content)
				return (1);
			a_iteri = a_iteri->next;
		}
		a = a->next;
	}
	return (0);
}

int	calculate_cost_method1(int index_a, int index_b)
{//RR + RA/RB
	if (index_a < index_b)
		return (index_b);
	return (index_a);
}

int	calculate_cost_method2(int index_a, int index_b, t_stack **a, t_stack **b)
{// RRR +RRA/RRB
	int		i;
	t_stack	*node_a;
	t_stack	*node_b;

	i = 0;
	node_a = *a;
	node_b = *b;
	while (i < index_a)
	{
		node_a = node_a->next;
		i++;
	}
	i = 0;
	while (i < index_b)
	{
		node_b = node_b->next;
		i++;
	}
	if (ft_lstsize(node_a) < ft_lstsize(node_b))
		return (ft_lstsize(node_b));
	return (ft_lstsize(node_a));
}

int	calculate_cost_method3(int index_a, int index_b, t_stack **head_b)
{// RA + RRB
	int		j;
	t_stack	*node;

	node = *head_b;
	j = 0;
	while (j < index_b)
	{
		node = node->next;
		j++;
	}
	return (index_a + ft_lstsize(node));
}

int	calculate_cost_method4(int index_a, int index_b, t_stack **head_a)
{// RB + RRA
	int		j;
	t_stack	*node;

	node = *head_a;
	j = 0;
	while (j < index_a)
	{
		node = node->next;
		j++;
	}
	return (index_b + ft_lstsize(node));
}
