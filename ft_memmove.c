/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaymaz <asaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:44:45 by asaymaz           #+#    #+#             */
/*   Updated: 2025/06/10 18:08:36 by asaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	temp_dest = dest;
	temp_src = src;
	i = 0;
	if (temp_dest > temp_src)
	{
		while (n > 0)
		{
			temp_dest[n] = temp_src[n];
			n--;
		}
	}
	else
		while (i++ < n)
			temp_dest[i] = temp_src[i];
	return (dest);
}
