/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_command_begin.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:58:36 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:58:39 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** Function that checks extension of last file and finds filename
*/

static int		check_command_exist(t_data *data, int rd)
{
	if (rd < 0)
		return (asm_error(READ_ERR, INV_READ, 0));
	if (data->comment_cmd == NULL)
		return (asm_error(CMD_ERR, NO_COMM, 0));
	if (data->name_cmd == NULL)
		return (asm_error(CMD_ERR, NO_NAME, 0));
	return (SUCCESS);
}

static int		free_and_ret(char **line, int ret)
{
	ft_strdel(line);
	return (ret);
}

static int		check_valid_line_cmd(t_asm *asm_var, t_data *data, char *line,
int rd)
{
	if (line[0] != COMMAND_CHAR)
		return (free_and_ret(&line, asm_error(SYNT_ERR, INV_CHAR,
		data->num_lines)));
	else if (check_commands(asm_var, data, line) == ERROR)
		return (free_and_ret(&line, ERROR));
	asm_var->nl_last = rd;
	return (SUCCESS);
}

int				get_name_comment(t_asm *asm_var, t_data *data)
{
	int		rd;
	char	*line;

	rd = 1;
	line = NULL;
	while (rd > 0 && (data->comment_cmd == NULL || data->name_cmd == NULL))
	{
		rd = get_next_line(asm_var->fd, &line);
		data->num_lines++;
		if (rd > 0)
		{
			if (remove_spaces(&line) == ERROR)
				return (asm_error(GEN_ERR, MALL_ERR, 0));
			if (is_comment_or_empty(line) == 0)
			{
				if (check_valid_line_cmd(asm_var, data, line, rd) == ERROR)
					return (ERROR);
			}
		}
		if (line != NULL)
			ft_strdel(&line);
	}
	return (check_command_exist(data, rd));
}
