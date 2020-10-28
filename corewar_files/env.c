/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 19:14:14 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** new_env
**  returns a structure env where game data is stored.
*/

t_env		*new_env(int argc, char **argv)
{
	t_env	*new;

	new = (t_env *)ft_memalloc(sizeof(t_env));
	if (new == NULL)
		return (0);
	new->argc = argc;
	new->argv = argv;
	new->flag_dump = -1;
	return (new);
}
