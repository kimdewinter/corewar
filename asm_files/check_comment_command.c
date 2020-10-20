/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_comment_command.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:52:08 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:52:11 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int			check_closing_quote(t_data *data, char **comment,
int *closing_quote_found, char *buff)
{
	char	*closing_quote;
	int		ret;

	closing_quote = ft_strchr(buff, '"');
	if (closing_quote != NULL)
	{
		*closing_quote_found = 1;
		ret = finish_comment(data, comment, buff);
		ft_strdel(&buff);
		return (ret);
	}
	else
	{
		ret = join_cmd(comment, buff);
		if (ret == ERROR)
		{
			ft_strdel(&buff);
			return (ret);
		}
		return (SUCCESS);
	}
}

static int			complete_comment(t_asm *asm_var, t_data *data,
char **comment)
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
			ret = check_closing_quote(data, comment, &closing_quote_found,
			buff);
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
	char	*comment;
	int		ret;

	comment = ft_strdup(&command[1]);
	if (comment == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	else
	{
		ret = complete_comment(asm_var, data, &comment);
		if (comment != NULL)
			ft_strdel(&comment);
		return (ret);
	}
}

static int			quote_if_two(t_data *data, char *command)
{
	char	*comment;
	char	*tmp;
	int		index;

	comment = ft_strchr(command, '"');
	tmp = ft_strchr(&comment[1], '"');
	index = (int)(tmp - comment);
	data->comment_cmd = ft_strsub(comment, 1, index - 1);
	if (data->comment_cmd == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (check_valid(&comment[index + 1]) == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	return (SUCCESS);
}

int					check_champion_comment(t_asm *asm_var, t_data *data,
char *command)
{
	size_t	quote_count;
	int		ret;

	ret = SUCCESS;
	if (data->comment_cmd != NULL)
		return (asm_error(CMD_ERR, DBL_COMM, 0));
	quote_count = ft_strchr_count(command, '"');
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
	if (ft_strlen(data->comment_cmd) > COMMENT_LENGTH)
		return (asm_error(CMD_ERR, NM_LEN, 0));
	return (SUCCESS);
}
