/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 17:50:21 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:51:41 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	init_vars(int *i, int *j, int *len, int *found)
{
	*i = 0;
	*j = 0;
	*len = 0;
	*found = 0;
}

static void	fill_array(char **array, char const *s, char c, int words)
{
	int		i;
	int		j;
	int		len;
	int		found;

	init_vars(&i, &j, &len, &found);
	while (j < words)
	{
		len = 0;
		found = 0;
		while (s[i] != '\0' && found == 0)
		{
			while (s[i] != c && s[i] != '\0' && found == 0)
			{
				len++;
				i++;
				if (s[i] == c)
					found = 1;
			}
		}
		if (len != 0)
			array[j] = ft_strsub(s, i - len, len);
		i++;
		j++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;

	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	fill_array(array, s, c, words);
	array[words] = 0;
	return (array);
}
