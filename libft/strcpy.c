/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:02:09 by ygudusze          #+#    #+#             */
/*   Updated: 2013/12/16 13:40:59 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = '\0';
	return (s1);
}