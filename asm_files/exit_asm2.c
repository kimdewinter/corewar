/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_asm2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 20:57:53 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

void		free_ins(t_ins **ins_lst)
{
	t_ins	*temp;
	t_ins	*next;

	temp = *ins_lst;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	if (*ins_lst)
		*ins_lst = NULL;
	ins_lst = NULL;
}

void		free_data(t_data **data)
{
	t_data	*temp;

	temp = *data;
	if (temp->name_cmd != NULL)
		ft_strdel(&(temp)->name_cmd);
	if (temp->comment_cmd != NULL)
		ft_strdel(&(temp)->comment_cmd);
	free(temp);
	*data = NULL;
	data = NULL;
}

int			synt_err(int err, int line)
{
	ft_printf(ANSI_COLOR_RED);
	if (err == INV_CHAR)
		ft_dprintf(STDERR_FILENO, "ERROR: SYNTAX ERROR ON LINE %d\n", line);
	if (err == NO_NEWL)
		ft_dprintf(STDERR_FILENO, \
			"ERROR: NO NEWLINE AFTER OPERATION OR LABEL ON LINE %d\n", line);
	if (err == INV_SEP)
		ft_dprintf(STDERR_FILENO, \
			"ERROR: INVALID SEPARATOR ON LINE %d\n", line);
	ft_printf(ANSI_COLOR_RESET);
	return (ERROR);
}
