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

int			my_putchar(int c)
{
	static int	fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_RDWR);
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

int     check_input()
{
	unsigned char buffer[10];

  while (1)
  {
	int i;
	bzero(buffer, 6);
	i = read(0, buffer, 10);
    buffer[i] = 0;
	printf("character written = [%d][%d][%d][%d]\n", (int)buffer[0], (int)buffer[1], (int)buffer[2], (int)buffer[3]);
	tputs(tgetstr("dl", NULL), 1, my_putchar);
  }
  return (0);
}

int main(void)
{
	int *ptr;

ptr = (int[6]){1, 2, 3, 4, 5 ,6};
printf("ptr[4] = %d\n", ptr[4]);
	int i;
  	struct termios term;
	char           *name_term;
	char  *bp;

	i = 0;

	bp = NULL;
	ft_printf("name_term = %s\n", "debut");
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	ft_printf("%[RED]name_term = %s%[NC]\n", name_term);
	if (tgetent(bp, name_term) == ERR)
		return (-1);
	ft_printf("%[RED]bp = %s%[NC]\n", bp);
		if (tcgetattr(STDIN_FILENO, &term) == -1)
		return (-1);
	ft_printf("%[YEL]sizeof term %ld, term.c_flag = %ld%[NC]\n", sizeof(term), sizeof(term.c_lflag));
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(VMIN);
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	// while (1)
	// {
	// 	check_input();
	// }

	char buf[1024];
	char buf2[30];
	char *ap = buf2;
	char *clearstr, *gotostr, *standstr, *stendstr;

	clearstr = tgetstr("cl", &ap);
gotostr = tgetstr("cm", &ap);
printf("gotostr = %s\n", gotostr);
standstr = tgetstr("so", &ap);
printf("standstr = %s\n", standstr);
stendstr = tgetstr("se", &ap);
printf("stendstr = %s\n", stendstr);
stendstr = tgetstr("kl", &ap);
printf("stendstr = %s\n", stendstr);
// tputs(clearstr, stdout);
// tputs(tgoto(gotostr, 20, 10), stdout);
// printf("Hello, ");
// tputs(standstr, stdout);
// printf("world");
// tputs(stendstr, stdout);
// putchar('!');
	return (0);
}
// Nb arg max : https://stackoverflow.com/questions/19354870/bash-command-line-and-input-limit
//DESCRIPTION
     // The isatty() function tests whether  fildes,  an  open  file
     // descriptor, is associated with a terminal device.
