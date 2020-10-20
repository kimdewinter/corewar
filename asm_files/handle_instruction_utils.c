/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_instruction_utils.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:54:14 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:54:16 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

void		ft_instruction_addend(t_ins **ins_lst, t_ins *new)
{
	t_ins *temp;

	temp = *ins_lst;
	if (temp == NULL)
	{
		*ins_lst = new;
		new->prev = NULL;
		new->tail = new;
		new->tail->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		temp->next->prev = temp;
	}
}

int			create_instr(t_ins **new, t_data *data, char *op)
{
	*new = ft_memalloc(sizeof(t_ins));
	if (*new == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, data->num_lines));
	(*new)->ins_id = data->ins_id;
	data->ins_id++;
	(*new)->position = data->total_size;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	(*new)->index = 0;
	find_opcode_args(*new, op);
	(*new)->ins_size += 1;
	return (SUCCESS);
}
