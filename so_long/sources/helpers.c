/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:30:21 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:34:56 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	*allocate_and_zero_memory(size_t total_size)
{
	void	*ptr;

	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;

	if (nmemb == 0 || size == 0)
		return (allocate_and_zero_memory(1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	return (allocate_and_zero_memory(total_size));
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

