/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:29:32 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/12 18:29:34 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

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
