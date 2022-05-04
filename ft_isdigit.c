/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:08:37 by shabibol          #+#    #+#             */
/*   Updated: 2022/02/28 04:08:49 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c == 43 || c == 45)
		return (1);
	return (0);
}
