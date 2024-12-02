/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:24:22 by mouad             #+#    #+#             */
/*   Updated: 2024/12/02 18:31:27 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*get_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = (char *)malloc((i + 2) * sizeof(char));
	else
		line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		line[i++] = stash[i];
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

int	check_bytes(ssize_t bytes)
{
	if (bytes == 0)
		return (0);
	if (bytes == -1)
		return (-1);
	return (1);
}

static int	read_and_store(int fd, char **stash)
{
	char		*buffer;
	ssize_t		bytes_read;
	char		*temp_stash;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (check_bytes(bytes_read) != 1)
		{
			free(buffer);
			return (-1);
		}
		if (bytes_read == 0)
			return (0);
		buffer[bytes_read] = '\0';
		temp_stash = ft_strjoin(*stash, buffer);
		if (!temp_stash)
		{
			free(buffer);
			return (-1);
		}
		free(*stash);
		*stash = temp_stash;
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_store(fd, &stash);
	if (bytes_read == 0 && !stash)
		return (NULL);
	if (bytes_read == -1 || !stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}
