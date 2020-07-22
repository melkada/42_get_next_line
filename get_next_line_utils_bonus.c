/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils_bonus.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-kada <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 20:54:30 by mel-kada     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 20:54:37 by mel-kada    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ptr = (char *)malloc((sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*address_to_free;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	i = -1;
	address_to_free = s1;
	while (*s1)
		ptr[++i] = *s1++;
	while (*s2)
		ptr[++i] = *s2++;
	ptr[++i] = 0;
	if (address_to_free != NULL)
		free(address_to_free);
	address_to_free = NULL;
	return (ptr);
}

int		ft_check_line(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
