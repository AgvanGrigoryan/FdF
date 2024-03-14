/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:06:08 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/14 11:46:14 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strcat(char *dest, char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_cs(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*cut(char *str, char *charset, int s)
{
	int		n;
	int		i;
	int		end;
	char	*cur;

	n = 0;
	i = 0;
	end = 0;
	while (is_cs(str[i], charset) == 1)
		i++;
	while (n != s)
	{
		if (is_cs(str[i], charset) && !(is_cs(str[i + 1], charset)))
			n++;
		i++;
	}
	end = i;
	while (!is_cs(str[end], charset) && (str[end + 1] != '\0')
		&& !is_cs(str[end + 1], charset))
		end++;
	cur = (char *)malloc((end - i + 2) * sizeof(char));
	if (cur == NULL)
		return (NULL);
	ft_strcat(cur, str, i, end);
	return (cur);
}

int	wc(char *str, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (is_cs(str[i], charset) && (str[i + 1] != '\0'))
		i++;
	while (str[i] != '\0')
	{
		if (!is_cs(str[i], charset) && (((is_cs(str[i + 1], charset)))
				|| (str[i + 1] == '\0')))
			len++;
		i++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	len = wc(str, charset);
	result = (char **)malloc((len + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = cut(str, charset, i);
		i++;
	}
	result[i] = 0;
	return (result);
}
