/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arg_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:07:33 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int		get_arg_size(t_ins *ins, int arg_type)
{
	int	argument_types[3];

	argument_types[0] = REG_SIZE;
	argument_types[1] = ins->t_dir_size;
	argument_types[2] = IND_SIZE;
	return (argument_types[arg_type - 1]);
}
