/*
MT2024128
Rohan Sonawane
Write a program to print the system resource limits. Use getrlimit system call.
*/
#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

int main() { 

	struct rlimit old_lim, lim, new_lim; 

	if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0) 
		printf("Old limits -> soft limit= %ld \t"
		" hard limit= %ld \n", old_lim.rlim_cur, 
								old_lim.rlim_max); 
	else
		perror("getrlimit");

	lim.rlim_cur = 3; 
	lim.rlim_max = 1024; 

	if(setrlimit(RLIMIT_NOFILE, &lim) == -1) 
		perror("setrlimit");

	if( getrlimit(RLIMIT_NOFILE, &new_lim) == 0) 
		printf("New limits -> soft limit= %ld "
		"\t hard limit= %ld \n", new_lim.rlim_cur, 
								new_lim.rlim_max); 
	else
		perror("getrlimit");
	return 0; 
} 

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab3$ gcc 3.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab3$ ./a.out
Old limits -> soft limit= 1024 	 hard limit= 1048576 
New limits -> soft limit= 3 	 hard limit= 1024 
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab3$ 

*/
