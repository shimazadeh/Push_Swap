/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:55:11 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/13 18:22:07 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_update_buffer(char *buffer, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		buffer[j] = buffer[++i];
		j++;
		i++;
	}
	while (i < size && buffer[j])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	while (j < size && buffer[j])
	{
		buffer[j] = '\0';
		j++;
	}
}

void	ft_update_line(char *line, int size)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (i < size && line[i])
	{
		line[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char			buffer[3 + 1];
	char				*line;
	int					byte_read;
	char				*temp;

	if (fd < 0)
		return (NULL);
	line = ft_strndup(buffer, ft_strlen_GNL(buffer));
	byte_read = 1;
	while (byte_read && !ft_gnl_strchr(buffer) && !ft_gnl_strchr(line))
	{
		byte_read = read(fd, buffer, 3);
		if (byte_read < 0)
			return (NULL);
		if (byte_read == 0 && !line)
			return (NULL);
		buffer[byte_read] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	ft_update_buffer(buffer, 3);
	ft_update_line(line, ft_strlen_GNL(line));
	return (line);
}
