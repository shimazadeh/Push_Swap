/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:14:22 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/12 19:14:24 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    method1(t_stack **head_a, t_stack **head_b, int flag)
{
    rotate_both_lst(head_a, head_b);
    if (flag == 1)
        rotate(head_a);
    else
        rotate(head_b);
    return ;
}

void    method2(t_stack **head_a, t_stack **head_b, int flag)
{
    rev_rotate_both_lst(head_a, head_b);
    if (flag == 1)
        reverse_rotate(head_a);
    else
        reverse_rotate(head_b);
    return ;
}

void    method3(t_stack **head_a, t_stack **head_b)
{
    rotate(head_a);
    reverse_rotate(head_b);
    return ;
}

void    method4(t_stack **head_a, t_stack **head_b)
{
    rotate(head_b);
    reverse_rotate(head_a);
    return ;
}
