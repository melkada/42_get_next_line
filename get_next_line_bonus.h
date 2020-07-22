/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.h                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-kada <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 20:53:48 by mel-kada     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 20:59:31 by mel-kada    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_FD 10000

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_line(char *s);

#endif
