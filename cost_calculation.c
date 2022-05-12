/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:20:57 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/12 19:21:10 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    calculate_cost1(t_stack **head_a, t_stack **head_b, t_stack *element)//rotate a, rev-rot b
{
    t_stack *a;
    t_stack *b;
    int     moves;

    a = *head_a;
    b = *head_b;
    moves = 0;
    if (b->content == element->content || ft_lstlast(b) == element->content)
        
    while (b->content == element->content)
    {

    }
}
