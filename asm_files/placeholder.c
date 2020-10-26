/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   placeholder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:08:55 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static void	ft_placeholder_addend(t_ph **ph_lst, t_ph *new)
{
	t_ph *temp;

	temp = *ph_lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	temp->next->prev = temp;
}

static void	add_placeholder_tail(t_ph **ph_lst)
{
	t_ph *tail;

	tail = *ph_lst;
	while (tail && tail->next != NULL)
		tail = tail->next;
	if (tail)
	{
		if (tail && tail->prev)
			tail->prev = tail->prev;
		else
			tail->prev = NULL;
		(*ph_lst)->tail = tail;
	}
}

static t_ph	*create_placeholder(char *label_name, size_t ins_id,
int arg_index)
{
	t_ph *placeholder;

	placeholder = (t_ph *)ft_memalloc(sizeof(t_ph));
	placeholder->ins_id = ins_id;
	placeholder->arg_id = arg_index;
	placeholder->label_name = ft_strdup(label_name);
	placeholder->next = NULL;
	placeholder->tail = NULL;
	return (placeholder);
}

int			insert_placeholders(t_ph **ph_lst, char *label_name,
size_t ins_id, int arg_index)
{
	t_ph *new;

	new = create_placeholder(label_name, ins_id, arg_index);
	if (new == NULL)
		return (-1);
	if (*ph_lst == NULL)
	{
		*ph_lst = new;
		new->prev = NULL;
		new->tail = new;
		new->tail->next = NULL;
		return (1);
	}
	ft_placeholder_addend(ph_lst, new);
	add_placeholder_tail(ph_lst);
	return (1);
}

int			insert_placeholder(t_data *data, t_ins *ins, char *label)
{
	t_ph *new;

	new = create_placeholder(label, ins->ins_id, ins->index);
	if (new == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (data->ins_placeholders == NULL)
	{
		data->ins_placeholders = new;
		new->prev = NULL;
		new->tail = new;
		new->tail->next = NULL;
		return (SUCCESS);
	}
	ft_placeholder_addend(&data->ins_placeholders, new);
	add_placeholder_tail(&data->ins_placeholders);
	return (SUCCESS);
}
