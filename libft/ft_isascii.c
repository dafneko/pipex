/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:13:23 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/26 05:40:30 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
//  {
// 	char c, result;

// 		c = '*';
// 	result = ft_isascii(c + 256);
// 		printf("The result is %d\n", result);

// 		c = 'B';
// 	result = ft_isascii(c + 256);
// 		printf("The result is %d\n", result);

// 		c = '+';
// 	result = ft_isascii(c);
// 		printf("The result is %d\n", result);
// 	return (0);
// }
 
