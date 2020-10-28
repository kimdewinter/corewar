/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 19:35:27 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	total_size;
	size_t	i;

	src_size = 0;
	dst_size = 0;
	i = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size == 0)
		return (src_size + size);
	while (dst[dst_size] != '\0')
		dst_size++;
	total_size = src_size + dst_size;
	while ((dst_size < (size - 1)) && (src[i] != 0))
	{
		dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	dst[dst_size] = '\0';
	if (dst_size > size)
		return (src_size + size);
	return (total_size);
}
