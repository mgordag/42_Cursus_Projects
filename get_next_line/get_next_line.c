/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 00:51:14 by gkorkmaz          #+#    #+#             */
/*   Updated: 2022/03/14 12:13:24 by gunjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s;/*burada strlende her çağırdığımızda i yi sıfırdan alıyoruz  fkat burada program bitene kadar static yoluyla her çağrıldığında kaldığı               yerden devam ediyor*/
	char		*dest;
	char		*buffer;
	int			size;

	buffer = malloc(BUFFER_SIZE + 1);
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	dest = ft_substr(s, 0, ft_strchr(s, '\n') - s + 1);
	s = move_line(s);
	free(buffer);// satır atladığımızda bir önceki buffer ını yani bellekte ayırdığı yeri temizliyor.
	return (dest);
}
