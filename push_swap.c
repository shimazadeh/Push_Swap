/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:49:59 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/24 15:50:03 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef struct s_list
{
    int content;
    struct s_list *next;

}t_list;

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	length;

	length = 0;
	if (s)
		length = ft_strlen(s);
	if (length < len)
		dst = (char *) malloc (sizeof(char) * (length + 1));
	else
		dst = (char *) malloc (sizeof(char) * (len + 1));
	if (s == NULL || dst == NULL)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && j < ft_strlen(s))
		dst[i++] = s[j++];
	dst[i] = '\0';
	return (dst);
}

void    parsing(t_list *tab, char *arg) 
{
    int i;
    int j;
    char    *buffer;

    i = 0;
    while (arg[i])
    {
        j = i;
        while (!ft_isdigit(arg[j]))
            j++;
        buffer = ft_substr(arg, i , j- i + 1);
        tab->content = buffer;
        tab->next = 
        i = j + 1;
    }
}


int main(int argc, char **argv)
{
    t_list *tab;
    int i;

    if (argc == 1)
        return (0);
    tab = (t_list)malloc(sizeof(t_list));
    parsing(tab, argv[1]);
        
    printf("first letter is: %s\n", argv[1]);
    printf("second letter is: %s\n", argv[2]);
}