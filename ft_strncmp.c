/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:26:57 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/02 09:46:38 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (s1[k] != s2[k])
			return ((unsigned char)s1[k] - (unsigned char)s2[k]);
		if (s1[k] == '\0')
			return (0);
		k++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	k;

	k = 0;
	while (s1[k] || s2[k])
	{
		if (s1[k] != s2[k])
			return ((unsigned char)s1[k] - (unsigned char)s2[k]);
		if (s1[k] == '\0' || s2[k] == '\0')
			return (0);
		k++;
	}
	return (0);
}