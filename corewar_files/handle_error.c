/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 12:18:51 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/30 14:06:03 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	delete_players(t_player **players)
{
	t_player *next;

	while (*players != NULL)
	{
		next = (*players)->next;
		if ((*players)->data != NULL)
		{
			free ((*players)->data);
			(*players)->data = NULL;
		}
		free(*players);
		*players = next;
	}
}

static void	delete_cursors(t_cursor **cursors)
{
	t_cursor	*next;

	while (*cursors != NULL)
	{
		next = (*cursors)->next;
		free(*cursors);
		*cursors = next;
	}
}

static void	delete_arena(t_arena **arena)
{
	if (*arena != NULL)
	{
		if ((*arena)->code != NULL)
		{
			free((*arena)->code);
			(*arena)->code = NULL;
		}
		if ((*arena)->color != NULL)
		{
			free((*arena)->color);
			(*arena)->color = NULL;
		}
		free(*arena);
		*arena = NULL;
	}
}

static void	delete_vis(t_vis **vis)
{
	if (*vis != NULL)
	{
		if ((*vis)->code_win != NULL)
		{
			free((*vis)->code_win);
			(*vis)->code_win = NULL;
		}
		if ((*vis)->info_win != NULL)
		{
			free((*vis)->info_win);
			(*vis)->info_win = NULL;
		}
		free(*vis);
		*vis = NULL;
	}
}

int			handle_error(t_env *game, const char *str)
{
	ft_dprintf(STDERR_FILENO, str);
	if (game != NULL)
	{
		delete_players(&(game->players));
		delete_cursors(&(game->cursors));
		delete_arena(&(game->arena));
		delete_vis(&(game->vis));
		if (game->arena_color != NULL)
			ft_strdel(&(game->arena_color));
		free(game);
		game = NULL;
	}
	exit(EXIT_FAILURE);
}
