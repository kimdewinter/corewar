/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_label.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 21:40:48 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int		create_label(t_label **label, char *label_name, t_data *data)
{
	*label = (t_label *)ft_memalloc(sizeof(t_label));
	if (*label == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	(*label)->name = ft_strdup(label_name);
	if ((*label)->name == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	(*label)->position = data->total_size;
	(*label)->next = NULL;
	(*label)->tail = NULL;
	return (SUCCESS);
}
