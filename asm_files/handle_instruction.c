/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_instruction.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:48:55 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:48:58 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

void			find_opcode_args(t_ins *ins, char *op)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(g_op_tab[i].op_name, op) == 1)
		{
			ins->opcode = g_op_tab[i].opcode;
			ins->max_arg = g_op_tab[i].args_amount;
			ins->encoding_byte = g_op_tab[i].octal_code;
			ins->ins_size += (int)ins->encoding_byte;
			ins->t_dir_size = g_op_tab[i].t_dir_size;
		}
		i++;
	}
}

static int		is_valid_separator(const char chr)
{
	if (ft_isspace(chr) == 1 || chr == '-' || chr == DIRECT_CHAR)
		return (1);
	return (0);
}

static int		ret_mall_error(char *arguments, char *op, t_ins *new)
{
	return (end_handle_instruction(
		asm_error(GEN_ERR, MALL_ERR, 0), arguments, op, new));
}

int				handle_instruction(t_data *data, char *line)
{
	int		last_non_label;
	char	*op;
	char	*arguments;
	t_ins	*new;

	arguments = NULL;
	new = NULL;
	last_non_label = find_non_label_char(line);
	if (is_valid_separator(line[last_non_label]) == 0)
		return (asm_error(SYNT_ERR, INV_SEP, data->num_lines));
	op = ft_strdup(line);
	if (op == NULL)
		return (ret_mall_error(arguments, op, new));
	op[last_non_label] = '\0';
	if (create_instr(&new, data, op) == ERROR)
		return (end_handle_instruction(ERROR, arguments, op, new));
	arguments = ft_strdup(&line[last_non_label]);
	if (arguments == NULL)
		return (ret_mall_error(arguments, op, new));
	if (remove_spaces(&arguments) == ERROR)
		return (ret_mall_error(arguments, op, new));
	if (get_args_ins(data, new, arguments) == ERROR)
		return (end_handle_instruction(ERROR, arguments, op, new));
	ft_instruction_addend(&data->ins_lst, new);
	return (end_handle_instruction(SUCCESS, arguments, op, new));
}
