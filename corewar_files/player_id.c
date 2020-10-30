/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_id.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 18:50:04 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/30 13:56:54 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	assign_rest_id(t_env *game, t_player **rank)
{
	t_player	*walker;
	size_t		i;

	walker = game->players;
	i = game->champ_count;
	while (i > 0)
	{
		i--;
		if (rank[i] == NULL)
		{
			while (walker && walker->id != 0)
				walker = walker->next;
			rank[i] = walker;
			walker->id = i + 1;
		}
	}
}

static void	assign_flag_id(t_env *game, t_player **rank)
{
	t_player	*walker;

	walker = game->players;
	while (walker)
	{
		if (walker->rank_n > game->champ_count)
			handle_error(game, "[Error] A player ID can not exceed " \
			"the number of players\n");
		else if (walker->id == 0 && walker->rank_n != 0)
		{
			if (rank[walker->rank_n - 1] != NULL)
				handle_error(game, "[Error] Players can not have the " \
				"same ID\n");
			walker->id = walker->rank_n;
			rank[walker->id - 1] = walker;
		}
		walker = walker->next;
	}
}

int			assign_id(t_env *game)
{
	t_player	**rank;

	rank = (t_player **)ft_memalloc(sizeof(t_player *) * \
	(game->champ_count + 1));
	if (!rank)
		handle_error(game, "[Error] Failed memory allocation\n");
	if (game->champ_count > MAX_PLAYERS)
		handle_error(game, "[Error] The number of players exceed the " \
		"game limit\n");
	if (game->champ_count == 0)
		handle_error(game, "[Error] Missing players\n");
	assign_flag_id(game, rank);
	assign_rest_id(game, rank);
	free(rank);
	return (1);
}

t_player	*get_id(t_env *game, int id)
{
	t_player	*walker;

	walker = game->players;
	while (walker)
	{
		if (walker->id == id)
			return (walker);
		walker = walker->next;
	}
	return (NULL);
}
