/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_return1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:16:20 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int	end_handle_instruction(const int ret, char *arguments, char *op, \
t_ins *new)
{
	if (arguments != NULL)
		ft_strdel(&arguments);
	if (op != NULL)
		ft_strdel(&op);
	if (new != NULL && ret != SUCCESS)
	{
		free(new);
		new = NULL;
	}
	return (ret);
}

int	end_get_operations(const int ret, char **line)
{
	if (*line != NULL)
		ft_strdel(line);
	return (ret);
}

int	end_get_args_ins(const int ret, char **args)
{
	if (args != NULL)
		ft_strarrdel(&args);
	return (ret);
}

int	end_handle_label(const int ret, char *instr, char *label_name, \
t_label *label)
{
	if (instr != NULL)
		ft_strdel(&instr);
	if (label_name != NULL)
		ft_strdel(&label_name);
	if (label != NULL && ret != SUCCESS)
	{
		if (label->name != NULL)
			ft_strdel(&label->name);
		free(label);
		label = NULL;
	}
	return (ret);
}
