/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:59:37 by mrital-           #+#    #+#             */
/*   Updated: 2022/12/07 15:52:47 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	char	*ptr;
	size_t	i;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	new = malloc(ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1);
	if (!new)
		return (0);
	ptr = new;
	i = 0;
	while (s1[i])
		*new ++ = s1[i++];
	i = 0;
	while (s2[i])
		*new ++ = s2[i++];
	*new = 0;
	free(s1);
	return (ptr);
}

char	*ft_strchr(char *str)
{
	if (!str)
		return (0);
	while (*str && *str != '\n')
		str++;
	if (!*str && *str != '\n')
		return (0x00000000);
	return (str);
}
