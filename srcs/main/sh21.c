/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:59:55 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/06 10:59:57 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include <term.h>
#include <curses.h>
#include <fcntl.h>

void handle_windowsize(int nb)
{
	t_21sh *data;

	data = get_data_21sh();
	ioctl(0, TIOCGWINSZ, &data->winsize);
	dprintf(data->debug_tty, "\rwindow_size = |%d * %d|\n", data->winsize.ws_row, data->winsize.ws_col);
}

int			my_putchar(int c)
{
	static int	fd = 0;
	t_21sh *data;

	data = get_data_21sh();
	if (!fd)
		fd = open("/dev/tty", O_RDWR);
	dprintf(data->debug_tty, "tty regular = %d, debug = %d\n", data->debug_tty, fd);
	if (!isatty(fd))
	{
		ft_putstr("/dev/tty is not a valid tty.\n");
		exit(EXIT_FAILURE);
	}
	if (c == -1)
	{
		close(fd);
		return (c);
	}
	write(fd, &c, 1);
	return (c);
}

void behaviour(t_21sh *data)
{
	int i;
	t_function_call *find;

	i = 0;
	find = data->input.function_call;
	dprintf(data->debug_tty, "find[i].key = %llu, ARROW_RIGHT = %llu\n", find[0].key, ARROW_RIGHT);
	while ((find[i]).key)
	{
		if (data->input.read == find[i].key)
		{
			find[i].f(data);
			break;
		}
		dprintf(data->debug_tty, "i = %d, find[i].key = %llu\n", i,
		find[i].key);
		i++;
	}
	// if (data->input.read == ARROW_UP)
	// 	tputs(tgoto(tgetstr("up", NULL), 0, 0), 1, my_putchar);
	// else if (data->input.read == ARROW_DOWN)
	// 	tputs(tgoto(tgetstr("do", NULL), 0, 0), 1, my_putchar);
	// else if (data->input.read == ARROW_LEFT)
	// 	tputs(tgoto(tgetstr("le", NULL), 0, 0), 1, my_putchar);
	// else if (data->input.read == ARROW_RIGHT)
	// 	tputs(tgoto(tgetstr("nd", NULL), 0, 0), 1, my_putchar);
	// else
	// 	my_putchar((int)nb);
}



int     get_input(void)
{
	t_21sh	*data;
	char *buffer;

	data = get_data_21sh();
	buffer = (char*)&data->input.read;
	while (read(0, &data->input.read, 8))
	{
		dprintf(data->debug_tty, "\rbuff = [%d][%d][%d][%d][%d][%d][%d][%d], %llu\n", buffer[0],
		buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], data->input.read);
		behaviour(data);
		data->input.read = 0;
	}
	return (0);
}

void	setdebug(void)
{
	t_21sh *data;

	data = get_data_21sh();
	data->debug_tty = open("/dev/ttys000", O_RDWR);
}

int main(void)
{
	set_terminal();
	setdebug();
	signal(SIGWINCH, handle_windowsize);
	while (1)
	{
		get_input();
	}
	return (0);
}

// Nb arg max : https://stackoverflow.com/questions/19354870/bash-command-line-and-input-limit
//DESCRIPTION
     // The isatty() function tests whether  fildes,  an  open  file
     // descriptor, is associated with a terminal device.

// It is safe to use tgoto for commands other than `cm' only if you have stored zero in BC and UP.

// pourquoi `le' ne fonctionne qu'une seule fois?
