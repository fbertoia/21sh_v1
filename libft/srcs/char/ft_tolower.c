/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:08:01 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/09 13:08:02 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	char ch;

	ch = (char)c;
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
