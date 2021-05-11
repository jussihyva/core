/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_readline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 00:32:25 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:13:33 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

static int	eof(char **mem, char **line, int r)
{
	if (r == 0 && *mem[0] != '\0')
	{
		*line = s_dup(*mem);
		s_del(&*mem);
		return (2);
	}
	else
	{
		s_del(&*mem);
		return (0);
	}
}

static int	readbuf(char **mem, char **line, int fd)
{
	char			*tmp;
	char			buff[READLINE_MAX_BUFF + 1];
	int				r;

	r = read(fd, buff, READLINE_MAX_BUFF);
	while (r)
	{
		buff[r] = '\0';
		tmp = s_join(*mem, buff);
		s_del(&*mem);
		if (!(s_chr(buff, '\n')))
			*mem = tmp;
		else
		{
			*line = s_cdup(tmp, '\n');
			*mem = s_csub(buff, '\n');
			free(tmp);
			return (1);
		}
		r = read(fd, buff, READLINE_MAX_BUFF);
	}
	if (r == -1)
		return (-1);
	return (eof(&*mem, &*line, r));
}

int	s_readline(const int fd, char **line)
{
	static char		*mem[READLINE_MAX_FD];
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!mem[fd])
		mem[fd] = s_new(0);
	if ((s_chr(mem[fd], '\n')))
	{
		*line = s_cdup(mem[fd], '\n');
		tmp = s_csub(mem[fd], '\n');
		s_del(&mem[fd]);
		mem[fd] = tmp;
		return (1);
	}
	return (readbuf(&mem[fd], &*line, fd));
}

/*
**  ----------------------------------------------------------------------------
**
**	S_READLINE
**
**	Read a line from a file and put the line into the string `line` passed
**	by reference. Subsequent calls to the function will get the next line
**	untill end of file or if file descriptor is closed.
**
**  ----------------------------------------------------------------------------
*/
