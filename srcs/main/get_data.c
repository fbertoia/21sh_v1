/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:50:14 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/12 11:50:16 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void 	function_call_initialize(t_21sh *data)
{
	static t_function_call ptr[] = (t_function_call[])
	{
		{ARROW_RIGHT, ft_arrow_right},
		{0, NULL}
	};
	data->input.function_call = ptr;
}

void 	buf_initialize(t_21sh *data)
{
	data->input.buf_size = BUFF_SIZE_21SH;
	data->input.buf = ft_strnew(BUFF_SIZE_21SH);
}

t_21sh	*get_data_21sh(void)
{
	static t_21sh data;

	if (!data.input.function_call)
		function_call_initialize(&data);
	if (!data.input.buf)
		buf_initialize(&data);
	return (&data);
}
