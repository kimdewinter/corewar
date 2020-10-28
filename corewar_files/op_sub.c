/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_sub.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 22:23:57 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** Function that implements the operation sub
**
** Usage:
**  Argument 1: T_REG
**  Argument 2: T_REG
**  Argument 3: T_REG
**
** Subtract the registry values with the indexes of the first and second
** argument and store the result in the registry with the index of the third
** argument.
*/

void		op_sub(t_env *game, t_cursor *cur)
{
	(void)game;
	cur->registries[cur->arg[2]] =
	cur->registries[cur->arg[0]] - cur->registries[cur->arg[1]];
	if (cur->registries[cur->arg[2]] == 0)
		cur->carry = 1;
	else
		cur->carry = 0;
}
