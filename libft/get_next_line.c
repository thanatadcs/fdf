/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:19:01 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/09 16:30:19 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Guarantee that storage_ptr and *storage_ptr are not null and contains \n.
// newline_index guaranteet to be positive.
// If failed, free storage.
static void	update_storage(char **storage_ptr, ssize_t newline_index)
{
	char	*new_storage;
	char	*storage;
	size_t	storage_len;
	ssize_t	i;

	storage = *storage_ptr;
	storage_len = 0;
	while (storage[storage_len])
		storage_len++;
	new_storage = malloc((storage_len - (size_t)newline_index - 1 + 1) \
	* sizeof(char));
	if (new_storage == 0)
	{
		free(storage);
		*storage_ptr = 0;
		return ;
	}
	i = 0;
	while (storage[newline_index + (++i)])
		new_storage[i - 1] = storage[newline_index + i];
	new_storage[i - 1] = '\0';
	*storage_ptr = new_storage;
	free(storage);
}

// Guarantee that storage_ptr and *storage_ptr are not null and contains \n.
// newline_index guaranteet to be positive.
// If failed, free storage.
static char	*get_newline_update_storage(char **storage_ptr, \
ssize_t newline_index)
{
	char	*to_return;
	char	*storage;
	ssize_t	i;

	storage = *storage_ptr;
	to_return = malloc((newline_index + 1 + 1) * sizeof (char));
	if (to_return == 0)
	{
		free(storage);
		*storage_ptr = 0;
		return (0);
	}
	i = -1;
	while (++i <= newline_index)
		to_return[i] = storage[i];
	to_return[i] = '\0';
	update_storage(storage_ptr, newline_index);
	return (to_return);
}

static void	read_line(char **storage_ptr, int fd)
{
	ssize_t		read_num;
	char		*old_storage;
	char		*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == 0)
		return ;
	read_num = read(fd, buf, BUFFER_SIZE);
	while (read_num != 0)
	{
		if (read_num == -1)
		{
			free(*storage_ptr);
			*storage_ptr = 0;
			break ;
		}
		buf[read_num] = '\0';
		old_storage = *storage_ptr;
		*storage_ptr = my_strjoin(*storage_ptr, buf);
		free(old_storage);
		if (get_char_index(*storage_ptr, '\n') >= 0)
			break ;
		read_num = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*to_return;
	ssize_t		newline_index;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	to_return = 0;
	read_line(&storage, fd);
	newline_index = get_char_index(storage, '\n');
	if (newline_index >= 0)
		to_return = get_newline_update_storage(&storage, newline_index);
	else if (storage != 0)
	{
		if (*storage == '\0')
			free(storage);
		else
			to_return = storage;
		storage = 0;
	}
	return (to_return);
}
