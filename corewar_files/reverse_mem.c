/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_mem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 14:11:05 by lravier       #+#    #+#                 */
/*   Updated: 2020/10/26 14:47:58 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	reverse_mem(void *s, size_t n)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*mem;

	i = 0;
	mem = (unsigned char *)s;
	while (i < n - i)
	{
		c = mem[i];
		mem[i] = mem[n - i];
		mem[n - i] = c;
		i++;
	}
}
