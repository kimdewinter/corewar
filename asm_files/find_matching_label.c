/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_matching_label.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:44:19 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

t_label		*find_matching_label(t_data *data, char *arg)
{
	t_label	*label;

	label = data->label_lst;
	while (label)
	{
		if (ft_strequ(label->name, arg) == 1)
			return (label);
		label = label->next;
	}
	return (NULL);
}
