/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:03:41 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/01 05:59:25 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
// int main() {
//     const char *str = "Hello";
//     char target = '\0';
// 	char *c = memchr(str,target,5);
//     char *result = test_memchr(str,target,5);
// 	printf("%s\n ,%s ", result, c);
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("%d\n",ft_strncmp("test\200", "test\0", 6));
	printf("%d",strncmp("test\200", "test\0", 6));
	// char p[40];
	// char t[] = "lorem ipum dolor sit a";
	// ft_strlcpy(p,t, 8);
	// printf("%zu\n", ft_strlcpy(p,t, 8));
	// printf("%s\n", p);
	// strlcpy(p, t, 8);
	// printf("%lu\n", strlcpy(p, t, 8));
	// printf("%s\n", p);
}
// int ft_memcmp(const void *s1, const void *s2, size_t n);
// Deklar dyal function dialk

// int main() {
//     // Test Case 1: Same strings
//     char str1[] = "hello";
//     char str2[] = "hello";
//     int result = ft_memcmp(str1, str2, 5);
//     printf("Test Case 1 - Expected: 0, Got: %d\n", result);
// 	int resul = memcmp(str1, str2, 5);
//     printf("Test Case 1 - Expected: 0, Got: %d\n", result);

//     // Test Case 2: Different strings (first difference in middle)
//     char str3[] = "hello";
//     char str4[] = "heLlo";
//     result = ft_memcmp(str3, str4, 5);
//     printf("Test Case 2 - Expected: Non-zero, Got: %d\n", result);
// 	resul = memcmp(str3, str4, 5);
//     printf("Test Case 2 - Expected: Non-zero, Got: %d\n", resul);

//     // Test Case 3: Different lengths (only compare part)
//     char str5[] = "hello";
//     char str6[] = "hell";
//     result = ft_memcmp(str5, str6, 4);  // Compare only first 4 characters
//     printf("Test Case 3 - Expected: 0, Got: %d\n", result);
// 	resul = memcmp(str5, str6, 4);  // Compare only first 4 characters
//     printf("Test Case 3 - Expected: 0, Got: %d\n", result);

//     // Test Case 4: Completely different strings
//     char str7[] = "abcd";
//     char str8[] = "wxyz";
//     result = ft_memcmp(str7, str8, 4);
//     printf("Test Case 4 - Expected: Non-zero, Got: %d\n", result);
// 	resul = memcmp(str7, str8, 4);
//     printf("Test Case 4 - Expected: Non-zero, Got: %d\n", result);

//     // Test Case 5: Empty strings
//     char str9[] = "";
//     char str10[] = "";
//     result = ft_memcmp(str9, str10, 0);
//     printf("Test Case 5 - Expected: 0, Got: %d\n", result);
// 	resul = memcmp(str9, str10, 0);
//     printf("Test Case 5 - Expected: 0, Got: %d\n", result);

//     return (0);
// }
