/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 16:35:04 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int s1_len;

	i = 0;
	s1_len = 0;
	while (s1[i] != '\0')
	{
		s1_len++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s1[s1_len] = s2[i];
		i++;
		s1_len++;
	}
	s1[s1_len] = '\0';
	return (s1);
}
