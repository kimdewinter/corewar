/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_spaces.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 20:02:54 by svan-der      #+#    #+#                 */
/*   Updated: 2020/09/16 01:27:58 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		count_spaces_end(char const *s, int len)
{
	int		i;
	int		spaces;

	i = len;
	spaces = 0;
	while (i > 0)
	{
		if (s[i - 1] == 32 || s[i - 1] == '\n' || s[i - 1] == '\t')
			spaces++;
		else
			break ;
		i--;
	}
	return (spaces);
}

int		count_spaces_start(char const *s)
{
	int		i;
	int		spaces;

	i = 0;
	spaces = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
			spaces++;
		else
			break ;
		i++;
	}
	return (spaces);
}
