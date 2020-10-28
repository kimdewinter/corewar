/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lldi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 18:23:19 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** Function that implements the operation lldi
**
** Usage:
**  Argument 1: T_REG/T_DIR/T_IND
**  Argument 2: T_REG/T_DIR
**  Argument 3: T_REG
**
** Read four bytes at the address: 'cursor position + first argument +
** second argument' and store the result in the registry with the
** index of the third argument.
*/

void	op_lldi(t_env *game, t_cursor *cur)
{
	if (cur->op.t_arg[0] == T_REG)
		cur->arg[0] = cur->registries[cur->arg[0]];
	else if (cur->op.t_arg[0] == T_IND)
		cur->arg[0] = get_val(game, cur->pos + (cur->arg[0] % IDX_MOD), \
		DIR_SIZE);
	if (cur->op.t_arg[1] == T_REG)
		cur->arg[1] = cur->registries[cur->arg[1]];
	cur->registries[cur->arg[2]] = get_val(game, cur->pos + cur->arg[0] + \
	cur->arg[1], DIR_SIZE);
	if (cur->registries[cur->arg[2]] == 0)
		cur->carry = 1;
	else
		cur->carry = 0;
}
