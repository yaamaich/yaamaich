#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>


int main ()
{
	int fd = open ("text.txt", O_RDWR , 0777);
	// int ls = open ("tex.txt", O_CREAT | O_RDWR , 0777);
	// int ks = open ("te.txt", O_CREAT | O_RDWR , 0777);

		
		printf("%s" ,get_next_line(fd));
		printf("%s" ,get_next_line(fd));
		// printf("%s" ,get_next_line(ls));
		// printf("%s" ,get_next_line(ks));
		// printf("%s" ,get_next_line(fd));
}