/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:59:30 by mrital-           #+#    #+#             */
/*   Updated: 2022/12/04 22:14:38 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *s, int fd)
{
	char	*sub;
	int		i;

	sub = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 1;
	while (!ft_strchr(s) && i != 0)
	{
		i = read(fd, sub, BUFFER_SIZE);
		if (i < 0)
		{
			free(s);
			free(sub);
			return (NULL);
		}
		sub[i] = '\0';
		s = ft_strjoin(s, sub);
	}
	free(sub);
	return (s);
}

char	*sub_line(char *s)
{
	int		x;
	char	*new;

	x = 0;
	if (!s[x])
		return (NULL);
	while (s[x] && s[x] != '\n')
		x++;
	new = (char *)malloc(sizeof(char) * (x + 2));
	if (!new)
		return (NULL);
	x = 0;
	while (s[x] && s[x] != '\n')
	{
		new[x] = s[x];
		x++;
	}
	if (s[x] == '\n')
	{
		new[x] = s[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}

char	*trash(char *str)
{
	int		j;
	int		i;
	char	*fake;

	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (!str[j])
	{
		free(str);
		return (NULL);
	}
	fake = (char *)malloc((ft_strlen(str, '\0') - j + 1));
	if (!fake)
		return (NULL);
	j++;
	i = 0;
	while (str[j])
		fake[i++] = str[j++];
	fake[i] = '\0';
	free(str);
	return (fake);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	line = sub_line(str);
	str = trash(str);
	return (line);
}
// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("test", O_RDONLY);
// 	while ((s = get_next_line(fd)))
// 		printf("%s", s);
// 	return (0);
// }
