/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_partII.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:50:47 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/10 12:50:49 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both_lst(t_stack **a, t_stack **b)
{
	swap(a, "");
	swap(b, "");
	printf("ss\n");
	return ;
}

void	rotate_both_lst(t_stack **a, t_stack **b)
{
	rotate(a, "");
	rotate(b, "");
	printf("rr\n");
	return ;
}

void	rev_rotate_both_lst(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	printf("rrr\n");
	return ;
}
