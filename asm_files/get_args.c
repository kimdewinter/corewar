/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:54:16 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static size_t	contains_only_digits(const char *str)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int				check_reg(t_data *data, t_ins *ins, char *arg)
{
	int			reg;
	int			len;

	len = ft_strlen(arg);
	reg = 0;
	if (len < 1 || len > 2)
		return (asm_error(ARG_ERR, INV_REG, data->num_lines));
	if (arg[0] == '0' && arg[1] == '0')
		return (asm_error(ARG_ERR, INV_REG, data->num_lines));
	if (contains_only_digits(arg) == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	reg = ft_atoi(arg);
	ins->args_type[ins->index] = REG_CODE;
	ins->arguments[ins->index] = reg;
	ins->ins_size += get_arg_size(ins, REG_CODE);
	if (arg_type_validation(ins->opcode, REG_CODE, ins->index) == 0)
		return (asm_error(ARG_ERR, INV_TYPE_ARGS, data->num_lines));
	return (SUCCESS);
}

int				check_lbl(char ***args, t_data *data, t_ins *ins)
{
	if ((*args)[ins->index][1] == LABEL_CHAR)
	{
		if (check_dir_lbl(data, ins, &((*args)[ins->index][2])) == ERROR)
			return (end_get_args_ins(ERROR, *args));
	}
	else
	{
		if (check_dir_arg(data, ins, &((*args)[ins->index][1])) == ERROR)
			return (end_get_args_ins(ERROR, *args));
	}
	return (SUCCESS);
}

int				get_args_ins(t_data *data, t_ins *ins, char *arguments)
{
	char		**args;
	int			ret;

	args = NULL;
	ret = init_args(&args, data, arguments);
	if (ret != SUCCESS)
		return (ret);
	ret = get_args_loop(&args, data, ins);
	if (ret != SUCCESS)
		return (ret);
	if (ins->index > (int)ins->max_arg)
	{
		ret = asm_error(ARG_ERR, INV_NUM_ARGS, data->num_lines);
		return (end_get_args_ins(ret, args));
	}
	data->total_size += ins->ins_size;
	return (end_get_args_ins(SUCCESS, args));
}
