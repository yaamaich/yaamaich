/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:16:48 by yaamaich          #+#    #+#             */
/*   Updated: 2024/07/07 22:16:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	g;

	i = 0;
	g = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (g == 1)
			{
				str[i] -= 32;
				g = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			g = 0;
		}
		else
			g = 1;
		i++;
	}
	return (str);
}

/*int main()
{
	char arr[] = "salut, comMEnt tu vas ? 42Mots quarante-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize (arr));
	return 0;
}*/