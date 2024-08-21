/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:44:55 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/03 13:50:56 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_strdup(char *s1, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

void	gnl_ft_free(t_list **lst, int fd)
{
	t_list	*cur;
	t_list	*pre;

	pre = *lst;
	cur = *lst;
	if ((*lst)->fd == fd)
	{
		*lst = cur->next;
		cur->next = NULL;
		free(cur);
		return ;
	}
	while (cur->next)
	{
		if (cur->fd == fd)
		{
			pre->next = cur->next;
			cur->next = NULL;
			free(cur);
			return ;
		}
		pre = cur;
		cur = cur->next;
	}
}

char	*gnl_ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*temp;
	size_t	s1_len;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		return (gnl_ft_strdup(s2, s2_len));
	s1_len = gnl_ft_strlen(s1);
	temp = (char *)malloc(s1_len + s2_len + 1);
	if (!temp)
		return (NULL);
	while (s1[i++])
		temp[i - 1] = s1[i - 1];
	free(s1);
	j = 0;
	while (s2[j])
	{
		temp[i + j - 1] = s2[j];
		j++;
	}
	temp[i + j - 1] = 0;
	return (temp);
}

t_list	*gnl_ft_find_fd(t_list *lst, int fd)
{
	t_list	*temp;

	temp = lst;
	while (lst)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
