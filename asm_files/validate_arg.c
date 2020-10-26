/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_arg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:45:52 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int		arg_type_validation(int opcode, int arg_type, size_t arg_index)
{
	size_t	bit_shift;
	size_t	optab;

	bit_shift = arg_type - 1;
	optab = g_op_tab[opcode - 1].args_type[arg_index];
	return (optab & (1 << bit_shift));
}
