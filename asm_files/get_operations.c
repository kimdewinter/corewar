/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_operations.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:53:04 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:53:06 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int	is_operation(char *operation)
{
	int		i;
	char	*op;
	int		first_non_label_char;

	first_non_label_char = find_non_label_char(operation);
	i = 0;
	op = ft_strdup(operation);
	if (op == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	op[first_non_label_char] = '\0';
	while (i < 16)
	{
		if (ft_strequ((g_op_tab[i].op_name), op) == 1)
		{
			ft_strdel(&op);
			return (1);
		}
		i++;
	}
	ft_strdel(&op);
	return (0);
}

static int	is_label(char *str)
{
	int		first_non_label_char;

	first_non_label_char = find_non_label_char(str);
	if (str[first_non_label_char] == LABEL_CHAR && first_non_label_char != 0)
		return (1);
	return (0);
}

static int	handle_label_or_op(t_asm *asm_var, t_data *data, char **line,
int rd)
{
	int ret;

	ret = is_operation(*line);
	if (ret == ERROR)
		return (end_get_operations(ERROR, line));
	if (is_label(*line) == 1)
	{
		if (handle_label(data, *line) == ERROR)
			return (end_get_operations(ERROR, line));
		asm_var->nl_last = rd;
		return (SUCCESS);
	}
	else if (ret == 1)
	{
		if (handle_instruction(data, *line) == ERROR)
			return (end_get_operations(ERROR, line));
		asm_var->nl_last = rd;
		return (SUCCESS);
	}
	else
		return (end_get_operations(asm_error(
			GEN_ERR, INV_LINE, data->num_lines), line));
}

static int	check_errors(t_asm *asm_var, t_data *data, int rd)
{
	if (rd < 0)
		return (asm_error(READ_ERR, INV_READ, 0));
	if (asm_var->nl_last != 2)
		return (asm_error(SYNT_ERR, NO_NEWL, data->num_lines));
	return ((SUCCESS));
}

int			get_operations(t_asm *asm_var, t_data *data)
{
	int		rd;
	char	*line;

	rd = 1;
	line = NULL;
	while (rd > 0)
	{
		rd = get_next_line(asm_var->fd, &line);
		data->num_lines++;
		if (rd > 0)
		{
			if (clean_line(&line) == ERROR)
				return (ERROR);
			if (is_comment_or_empty(line) == 0)
			{
				if (handle_label_or_op(asm_var, data, &line, rd) == ERROR)
					return (ERROR);
			}
		}
		if (line != NULL)
			ft_strdel(&line);
	}
	return (check_errors(asm_var, data, rd));
}
