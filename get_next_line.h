/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:59:33 by mrital-           #+#    #+#             */
/*   Updated: 2022/12/04 22:25:20 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_subline(char *stash);
char	*get_next_line(int fd);
char	*ft_read(char *str, int fd);
size_t	ft_strlen(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str);
char	*ft_check_cut(char *str);

#endif