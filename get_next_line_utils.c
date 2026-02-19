/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:57:55 by idait-el          #+#    #+#             */
/*   Updated: 2025/11/24 20:07:55 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	char_to_find;

	if (!s)
		return (NULL);
	char_to_find = (unsigned char)c;
	while (*s)
	{
		if (*s == char_to_find)
			return ((char *)s);
		s++;
	}
	if (*s == char_to_find)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	char	*dup_str;
	size_t	i;

	if (!s1)
		return (NULL);
	dup_str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup_str[i] = s1[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}

char	*ft_strdup_nl(const char *s1)
{
	char	*dup_str;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	dup_str = malloc((len + 2) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup_str[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		dup_str[i] = '\n';
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
