/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:13:36 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/08 16:13:37 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include <curses.h>
#include <term.h>

void		set_terminal(void)
{
	struct termios term;
	char           *name_term;
	char  *bp;

	bp = NULL;
	if ((name_term = getenv("TERM")) == NULL)
		exit(1);
	if (tgetent(bp, name_term) == ERR)
		exit(2);
	if (tcgetattr(STDIN_FILENO, &term) == -1)
		exit(3);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(VMIN);
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		exit(4);
	
	// if ((term.c_lflag & ~(ICANON)) != ~(ICANON)
	// 	|| (term.c_lflag & ~(ECHO)) != ~(ECHO)
	// 		|| (term.c_lflag & ~(VMIN)) != ~(VMIN)
	// 			|| term.c_cc[VTIME] != 0)
	// 	exit(5);
}
