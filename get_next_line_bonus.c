/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-kada <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 20:54:15 by mel-kada     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 11:57:52 by mel-kada    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_error_free(char *garbage, char *buffer)
{
	if (garbage)
	{
		free(garbage);
		garbage = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (-1);
}

static int	ft_end_of_reading(char **garbage, char **line, int fd)
{
	if (garbage[fd] != NULL)
		*line = ft_strdup(garbage[fd]);
	else
		*line = ft_strdup("");
	free(garbage[fd]);
	garbage[fd] = NULL;
	return (0);
}

static int	ft_update_buffer(char **garbage, char **line, int fd)
{
	int		index;
	char	*tmp;

	index = ft_check_line(garbage[fd]);
	if (index == -1)
		return (ft_end_of_reading(garbage, line, fd));
	garbage[fd][index] = 0;
	if (!(*line = ft_strdup(garbage[fd])))
		return (ft_error_free(garbage[fd], NULL));
	tmp = garbage[fd];
	if (!(garbage[fd] = ft_strdup(&garbage[fd][index + 1])))
		return (ft_error_free(garbage[fd], NULL));
	free(tmp);
	tmp = NULL;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*garbage[MAX_FD];
	char		*buffer;
	int			end;

	end = 0;
	if (!line || fd < 0 || BUFFER_SIZE < 0 ||
			!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (ft_check_line(garbage[fd]) == -1
			&& (end = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[end] = 0;
		if (!(garbage[fd] = ft_strjoin(garbage[fd], buffer)))
			return (ft_error_free(garbage[fd], buffer));
	}
	free(buffer);
	if (end < 0)
		return (-1);
	return (ft_update_buffer(garbage, line, fd));
}
