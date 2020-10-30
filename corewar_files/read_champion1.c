/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_champion1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 14:13:44 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/30 13:31:32 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	read_prog_size(int fd, t_player *new, t_env *game)
{
	int	rd;

	rd = read(fd, &new->data->prog_size, 4);
	if (rd < 0)
		handle_error(game, "[Error] Unable to read file\n");
	if (rd < 4)
		handle_error(game, "[Error] Read too few bytes for program size\n");
	reverse_mem(&new->data->prog_size, 3);
	if (new->data->prog_size > CHAMP_MAX_SIZE || new->data->prog_size < 0)
		handle_error(game, "[Error] Invalid program size\n");
}

void	read_comment(int fd, t_player *new, t_env *game)
{
	int	rd;

	rd = read(fd, &new->data->comment, COMMENT_LENGTH);
	if (rd < 0)
		handle_error(game, "[Error] Unable to read file\n");
	if (rd < COMMENT_LENGTH)
		handle_error(game, "[Error] Read too few bytes for comment\n");
}

void	read_champion_code(int fd, t_player *new, t_env *game)
{
	int	rd;

	rd = read(fd, new->code, CHAMP_MAX_SIZE + 1);
	if (rd < 0)
		handle_error(game, "[Error] Unable to read file\n");
	if (rd > CHAMP_MAX_SIZE)
		handle_error(game, "[Error] Program size of exceeds the maximum");
	if (rd != (int)new->data->prog_size)
		handle_error(game, "[Error] Specified size doesn't match program \
size\n");
}

int		read_file(t_player *new, t_env *game)
{
	int	fd;

	fd = open(new->filename, O_RDONLY);
	if (fd < 0)
		handle_error(game, "[Error] Failed to open file\n");
	read_magic_header(fd, new, game);
	read_prog_name_length(fd, new, game);
	read_null_bytes(fd, new, game);
	read_prog_size(fd, new, game);
	read_comment(fd, new, game);
	read_null_bytes(fd, new, game);
	read_champion_code(fd, new, game);
	close(fd);
	return (1);
}

int		read_champion(t_env *arena)
{
	t_player	*walker;

	if (arena == NULL)
		handle_error(arena, "[Error] Missing arena\n");
	if (arena->players == NULL)
		handle_error(arena, "[Error] Missing players\n");
	walker = arena->players;
	while (walker)
	{
		read_file(walker, arena);
		walker = walker->next;
	}
	return (1);
}
