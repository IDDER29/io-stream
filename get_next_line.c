/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:03:43 by idait-el          #+#    #+#             */
/*   Updated: 2025/11/24 20:07:34 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_line_from_stash(char **stash_ptr)
{
	char	*line_to_return;
	char	*remainder;

	line_to_return = ft_strdup_nl(*stash_ptr);
	remainder = ft_strdup(ft_strchr(*stash_ptr, '\n') + 1);
	free(*stash_ptr);
	*stash_ptr = remainder;
	return (line_to_return);
}

static char	*handle_final_line(char **stash_ptr)
{
	char	*line_to_return;

	if (*(*stash_ptr) == '\0')
	{
		free(*stash_ptr);
		*stash_ptr = NULL;
		return (NULL);
	}
	line_to_return = *stash_ptr;
	*stash_ptr = NULL;
	return (line_to_return);
}

static int	read_and_join(int fd, char **stash)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	rd_bytes = read(fd, buffer, BUFFER_SIZE);
	if (rd_bytes == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[rd_bytes] = '\0';
	*stash = ft_strjoin(*stash, buffer);
	free(buffer);
	return (rd_bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			rd_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		rd_bytes = read_and_join(fd, &stash);
		if (rd_bytes == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			return (create_line_from_stash(&stash));
		if (rd_bytes == 0)
			return (handle_final_line(&stash));
	}
}
