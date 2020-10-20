/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_words.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/29 14:40:13 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/18 11:50:57 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		count_words(char const *s, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	if ((s[0] != c) && (s[0] != '\0'))
		words++;
	return (words);
}
