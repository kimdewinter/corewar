/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lfork.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 20:42:26 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/30 13:38:14 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_lfork(t_env *game, t_cursor *cur)
{
	t_cursor	*new;

	new = new_cursor(game);
	*new = *cur;
	add_cursor(&game->cursors, new);
	new->pos = (new->pos + cur->arg[0]) % MEM_SIZE;
	while (new->pos < 0)
		new->pos += MEM_SIZE;
	game->cursor_total++;
	new->pid = game->cursor_total;
	reset_op(new);
}
