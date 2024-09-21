/*
MT2024128
Rohan Sonawane
Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    long maxLen = sysconf(_SC_ARG_MAX);
    if (maxLen == -1) {
        perror("_SC_ARG_MAX");
    } else {
        printf("a. Maximum length of the arguments to exec functions: %ld\n",maxLen);
    }

    long maxNoOfProcesses = sysconf(_SC_CHILD_MAX);
    if (maxNoOfProcesses == -1) {
        perror("_SC_CHILD_MAX");
    } else {
        printf("b. Maximum number of simultaneous processes per user id: %ld\n", maxNoOfProcesses);
    }

    long noOfClkTck = sysconf(_SC_CLK_TCK);
    if (noOfClkTck == -1) {
        perror("_SC_CLK_TCK");
    } else {
        printf("c. Number of clock ticks (jiffy) per second: %ld\n",noOfClkTck);
    }

    long maxOpenFiles = sysconf(_SC_OPEN_MAX);
    if (maxOpenFiles == -1) {
        perror("_SC_OPEN_MAX");
    } else {
        printf("d. Maximum number of open files: %ld\n", maxOpenFiles);
    }

    long pageSize = sysconf(_SC_PAGESIZE);
    if (pageSize == -1) {
        perror("_SC_PAGESIZE");
    } else {
        printf("e. Size of a page: %ld bytes\n", pageSize);
    }

    long totalPages = sysconf(_SC_PHYS_PAGES);
    if (totalPages == -1) {
        perror("Error retrieving _SC_PHYS_PAGES");
    } else {
        printf("f. Total number of pages in physical memory: %ld\n", totalPages);
    }

    long availPages = sysconf(_SC_AVPHYS_PAGES);
    if (availPages == -1) {
        perror("_SC_AVPHYS_PAGES");
    } else {
        printf("g. Number of currently available pages in physical memory: %ld\n", availPages);
    }

    return 0;
}

/*
 
5$ ./a.out
a. Maximum length of the arguments to exec functions: 2097152
b. Maximum number of simultaneous processes per user id: 30554
c. Number of clock ticks (jiffy) per second: 100
d. Maximum number of open files: 1024
e. Size of a page: 4096 bytes
f. Total number of pages in physical memory: 1974207
g. Number of currently available pages in physical memory: 1022535
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOn

*/
