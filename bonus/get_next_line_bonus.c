/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:10:40 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/13 20:24:09 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*return_value(char **s)
{
	char	*res;
	int		i;
	char	*str;

	i = 0;
	if (!*s || !s)
		return (NULL);
	str = *s;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	if (*(str + i) == '\n')
		i++;
	res = ft_str_dup(str, i - 1);
	*s = ft_str_dup(str + i, ft_str_len(str + i));
	return (free(str), str = NULL, res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buff;
	ssize_t		byte_read ;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (free(res), res = NULL, NULL);
	buff = (char *)malloc(sizeof (char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	byte_read = 9;
	while (byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buff), buff = NULL, NULL);
		buff[byte_read] = '\0';
		res = ft_join(res, buff);
		if (chec_new_line(res))
			break ;
	}
	return (free(buff), buff = NULL, return_value(&res));
}

void	sp_close(int fd1, int fd2, int fd3)
{
	close(fd1);
	close(fd2);
	close(fd3);
}
