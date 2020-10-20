/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_arg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 18:45:52 by rheuts        #+#    #+#                 */
/*   Updated: 2020/09/17 18:45:59 by rheuts        ########   odam.nl         */
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
