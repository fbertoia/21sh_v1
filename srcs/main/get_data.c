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
	data->input.function_call = (t_function_call[2]){
		{ARROW_RIGHT, ft_arrow_right},
		{0, NULL}
	};
}


t_21sh	*get_data_21sh(void)
{
	static t_21sh data;

	if (!data.input.function_call)
		function_call_initialize(&data);
	return (&data);
}
