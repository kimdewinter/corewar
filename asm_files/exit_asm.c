/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_asm.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:56:41 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/30 15:04:49 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static void		free_label(t_label **label_lst)
{
	t_label		*temp;
	t_label		*next;

	temp = *label_lst;
	while (temp != NULL)
	{
		next = temp->next;
		if (temp->name != NULL)
			ft_strdel(&(temp)->name);
		free(temp);
		temp = next;
	}
	if (*label_lst)
		*label_lst = NULL;
	label_lst = NULL;
}

static void		free_placeholder(t_ph **ph_lst)
{
	t_ph		*temp;
	t_ph		*next;

	temp = *ph_lst;
	while (temp != NULL)
	{
		next = temp->next;
		if (temp->label_name != NULL)
			ft_strdel(&(temp)->label_name);
		free(temp);
		temp = next;
	}
	if (*ph_lst)
		*ph_lst = NULL;
	ph_lst = NULL;
}

static void		free_asm_var(t_asm **asm_var)
{
	t_asm		*temp;

	temp = *asm_var;
	if ((*asm_var)->origin_file != NULL)
	{
		free((*asm_var)->origin_file);
		(*asm_var)->origin_file = NULL;
	}
	if (temp->file != NULL)
	{
		free(temp->file);
		temp->file = NULL;
	}
	if (temp->file_name != NULL)
	{
		free(temp->file_name);
		temp->file_name = NULL;
	}
	free(temp);
	*asm_var = NULL;
	asm_var = NULL;
	temp = NULL;
}

static void		empty_gnl_buffer(const int fd)
{
	char	*str;

	str = NULL;
	if (fd > 2)
	{
		while (get_next_line(fd, &str) > 0)
		{
			if (str != NULL)
				ft_strdel(&str);
		}
	}
}

int				ft_exit_asm(t_asm *asm_var, t_data *data, int ret)
{
	if (asm_var != NULL)
	{
		empty_gnl_buffer(asm_var->fd);
		close(asm_var->fd);
		close(asm_var->fd_rw);
	}
	if (data != NULL)
	{
		free_ins(&data->ins_lst);
		free_placeholder(&data->ins_placeholders);
		free_label(&data->label_lst);
		free_data(&data);
	}
	if (asm_var != NULL)
		free_asm_var(&asm_var);
	return (ret);
}
