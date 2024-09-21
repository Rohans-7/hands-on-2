/*
MT2024128
Rohan Sonawane
Write a program to print the system resource limits. Use getrlimit system call.
*/
#include<sys/resource.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
	struct rlimit old_lim;
	if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0)
        printf("Old limits -> soft limit= %ld \t"
           " hard limit= %ld \n", old_lim.rlim_cur,
                                 old_lim.rlim_max);
    else
        perror("getrlimit");
	return 0;
}

/*
 rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab2$ ./a.out
Old limits -> soft limit= 1024 	 hard limit= 1048576 
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab2$ 

*/
