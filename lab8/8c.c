#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void handleSigfpe(){
	printf("Cannot divide by zero.\n");
	exit(1);
}

int main(){
	signal(SIGFPE,handleSigfpe);

	int a=5,b=0;
	printf("Trying to divide by zero\n");
	int c=a/b;

	return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ ./a.out
Trying to divide by zero
Cannot divide by zero.
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ 
*/
	
