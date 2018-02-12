/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:55:22 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/12 15:55:24 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void 	add1char_buf(t_buf *input)
{
	char *tmp;

	if (input->buf == NULL)
		return ;
	if (input->buf == NULL)
		input->buf = ft_strnew(input->buf_size);
	if (input->cur_pos == input->buf_size - 1)
	{
		tmp = input->buf;
		input->buf = ft_strnew(input->buf_size + input->buf_size);
		ft_strcpy(input->buf, tmp);
		free(tmp);
		input->buf_size *= 2;
	}
	if (input->buf[input->cur_pos] != 0)
		ft_memmove(input->buf + input->cur_pos, input->buf + input->cur_pos + 1,
			ft_strlen(input->buf + input->cur_pos));
	*input->buf = (char)input->read;
}

void 	print_char(t_21sh *data)
{
	int i;

	i = 0;
	add1char_buf(&data->input);
	while (data->input.buf[i + data->input.cur_pos])
	{
		my_putchar(data->input.buf[i + data->input.cur_pos]);
		i++;
	}
	data->input.cur_pos++;
}


//add a char to a string
// delete a char from a string
//
