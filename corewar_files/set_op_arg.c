/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_op_arg.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 16:17:52 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** Set the type of argument(s) for the operation.
*/

int		set_op_arg(t_env *game, t_cursor *cur)
{
	if (g_op_tab[cur->op.id].encode == TRUE)
		return (decode_op(game, cur));
	else
		cur->op.t_arg[0] = T_DIR;
	return (1);
}
