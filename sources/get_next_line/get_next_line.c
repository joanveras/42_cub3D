/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:19:25 by marcribe          #+#    #+#             */
/*   Updated: 2025/05/15 22:28:57 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_check(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

static char	*get_bkp(char *line)
{
	size_t	count;
	char	*bkp;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	bkp = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*bkp == '\0')
	{
		free(bkp);
		bkp = NULL;
	}
	line[count +1] = '\0';
	return (bkp);
}

static char	*get_line(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*s_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!bkp)
			bkp = ft_strdup("");
		s_temp = bkp;
		bkp = ft_strjoin(s_temp, buf);
		free(s_temp);
		s_temp = NULL;
		if (ft_check (buf, '\n'))
			break ;
	}
	return (bkp);
}

char	*get_next_line(int fd)
{
	static char	*bkp;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, bkp);
	free(buffer);
	if (!line)
		return (NULL);
	bkp = get_bkp(line);
	return (line);
}
