/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_label.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 20:39:27 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/09/17 21:53:31 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static void		add_label_tail(t_label **label_lst)
{
	t_label		*tail;

	tail = *label_lst;
	while (tail && tail->next != NULL)
		tail = tail->next;
	if (tail)
	{
		if (tail && tail->prev)
			tail->prev = tail->prev;
		else
			tail->prev = NULL;
		(*label_lst)->tail = tail;
	}
}

static void		ft_labeladdend(t_label **label_lst, t_label *new)
{
	t_label		*temp;

	temp = *label_lst;
	if (temp == NULL)
	{
		*label_lst = new;
		new->prev = NULL;
		new->tail = new;
		new->tail->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		temp->next->prev = temp;
	}
}

static int		label_checks(char **instr, t_data **data, char **label, \
								t_label **new)
{
	int			ret;

	if (*instr == NULL)
	{
		ret = asm_error(GEN_ERR, MALL_ERR, (*data)->num_lines);
		return (end_handle_label(ret, *instr, *label, *new));
	}
	if (remove_spaces(instr) == ERROR)
		return (end_handle_label(ERROR, *instr, *label, *new));
	if (create_label(new, *label, (*data)) == ERROR)
		return (end_handle_label(ERROR, *instr, *label, *new));
	if (*new == NULL)
	{
		ret = asm_error(GEN_ERR, MALL_ERR, 0);
		return (end_handle_label(ret, *instr, *label, *new));
	}
	ft_labeladdend(&(*data)->label_lst, *new);
	add_label_tail(&(*data)->label_lst);
	ft_strdel(label);
	return (SUCCESS);
}

int				handle_label(t_data *data, char *line)
{
	int			len;
	char		*label;
	char		*instr;
	int			ret;
	t_label		*new;

	instr = NULL;
	new = NULL;
	len = ft_strchri(line, LABEL_CHAR);
	label = ft_strdup(line);
	if (label == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	label[len] = '\0';
	instr = ft_strdup(&line[len + 1]);
	ret = label_checks(&instr, &data, &label, &new);
	if (ret != SUCCESS)
		return (ret);
	if (instr != NULL && instr[0] != '\0')
	{
		ret = handle_instruction(data, instr);
		ft_strdel(&instr);
		return (ret);
	}
	return (end_handle_label(SUCCESS, instr, label, new));
}
