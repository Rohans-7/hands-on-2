/*
Rohan Sonawane
MT2024128
6. Write a simple program to create three threads.
*/
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void *thread_fun(){
	printf("Thread executing\n");
	 pthread_exit(NULL); 
}

int main(){
	pthread_t threads[3];

	int threadVal;

	for(int i=0; i<3; ++i){
		 threadVal=pthread_create(&threads[i],NULL,thread_fun,NULL);

		 if(threadVal){
			 fprintf(stderr,"Error creating threads");
			 exit(1);
		 }
	}
	 
	for(int i=0; i<3; ++i){
		threadVal=pthread_join(threads[i],NULL);
		if(threadVal){
			fprintf(stderr,"Error joining the threads");
			exit(1);
		}
	}
	printf("created all threads");
	return 0;
}

/*

rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab6$ ./a.out
Thread executing
Thread executing
Thread executing
created all threadsrohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab6$ 

*/
