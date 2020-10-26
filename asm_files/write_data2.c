/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_data2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/05 15:26:36 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** Takes an array as an arg
** arr[0] is the 1st argument of an instruction
** arr[1] is the 2nd argument of an instruction
** arr[2] is the 3rd argument of an instruction
** Takes 1 (0b01) as T_REG
** Takes 2 (0b10) as T_DIR
** Takes 3 (0b11) as T_IND
** Takes 0 as NO argument
*/

int		enc_byte(int *arr)
{
	return (arr[0] << 6 | arr[1] << 4 | arr[2] << 2);
}

/*
** Function that converts the argument to 2's complement
** Flips all bits, and then adds 1 to make it 2's complement
*/

int		make_twoscomplement(int value)
{
	value = (~value) + 1;
	return (value);
}

/*
**	Writes strings in reverse, big-endian, to FD.
*/

void	ft_rnputstr(int fd, unsigned char *str, int len)
{
	while (len > 0)
	{
		len--;
		write(fd, &str[len], 1);
	}
}

/*
** Writes 4 NULL-bytes to FD.
*/

void	write_null(int fd)
{
	int		i;

	i = 0;
	write(fd, &i, sizeof(int));
}
