/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 13:32:36 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			i;
	unsigned int	src_len;

	src_len = 0;
	i = 0;
	while (src[i] != '\0')
	{
		src_len++;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (i < src_len)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
