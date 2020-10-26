/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm_checks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:59:28 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int		check_name_comment(t_asm *asm_var, t_data *data)
{
	if (get_name_comment(asm_var, data) == ERROR)
		return (ERROR);
	if (data->name_cmd == NULL)
		return (asm_error(CMD_ERR, NO_NAME, 0));
	if (data->comment_cmd == NULL)
		return (asm_error(CMD_ERR, NO_COMM, 0));
	return (SUCCESS);
}

int		check_exec_code(t_asm *asm_var, t_data *data)
{
	if (data->total_size == 0 && data->label_lst == NULL)
	{
		return (ft_exit_asm(asm_var, data, asm_error(GEN_ERR, NO_CODE,
			data->num_lines)));
	}
	return (SUCCESS);
}
