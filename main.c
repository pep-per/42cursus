#include <errno.h>
// #include <string.h>
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	FILE *fp;
	// printf("%s\n", strerror(ENOMEM));
	fp = fopen( "nofile.c", "r");  
	// perror(strerror(errno));
	printf("%s\n", strerror(errno));
}