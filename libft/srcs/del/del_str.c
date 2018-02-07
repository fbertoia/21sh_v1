/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:08:43 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/07 16:08:45 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	delstr(int nb_args, ...)
{
	va_list	ap;
	int		i;
	char	**tmp;

	i = 0;
	va_start(ap, nb_args);
	while (i < nb_args)
	{
		tmp = va_arg(ap, char **);
		ft_memdel((void**)tmp);
		i++;
	}
	va_end(ap);
}
