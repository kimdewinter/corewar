/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_command_end.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:58:09 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:58:12 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int			finish_comment(t_data *data, char **comment, char *buff)
{
	char	*last_quote;
	char	*found;
	int		index;

	last_quote = ft_strchr(buff, '"');
	index = (int)(last_quote - buff);
	found = ft_strsub(buff, 0, index);
	if (found == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (join_cmd(comment, found) == ERROR)
	{
		ft_strdel(&found);
		return (ERROR);
	}
	else
		ft_strdel(&found);
	data->comment_cmd = ft_strdup(*comment);
	if (data->comment_cmd == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (check_valid(&buff[index + 1]) == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	return (SUCCESS);
}

int			finish_name(t_data *data, char **name, char *buff)
{
	char	*last_quote;
	char	*found;
	int		index;

	last_quote = ft_strchr(buff, '"');
	index = (int)(last_quote - buff);
	found = ft_strsub(buff, 0, index);
	if (found == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (join_cmd(name, found) == ERROR)
	{
		ft_strdel(&found);
		return (ERROR);
	}
	else
		ft_strdel(&found);
	data->name_cmd = ft_strdup(*name);
	if (data->name_cmd == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (check_valid(&buff[index + 1]) == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	return (SUCCESS);
}
