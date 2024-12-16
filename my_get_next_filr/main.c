#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <libc.h>


int main ()
{
	int fd = open ("text.txt", O_CREAT | O_RDWR , 0777);
		
		printf("%s" ,get_next_line(fd));
		printf("%s" ,get_next_line(fd));
		printf("%s" ,get_next_line(fd));
		printf("%s" ,get_next_line(fd));
}