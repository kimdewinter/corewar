/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_spaces.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:55:38 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:55:40 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int				remove_comment(char **str)
{
	int		len;
	int		i;
	char	*tmp;

	len = ft_strlen(*str);
	i = len - 1;
	tmp = NULL;
	while (i >= 0)
	{
		if ((*str)[i] == COMMENT_CHAR || (*str)[i] == ALT_COMMENT_CHAR)
		{
			tmp = ft_strdup(*str);
			if (tmp == NULL)
				return (asm_error(GEN_ERR, MALL_ERR, 0));
			tmp[i] = '\0';
			ft_strdel(str);
			*str = tmp;
		}
		i--;
	}
	return (SUCCESS);
}

static void		get_spaces_count(char *str, int *start, int *end, int *len)
{
	*len = ft_strlen(str);
	*start = count_spaces_start(str);
	*end = count_spaces_end(str, *len);
}

int				remove_spaces(char **str)
{
	int		start;
	int		end;
	int		len;
	char	*tmp;

	tmp = NULL;
	get_spaces_count(*str, &start, &end, &len);
	if (start + end >= len)
		ft_strdel(str);
	else
	{
		tmp = ft_strnew(len - (end + start));
		if (tmp)
		{
			ft_strncpy(tmp, &(*str)[start], len - (end + start));
			ft_strdel(str);
			*str = tmp;
		}
		else
		{
			ft_strdel(str);
			return (asm_error(GEN_ERR, MALL_ERR, 0));
		}
	}
	return (SUCCESS);
}

int				is_comment_or_empty(char *line)
{
	if (line != NULL && line[0] != COMMENT_CHAR && line[0] != ALT_COMMENT_CHAR
	&& line[0] != '\0')
		return (0);
	return (1);
}
