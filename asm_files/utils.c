/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 13:57:32 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/09/18 13:57:34 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int		clean_line(char **line)
{
	if (remove_spaces(line) == ERROR)
		return (end_get_operations(ERROR, line));
	if (*line != NULL && remove_comment(line) == ERROR)
		return (end_get_operations(ERROR, line));
	return (SUCCESS);
}

int		find_non_label_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchri(LABEL_CHARS, str[i]) == -1)
			return (i);
		i++;
	}
	return (i);
}

int		ft_strchr_count(char *str, char c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			j += 1;
		i++;
	}
	return (j);
}

int		ft_strchri(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_isspace(char c)
{
	if (c == '\f' || c == ENDLINE_CHAR || c == '\r' || c == '\t'
	|| c == '\v' || c == ' ' || c == '\n')
		return (1);
	return (0);
}
