/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_data1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:03:52 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/17 19:51:31 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** Writes the champion name and pads the remaining bytes with 0.
*/

static void	write_name(int fd, char *name)
{
	int		len;
	char	*pad;

	len = 0;
	len = ft_strlen(name);
	write(fd, name, len);
	pad = (char *)ft_memalloc(sizeof(char) * (PROG_NAME_LENGTH - len));
	write(fd, pad, PROG_NAME_LENGTH - len);
	free(pad);
}

/*
** Writes the champion comment and pads the remaining bytes with 0.
*/

static void	write_comment(int fd, char *comment)
{
	int		len;
	char	*pad;

	len = ft_strlen(comment);
	write(fd, comment, len);
	pad = (char *)ft_memalloc(sizeof(char) * (COMMENT_LENGTH - len));
	write(fd, pad, COMMENT_LENGTH - len);
	free(pad);
}

/*
** Writes argument to FD, size depending on arg type.
** If argument is negative then needs conversion to 2's complement
*/

static void	write_arg(int fd, int i, t_ins *ins)
{
	if (ins->arguments[i] < 0)
		ins->arguments[i] = make_twoscomplement(-(ins->arguments[i]));
	if (ins->args_type[i] == REG_CODE)
		ft_rnputstr(fd, (unsigned char *)&ins->arguments[i], 1);
	else if (ins->args_type[i] == DIR_CODE)
		ft_rnputstr(fd, (unsigned char *)&ins->arguments[i], ins->t_dir_size);
	else if (ins->args_type[i] == IND_CODE)
		ft_rnputstr(fd, (unsigned char *)&ins->arguments[i], 2);
}

/*
** Loops through the instruction list.
** Writes the opcode in 1 byte.
** If encoding_byte is turned on, write the encoding byte
** Loops through arguments,
** sending them to write_arg with fd, index and ins struct
*/

static void	write_champ_code(int fd, t_ins *ins_lst)
{
	t_wcc_wrap	wrap;

	wrap.i = 0;
	wrap.k = 0;
	wrap.ins = ins_lst;
	while (wrap.ins != NULL)
	{
		ft_rnputstr(fd, (unsigned char *)&wrap.ins->opcode, 1);
		wrap.max_arg = wrap.ins->max_arg;
		if (wrap.ins->encoding_byte)
		{
			wrap.ret = enc_byte(wrap.ins->args_type);
			ft_rnputstr(fd, (unsigned char *)&wrap.ret, 1);
		}
		while (wrap.i < wrap.max_arg)
		{
			write_arg(fd, wrap.i, wrap.ins);
			wrap.i++;
		}
		wrap.i = 0;
		wrap.k++;
		wrap.ins = wrap.ins->next;
	}
}

/*
** First reverse putstr writes the magic header,
** second one writes the execution code size.
** The write functions write what their function name implies.
** Closes FD, remove if present elsewhere.
*/

int			write_data(t_asm *asm_var, t_data *data)
{
	int		header;
	int		exec_size;

	exec_size = data->total_size;
	header = COREWAR_EXEC_MAGIC;
	ft_rnputstr(asm_var->fd_rw, (unsigned char *)&header, sizeof(int));
	write_name(asm_var->fd_rw, data->name_cmd);
	write_null(asm_var->fd_rw);
	ft_rnputstr(asm_var->fd_rw, (unsigned char *)&exec_size, sizeof(int));
	write_comment(asm_var->fd_rw, data->comment_cmd);
	write_null(asm_var->fd_rw);
	write_champ_code(asm_var->fd_rw, data->ins_lst);
	return (0);
}
