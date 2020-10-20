/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_commands.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:12:01 by rheuts        #+#    #+#                 */
/*   Updated: 2020/09/17 18:14:14 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int		get_clean_command(t_data *data, char **command, char *line, \
int len)
{
	*command = ft_strdup(&line[len]);
	if (*command == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	if (remove_spaces(command) == ERROR)
		return (ERROR);
	if (*command == NULL || (*command)[0] != QUOTATION_CHAR)
	{
		if (*command != NULL)
			ft_strdel(command);
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	}
	return (SUCCESS);
}

int				check_commands(t_asm *asm_var, t_data *data, char *line)
{
	char	*command;
	int		len_name;
	int		len_comment;
	int		ret;

	command = NULL;
	ret = 0;
	len_name = ft_strlen(NAME_CMD_STRING);
	len_comment = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strnequ(line, NAME_CMD_STRING, len_name) == 1)
	{
		if (get_clean_command(data, &command, line, len_name) == ERROR)
			return (ERROR);
		ret = check_champion_name(asm_var, data, command);
	}
	else if (ft_strnequ(line, COMMENT_CMD_STRING, len_comment) == 1)
	{
		if (get_clean_command(data, &command, line, len_comment) == ERROR)
			return (ERROR);
		ret = check_champion_comment(asm_var, data, command);
	}
	if (command != NULL)
		ft_strdel(&command);
	return (ret);
}
