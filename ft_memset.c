/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaymaz <asaymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:30:36 by asaymaz           #+#    #+#             */
/*   Updated: 2025/06/10 15:44:35 by asaymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	while (i < n)
	{
		ptr[i] = val;
		i++;
	}
	return (s);
}

// int main()
// {
//     char    arr1[20];

//     ft_memset(arr1, 'X', 5);
//     printf("ft_memset(arr1, 'X', 5): %s (Beklenen: XXXXX)\n", arr1);

// }