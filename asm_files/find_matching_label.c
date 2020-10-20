/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_matching_label.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:44:19 by rheuts        #+#    #+#                 */
/*   Updated: 2020/09/17 18:44:31 by rheuts        ########   odam.nl         */
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
