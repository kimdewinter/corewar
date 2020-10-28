/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 15:46:21 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*copy;
	int		sp_start;
	int		sp_end;
	int		len;

	sp_start = 0;
	sp_end = 0;
	len = ft_strlen(s);
	sp_start = count_spaces_start(s);
	sp_end = count_spaces_end(s, len);
	if ((sp_start == len) && (sp_end == len))
		copy = "";
	else
	{
		copy = (char *)malloc(sizeof(char) * ((len - sp_start - sp_end) + 1));
		if (copy == NULL)
			return (NULL);
		copy = ft_strsub(s, sp_start, len - sp_start - sp_end);
	}
	return (copy);
}
