/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:53:03 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/13 14:36:09 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	itoc;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != itoc)
		i++;
	if (s[i] == '\0' && itoc != '\0')
		return (NULL);
	return ((char *) s + i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_final;
	int		size_s1;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	s_final = (char *)malloc((size_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!s_final)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		s_final[i] = s1[i];
		i++;
	}
	size_s1 = 0;
	while (size_s1 < ft_strlen(s2))
	{
		s_final[i] = s2[size_s1];
		i++;
		size_s1++;
	}
	s_final[i] = '\0';
	return (s_final);
}
