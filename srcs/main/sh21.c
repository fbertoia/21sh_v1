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


void handle_windowsize(int nb)
{
	t_21sh *data;

	data = get_data_21sh();
	ioctl(0, TIOCGWINSZ, &data->winsize);
	dprintf(data->debug_tty, "\rwindow_size = |%d * %d|\n", data->winsize.ws_row, data->winsize.ws_col);
}

void behaviour(t_21sh *data)
{
	int i;
	t_function_call *find;

	i = 0;
	find = data->input.function_call;
	if (ft_isprint(data->input.read))
		print_char(data);
	else
	{
		while (find[i].key)
		{
			if (data->input.read == find[i].key)
			{
				find[i].f(data);
				break;
			}
			dprintf(data->debug_tty, "i = %d, find[i].key = %llu, buf_size = %d\n", i,
			find[i].key, data->input.buf_size);
			i++;
		}
	}
}

int     get_input(void)
{
	t_21sh	*data;
	char *buffer;

	data = get_data_21sh();
	buffer = (char*)&data->input.read;
	while (read(0, &data->input.read, 8))
	{
		dprintf(data->debug_tty, "\rread = %llu, buf = %s, cur_pos = %d\n", data->input.read,
		data->input.buf, data->input.cur_pos);
		behaviour(data);
		data->input.read = 0;
	}
	return (0);
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
