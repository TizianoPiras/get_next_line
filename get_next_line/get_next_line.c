/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:06:34 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/13 14:46:35 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(int fd, char *buff)
{
	char	*tmp;
	int		flag;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	flag = 1;
	while ((ft_check_nline(buff) == 0) && flag != 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[flag] = '\0':
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			res;
	char		*temp;

	*str = NULL;
	res = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (-1);
	while (res > 0)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
			return (-1);
		buf[res] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		free (temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	//*line = ft_sel(str, &res);
	temp = str;
	str = ft_select(temp);
	free(temp);
	if (res == 0 && (*str)[0] == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (res);
}
