/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 16:38:49 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*result;

	result = (unsigned char *)b;
	c1 = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		result[i] = c1;
		i++;
	}
	return (result);
}
