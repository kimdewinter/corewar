/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_args_checks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 14:44:29 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int	is_valid_numerical_arg(const char *str)
{
	size_t	i;
	size_t	len;

	if (str[0] == '\0' || str[0] == 0)
		return (0);
	len = ft_strlen(str);
	if (len >= 2 && str[0] == '-' && (str[1] == '\0' || str[1] == 0))
		return (0);
	i = ((str[0] == '-') ? 1 : 0);
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			check_dir_arg(t_data *data, t_ins *ins, char *arg)
{
	int		res;

	if (is_valid_numerical_arg(arg) == 0)
		return (asm_error(ARG_ERR, INV_ARG, data->num_lines));
	res = ft_atoi(arg);
	ins->args_type[ins->index] = DIR_CODE;
	ins->arguments[ins->index] = res;
	ins->ins_size += get_arg_size(ins, DIR_CODE);
	if (arg_type_validation(ins->opcode, DIR_CODE, ins->index) == 0)
		return (asm_error(ARG_ERR, INV_TYPE_ARGS, data->num_lines));
	return (SUCCESS);
}

int			check_ind_arg(t_data *data, t_ins *ins, char *arg)
{
	int		res;

	if (is_valid_numerical_arg(arg) == 0)
		return (asm_error(ARG_ERR, INV_ARG, data->num_lines));
	res = ft_atoi(arg);
	ins->args_type[ins->index] = IND_CODE;
	ins->arguments[ins->index] = res;
	ins->ins_size += get_arg_size(ins, IND_CODE);
	if (arg_type_validation(ins->opcode, IND_CODE, ins->index) == 0)
		return (asm_error(ARG_ERR, INV_TYPE_ARGS, data->num_lines));
	return (SUCCESS);
}

int			check_dir_lbl(t_data *data, t_ins *ins, char *arg)
{
	t_label *label;

	label = find_matching_label(data, arg);
	ins->args_type[ins->index] = DIR_CODE;
	if (label == NULL)
	{
		if (insert_placeholder(data, ins, arg) == ERROR)
			return (ERROR);
	}
	else
	{
		ins->arguments[ins->index] = label->position - ins->position;
		ins->args_type[ins->index] = DIR_CODE;
	}
	ins->ins_size += get_arg_size(ins, DIR_CODE);
	if (arg_type_validation(ins->opcode, DIR_CODE, ins->index) == 0)
		return (asm_error(ARG_ERR, INV_TYPE_ARGS, data->num_lines));
	return (SUCCESS);
}

int			check_ind_lbl(t_data *data, t_ins *ins, char *arg)
{
	t_label	*label;

	ins->args_type[ins->index] = IND_CODE;
	label = find_matching_label(data, arg);
	if (label == NULL)
	{
		if (insert_placeholder(data, ins, arg) == ERROR)
			return (ERROR);
	}
	else
	{
		ins->arguments[ins->index] = label->position - ins->position;
		ins->args_type[ins->index] = IND_CODE;
	}
	ins->ins_size += get_arg_size(ins, IND_CODE);
	if (arg_type_validation(ins->opcode, IND_CODE, ins->index) == 0)
		return (asm_error(ARG_ERR, INV_TYPE_ARGS, data->num_lines));
	return (SUCCESS);
}
