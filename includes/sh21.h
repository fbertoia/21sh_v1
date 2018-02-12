/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <fbertoia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:36:55 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/22 02:11:35 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/stat.h>
# include "libft.h"
# include <ft_printf.h>
# include <errno.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>
# include <sys/ioctl.h>
#include <term.h>
#include <curses.h>
#include <fcntl.h>
/*
** buf is where's hold the string written in input
** cur_pos means cursor position
*/
typedef struct winsize t_winsize;
typedef struct s_21sh t_21sh;
typedef struct s_function_call
{
	unsigned long long key;
	void (*f)(struct s_21sh*);
}				t_function_call;

typedef struct s_buf
{
	unsigned long long read;
	char *buf;
	int cur_pos;
	int buf_size;
	t_function_call *function_call;
}				t_buf;

struct	s_21sh
{
	// struct sh *next;
	int 	debug_tty;
	t_winsize winsize;
	t_buf	input;
};

#define BUFF_SIZE_21SH 5
#define ARROW_RIGHT (unsigned long long)4414235
#define ARROW_LEFT (unsigned long long)4479771
#define ARROW_UP (unsigned long long)4283163
#define ARROW_DOWN (unsigned long long)4348699
#define DEL_BACKWARD 127
#define DEL_FORWARD 2117294875
#define CLEAR_SCREEN 12
#define GO_TO_BEG_OF_LINE 1
#define GOTO_END_OF_LINE 5

#define DEL_FROM_CURSOR_TO_END 11
#define DEL_LINE 21
#define DEL_WORD_BACKWARD 23
#define CANCEL 24
#define SUBSTITUTE 26
#define ESC 27
#define SPACE 32


void	set_terminal(void);
t_21sh	*get_data_21sh(void);

void ft_arrow_right(t_21sh *data);
void 	print_char(t_21sh *data);
int			my_putchar(int c);

void	setdebug(void);

#endif
