// Disha Chavan
// Class: TE 10	Batch: L 10
// Problem statement: Implement the C program in which main program accepts the integers to be sorted. Main program
// uses the FORK system call to create a new process called a child process. Parent process sorts the
// integers using sorting algorithm and waits for child process using WAIT system call to sort the integers
// using any sorting algorithm


#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#define MAX 10

void bubbleSort(int arr[], int n)			// function to perform bubble sort on array
{
   int i, j;			
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1]){
           	int temp = arr[j] ;
           	arr[j] = arr[j+1] ;
           	arr[j+1] = temp ;
           }
              
}
int main(int argc, char* argv)			// main method
{
	pid_t pid;					// variable for process id
	int num_bubblesort ;				// variable for number of elements in array
	
	printf("Enter number of elements in array to be sorted by bubble sort: ") ;
	scanf("%d", &num_bubblesort) ;
	
	printf("Enter elements in array to be sorted by bubblesort: ") ;
	
	int arr_b[num_bubblesort] ;
	for(int i = 0 ; i < num_bubblesort ; i++)
		scanf("%d", &arr_b[i]) ;
		
		
	printf("\n");
	printf("\nPerforming Bubble sort...\n");
	printf("\nBefore sorting\n");
	printf("\n------------------------------------------------------------------------------\n") ;
	for(int i = 0 ; i < num_bubblesort ; i++ ){
		printf("%d, ", arr_b[i]) ;
	}
	printf("\n------------------------------------------------------------------------------\n") ;
	
	
	bubbleSort(arr_b, num_bubblesort) ;		// sorting array using bubblesort function
	
	
	printf("\nAfter sorting\n");
	printf("\n------------------------------------------------------------------------------\n") ;
	for(int i = 0 ; i < num_bubblesort ; i++ ){
		printf("%d, ", arr_b[i]) ;
	}
	printf("\n------------------------------------------------------------------------------\n") ;
	printf("\nBubble sort complete\n");

	pid=fork();						// using fork method to generate process id
	
	if(pid==0)						// in case of a child process
	{
  
		  printf("\nThis is Child Process...%d",getpid());
		  
		  char *arg[num_bubblesort+1];		// char array to be passed to reverseArr program 
		  int i ;
		  arg[0] = "./reverseArr" ;		
		  		
 		  for(i = 1 ; i < num_bubblesort+1 ; i++){	// loop to copy integers of array as characters in array to passed as argument
 		  
		  	arg[i] = malloc(20) ;			
		  	snprintf(arg[i],20, "%d", arr_b[i-1]) ;
		  }
		  		  
		  arg[i] = NULL ;				// ending char array with null
		  
		  execv("./reverseArr", arg) ;		// execv calls other program and passes commandline argument as arg array
		  printf("\nExiting from child") ;
		  
	}
	else if(pid>0)						// in case of a parent process
	{
		printf("\nParent process...%d \n",getpid());
		wait();
		
	}
	else{							// if process is not created
		exit(-1) ;
	}
	return(0);
}

/*Output
disha@disha-VirtualBox:~$ ./OsAssign2Barr 
Enter number of elements in array to be sorted by bubble sort: 5
Enter elements in array to be sorted by bubblesort: 4 1 5 2 3


Performing Bubble sort...

Before sorting

------------------------------------------------------------------------------
4, 1, 5, 2, 3, 
------------------------------------------------------------------------------

After sorting

------------------------------------------------------------------------------
1, 2, 3, 4, 5, 
------------------------------------------------------------------------------

Bubble sort complete

Parent process...4146 


In program reverseArr.c

Array in reverse format
5, 4, 3, 2, 1, 
*/