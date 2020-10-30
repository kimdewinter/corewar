/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_name_command.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:50:53 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/30 11:35:35 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int			check_closing_quote(t_data *data, char **name,
int *closing_quote_found, char *buff)
{
	char	*closing_quote;
	int		ret;

	closing_quote = ft_strchr(buff, QUOTATION_CHAR);
	if (closing_quote != NULL)
	{
		*closing_quote_found = 1;
		ret = finish_name(data, name, buff);
		ft_strdel(&buff);
		return (ret);
	}
	else
	{
		ret = join_cmd(name, buff);
		if (ret == ERROR)
		{
			ft_strdel(&buff);
			return (ret);
		}
		return (SUCCESS);
	}
}

static int			complete_name(t_asm *asm_var, t_data *data, char **name)
{
	int		rd;
	char	*buff;
	int		ret;
	int		closing_quote_found;

	rd = 1;
	buff = NULL;
	closing_quote_found = 0;
	while (rd > 0)
	{
		rd = get_next_line(asm_var->fd, &buff);
		data->num_lines++;
		if (rd > 0)
		{
			ret = check_closing_quote(data, name, &closing_quote_found, buff);
			if (closing_quote_found == 1 || ret == ERROR)
				return (ret);
		}
		if (buff != NULL)
			ft_strdel(&buff);
	}
	return (check_error_cmds(data, closing_quote_found, rd));
}

static int			quote_if_one(t_asm *asm_var, t_data *data, char *command)
{
	char	*name;
	int		ret;

	name = ft_strdup(&command[1]);
	if (name == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	else
	{
		ret = complete_name(asm_var, data, &name);
		if (name != NULL)
			ft_strdel(&name);
		return (ret);
	}
}

static int			quote_if_two(t_data *data, char *command)
{
	char	*name;
	char	*tmp;
	int		index;

	name = ft_strchr(command, QUOTATION_CHAR);
	tmp = ft_strchr(&name[1], QUOTATION_CHAR);
	index = (int)(tmp - name);
	data->name_cmd = ft_strsub(name, 1, index - 1);
	if (data->name_cmd == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (check_valid(&name[index + 1]) == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	return (SUCCESS);
}

int					check_champion_name(t_asm *asm_var, t_data *data,
char *command)
{
	size_t	quote_count;
	int		ret;

	ret = SUCCESS;
	if (data->name_cmd != NULL)
		return (asm_error(CMD_ERR, DBL_NM, 0));
	quote_count = ft_strchr_count(command, QUOTATION_CHAR);
	if (quote_count == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	else if (quote_count == 1)
	{
		ret = quote_if_one(asm_var, data, command);
		if (ret == ERROR)
			return (ERROR);
	}
	else
	{
		ret = quote_if_two(data, command);
		if (ret == ERROR)
			return (ERROR);
	}
	if (ft_strlen(data->name_cmd) > PROG_NAME_LENGTH)
		return (asm_error(CMD_ERR, NM_LEN, 0));
	return (SUCCESS);
}
