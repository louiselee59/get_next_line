/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:38:21 by lolee             #+#    #+#             */
/*   Updated: 2019/07/03 19:46:47 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# define BUFF_SIZE	10
# define DEBUG

typedef struct			s_fd
{
	int					fd;
	int					completed;
	int					idx;
	char				*buffer;
	int					len;
	struct s_fd			*next;
}						t_fd;

int						ft_read_dsk(t_fd *fd);
int						ft_read_buf(t_fd *fd, char **line);
int						get_next_line(const int fd, char **line);

#endif
