/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:57:39 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/12 13:57:40 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_arrow_right(t_21sh *data)
{
	dprintf(data->debug_tty, "arrow_right launched\n");
	tputs(tgoto(tgetstr("nd", NULL), 0, 0), 1, my_putchar);
}

// if (data->input.read == ARROW_UP)
// 	tputs(tgoto(tgetstr("up", NULL), 0, 0), 1, my_putchar);
// else if (data->input.read == ARROW_DOWN)
// 	tputs(tgoto(tgetstr("do", NULL), 0, 0), 1, my_putchar);
// else if (data->input.read == ARROW_LEFT)
// 	tputs(tgoto(tgetstr("le", NULL), 0, 0), 1, my_putchar);
// else if (data->input.read == ARROW_RIGHT)
//
// else
// 	my_putchar((int)nb);
