/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_args_checks2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:49:29 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int			init_args(char ***args, t_data *data, char *arguments)
{
	if (arguments[ft_strlen(arguments) - 1] == ',')
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	*args = ft_strsplit(arguments, ',');
	if (*args == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (clean_arguments(*args) == ERROR)
		return (end_get_args_ins(asm_error(GEN_ERR, MALL_ERR, 0), *args));
	return (SUCCESS);
}

int			clean_arguments(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		if (remove_spaces(&arguments[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static int	check_other(char ***args, t_data *data, t_ins *ins)
{
	int	ret;

	if ((*args)[ins->index][0] == INDIRECT_LABEL_CHAR)
	{
		if (check_ind_lbl(data, ins, &((*args)[ins->index][1])) == ERROR)
			return (end_get_args_ins(ERROR, *args));
	}
	else if (ft_isdigit((*args)[ins->index][0]) == 1 || \
	(*args)[ins->index][0] == '-')
	{
		if (check_ind_arg(data, ins, (*args)[ins->index]) == ERROR)
			return (end_get_args_ins(ERROR, *args));
	}
	else if ((*args)[ins->index][0] == REGISTRY)
	{
		if (check_reg(data, ins, &((*args)[ins->index][1])) == ERROR)
			return (end_get_args_ins(ERROR, *args));
	}
	else
	{
		ret = asm_error(SYNT_ERR, INV_CHAR, data->num_lines);
		return (end_get_args_ins(ret, *args));
	}
	return (SUCCESS);
}

int			get_args_loop(char ***args, t_data *data, t_ins *ins)
{
	int	ret;

	while ((*args)[ins->index])
	{
		if ((*args)[ins->index][0] == DIRECT_CHAR)
		{
			ret = check_lbl(&(*args), data, ins);
			if (ret != SUCCESS)
				return (ret);
		}
		else
		{
			ret = check_other(&(*args), data, ins);
			if (ret != SUCCESS)
				return (ret);
		}
		ins->index++;
	}
	return (SUCCESS);
}
