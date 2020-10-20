/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   backpatching_args.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:39:26 by rheuts        #+#    #+#                 */
/*   Updated: 2020/09/17 18:40:03 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int		find_labelbkp_arg(t_data *data, t_ins *ins, t_ph *ph_lst)
{
	t_label *temp;
	t_ins	*temp_ins;

	temp = data->label_lst;
	temp_ins = ins;
	while (temp != NULL)
	{
		if (ft_strequ(temp->name, ph_lst->label_name) == 1)
		{
			if (temp_ins->args_type[ph_lst->arg_id] == DIR_CODE)
				temp_ins->arguments[ph_lst->arg_id] = temp->position
				- temp_ins->position;
			else if (temp_ins->args_type[ph_lst->arg_id] == IND_CODE)
				temp_ins->arguments[ph_lst->arg_id] = temp->position
				- temp_ins->position;
			return (SUCCESS);
		}
		temp = temp->next;
	}
	return (ERROR);
}

static t_ins	*return_ins(t_ins **ins_lst, size_t ins_id)
{
	t_ins *temp;

	temp = *ins_lst;
	while (temp != NULL)
	{
		if (temp->ins_id == ins_id)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int				backpatching_ins_lst(t_ph *ph_lst, t_data *data)
{
	int		ret;
	t_ins	*ins;

	while (ph_lst != NULL)
	{
		ins = return_ins(&data->ins_lst, ph_lst->ins_id);
		if (ins == NULL)
			return (asm_error(ARG_ERR, LBL_REF_INV, data->num_lines));
		ins->index = ph_lst->arg_id;
		ret = find_labelbkp_arg(data, ins, ph_lst);
		if (ret == ERROR)
			return (asm_error(ARG_ERR, LBL_REF_INV, data->num_lines));
		ph_lst = ph_lst->next;
	}
	return (SUCCESS);
}
