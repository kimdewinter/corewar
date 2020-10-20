/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:49:29 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 10:49:31 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int		read_and_write_asm_file(t_asm *asm_var, char **argv, int flag)
{
	char	str[1];

	if (flag == 0)
	{
		asm_var->fd = open(*argv, O_RDONLY);
		if (asm_var->fd < 3)
			return (asm_error(READ_ERR, INV_FD, 0));
		if (read(asm_var->fd, str, 0) < 0)
			return (asm_error(READ_ERR, INV_READ, 0));
	}
	else
	{
		asm_var->file = ft_strjoin(asm_var->file_name, ".cor");
		if (asm_var->file == NULL)
			return (asm_error(GEN_ERR, MALL_ERR, 0));
		asm_var->fd_rw = open(asm_var->file, O_CREAT | O_TRUNC | O_RDWR, 0755);
		if (asm_var->fd_rw < 3)
			return (asm_error(READ_ERR, WR_ERR, 0));
	}
	return (SUCCESS);
}

static int		check_extension(t_asm *asm_var, int argc, char **argv)
{
	int		i;
	char	*str;
	char	*extension;

	i = 0;
	extension = NULL;
	while (i < argc)
	{
		str = argv[i];
		i++;
	}
	asm_var->file = ft_strdup(argv[i - 1]);
	extension = ft_strrchr(str, '.');
	if (extension == NULL || ft_strequ(extension, ".s") == 0)
		return (asm_error(GEN_ERR, INV_EXT, 0));
	extension[0] = '\0';
	asm_var->file_name = ft_strdup(str);
	ft_strcpy(argv[i - 1], asm_var->file);
	ft_strdel(&(asm_var)->file);
	return (SUCCESS);
}

static int		set_data(int argc, t_asm **asm_var, t_data **data)
{
	if (argc < 2)
		return (asm_error(GEN_ERR, NO_INPUT, 0));
	*asm_var = (t_asm *)(ft_memalloc(sizeof(t_asm)));
	*data = (t_data *)(ft_memalloc(sizeof(t_data)));
	if (asm_var == NULL || data == NULL)
		return (asm_error(GEN_ERR, MALL_ERR, 0));
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_asm	*asm_var;
	t_data	*data;

	asm_var = NULL;
	data = NULL;
	if (set_data(argc, &asm_var, &data) == ERROR)
		return (ft_exit_asm(asm_var, data, ERROR));
	if (read_and_write_asm_file(asm_var, &argv[argc - 1], 0) != SUCCESS)
		return (ft_exit_asm(asm_var, data, ERROR));
	if (check_extension(asm_var, argc, argv) != SUCCESS)
		return (ft_exit_asm(asm_var, data, ERROR));
	if (check_name_comment(asm_var, data) == ERROR)
		return (ft_exit_asm(asm_var, data, ERROR));
	if (get_operations(asm_var, data) == ERROR)
		return (ft_exit_asm(asm_var, data, ERROR));
	if (backpatching_ins_lst(data->ins_placeholders, data) != SUCCESS)
		return (ft_exit_asm(asm_var, data, ERROR));
	if (check_exec_code(asm_var, data) == ERROR)
		return (ERROR);
	if (read_and_write_asm_file(asm_var, &argv[argc - 1], 1) != SUCCESS)
		return (ft_exit_asm(asm_var, data, ERROR));
	write_data(asm_var, data);
	return (ft_exit_asm(asm_var, data, SUCCESS));
}
