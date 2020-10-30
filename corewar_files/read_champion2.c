/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_champion2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 14:12:25 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/30 13:23:33 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	read_magic_header(t_env *game, int fd, t_player *new)
{
	int	rd;

	rd = read(fd, &new->data->magic, 4);
	if (rd < 0)
		handle_error("[Error] Unable to read: %s\n", new->filename);
	if (rd < 4)
		handle_error("[Error] Read too few bytes for magic header\n");
	reverse_mem(&new->data->magic, 3);
	if (new->data->magic != COREWAR_EXEC_MAGIC)
		handle_error("[Error] Magic header is invalid\n");
}

void	read_prog_name_length(t_env *game, int fd, t_player *new)
{
	int	rd;

	rd = read(fd, &new->data->prog_name, PROG_NAME_LENGTH);
	if (rd < 0)
		handle_error("[Error] Unable to read: %s\n", new->filename);
	if (rd < PROG_NAME_LENGTH)
		handle_error("[Error] Read too few bytes for program name\n");
}

void	read_null_bytes(t_env *game, int fd, t_player *new)
{
	int	rd;
	int	buff;

	rd = read(fd, &buff, 4);
	if (rd < 0)
		handle_error("[Error] Unable to read: %s\n", new->filename);
	if (rd < 4)
		handle_error("[Error] Read too few bytes\n");
	if (buff != 0)
		handle_error("[Error] Missing 4 null bytes after program name\n");
}
