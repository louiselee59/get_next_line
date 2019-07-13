/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:50:59 by lolee             #+#    #+#             */
/*   Updated: 2019/07/12 19:44:10 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_process_data_without_eol(t_fd *fd, char **line)
{
	char	*line2;
	int		ret;
	char	*tmp;

//printf("2. ENTER, ft->completed = %d\n", fd->completed);
//printf("HERE");
	ret = -20;
	*line = ft_strsub(fd->buffer, fd->idx, fd->len);
	fd->idx += fd->len;
	fd->len = 0;
	if (!fd->completed)
	{
		line2 = NULL;
		ret = ft_read_buf(fd, &line2);
//printf("3.  return from recursion,  ret = %d, ft->completed = %d, *line = \n %s\n", ret, fd->completed,  *line);
		if (ret == 1)
		{
			tmp = ft_strjoin(*line, line2);
//printf("4.  after join,  *line = \n %s\n, line2 = %s\n, tmp= %s\n\n",  *line, line2, tmp);
			free(*line);
			free(line2);
			*line = tmp;
		}
	}
//printf("5.  EXIT, ret = %d, ft->completed = %d, *line = \n %s\n\n", ret, fd->completed,  *line);

}

static void		ft_process_data_with_eol(t_fd *fd, char **line, char *eol)
{
	int		length_of_line;

	length_of_line = eol - &fd->buffer[fd->idx];
	if (length_of_line)
	{
		*line = ft_strsub(fd->buffer, fd->idx, length_of_line);
		fd->idx += length_of_line + 1;
		fd->len -= (length_of_line + 1);

//printf("6.  process data with EOL, length_of_line = %d, fd->completed = %d, fd->idx = %d, fd->len = %d, *line = %s\n", length_of_line, fd->completed, fd->idx, fd->len, *line);
	}
	else
	{
		*line = ft_strnew(0);
		fd->idx += 1;
		fd->len -= 1;
//printf("7.  process data with EOL, length_of_line = %d, fd->completed = %d, fd->idx = %d, fd->len = %d, *line = %s\n", length_of_line, fd->completed, fd->idx, fd->len, *line);
	}
//printf("8.  ******* process data with EOL, length_of_line = %d, fd->completed = %d, fd->idx = %d, fd->len = %d, *line = %s\n", length_of_line, fd->completed, fd->idx, fd->len, *line);
	
}

/*
**	return a line (EOF or '\n')
**	return 1 for empty string,  ex. ....\n\n..
**	return status codes :   1, 0 or -1.  (return bytes read)
*/

int				ft_read_buf(t_fd *fd, char **line)
{
	char	*eol;
	int		ret;

	if (fd->len == 0 && fd->completed)
		return (0);
	if (!fd->buffer)
		ret = ft_read_dsk(fd);
	if (fd->len == 0 && !fd->completed)
		ret = ft_read_dsk(fd);
	if (fd->len > 0)
	{
		eol = ft_strchr(&fd->buffer[fd->idx], '\n');
		if (eol)
			ft_process_data_with_eol(fd, line, eol);
		else
			ft_process_data_without_eol(fd, line);
		return (1);
	}
//printf("1. read_buf return : len = %d, *line = \n %s\n", fd->len, *line);

	return (ret);
}

/*
**  clear buffer,
**  read BUFF_SIZE or EOL, EOF, error
**  update fd->len  -  bytes read
**  set fd->offsetf = 0
**  set fd->completed = 1 if EOF
**  return ret from read(....)
**	 0   - reached EOF
**  -1   - error
**   >0  - bytes read
*/

int				ft_read_dsk(t_fd *fd)
{
	int		ret;

	ret = 0;
	if (!fd->buffer)
		fd->buffer = (char *)ft_memalloc(BUFF_SIZE + 1);
	else
		fd->buffer = (char *)ft_memset(fd->buffer, 0, BUFF_SIZE + 1);
	while (fd->len < BUFF_SIZE && (ret = \
				read(fd->fd, fd->buffer + fd->len, BUFF_SIZE)) > 0)
		fd->len += ret;
	fd->idx = 0;
	if (ret == 0)
		fd->completed = 1;
	return (ret);
}

/*
**  use a static list of t_fd to maintain file descriptors..
**	if t_fd of fd does not exist, it would be created and
**	added to the end of the list.
**  return 1 and null if a 0 size string is read.
**	ex. read between 2 newlines -> \n\n
*/

int				get_next_line(const int fd, char **line)
{
	static t_fd		*fds;
	t_fd			*current_fd;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (fds)
	{
		current_fd = fds;
		while (current_fd->fd != fd && current_fd->next)
			current_fd = current_fd->next;
		if (current_fd->fd != fd)
		{
			current_fd->next = (t_fd *)ft_memalloc(sizeof(t_fd));
			current_fd = current_fd->next;
		}
	}
	else
	{
		fds = (t_fd *)ft_memalloc(sizeof(t_fd));
		current_fd = fds;
	}
	current_fd->fd = fd;
	ret = ft_read_buf(current_fd, line);
//printf("9.  get_next_line,  return :   *line = \n %s\n", *line);
	return (ret);
}
