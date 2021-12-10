/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:36:55 by cnotin            #+#    #+#             */
/*   Updated: 2020/06/29 19:36:58 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinf(char *s1, char *s2, size_t rm, size_t len)
{
	char			*new_s;

	if ((int)rm < 0 || (int)rm > 3)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_s == NULL)
		return (NULL);
	ft_strcpy(new_s, s1);
	ft_strncat(new_s, s2, len);
	if (rm == 1 || rm == 3)
		ft_strdel(&s1);
	if (rm == 2 || rm == 3)
		ft_strdel(&s2);
	return (new_s);
}
