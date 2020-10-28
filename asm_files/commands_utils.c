/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:57:30 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int			check_error_cmds(t_data *data, int closing_quote_found, int rd)
{
	if (rd < 0)
		return (asm_error(READ_ERR, INV_READ, 0));
	if (closing_quote_found == 0)
		return (asm_error(SYNT_ERR, INV_CHAR, data->num_lines));
	return (SUCCESS);
}

int			check_valid(char *tmp)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(tmp);
	i = 0;
	while (i < len)
	{
		if (ft_isspace(tmp[i]) == 0 && tmp[i] != COMMENT_CHAR &&
		tmp[i] != ALT_COMMENT_CHAR)
			return (0);
		if (tmp[i] == COMMENT_CHAR || tmp[i] == ALT_COMMENT_CHAR)
			return (1);
		i++;
	}
	return (1);
}

int			join_cmd(char **prev, char *add)
{
	char	*tmp;

	tmp = ft_strjoin(*prev, "\n");
	if (tmp == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	ft_strdel(prev);
	*prev = ft_strjoin(tmp, add);
	ft_strdel(&tmp);
	if (*prev == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	return (SUCCESS);
}
