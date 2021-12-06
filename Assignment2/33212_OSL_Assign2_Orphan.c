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

int partition(int arr[], int low, int high){			// function used to get partition element in quicksort
	int pivot = arr[high] ;
	int i = low-1 ;
	for(int j = low ; j<=high-1 ;j++){
		if(arr[j] < pivot){
			i++ ;
			int temp = arr[i] ;
			arr[i] = arr[j] ;
			arr[j] = temp ;
		}
	}
	int temp = arr[i+1] ;
	arr[i+1] = arr[high] ;
	arr[high] = temp ;
	return i+1 ;
}

void quicksort(int arr[], int low, int high){			// function to sort array using quicksort
	if(low < high){
		int j = partition(arr,low,high) ;
		quicksort(arr, low, j-1) ;
		quicksort(arr, j+1, high) ; 
	}	
}

void merge(int arr[], int l, int m, int r){			// function to merge arrays into a sorted array
	int i , j , k ;
	int lenA = m-l+1 ;
	int lenB = r-m ;
	
	int A[lenA], B[lenB] ;
	for(i = 0 ; i < lenA ; i++){
		A[i] = arr[l+i] ;
	}
	for(j = 0 ; j < lenB ; j++){
		B[j] = arr[m+1+j] ;
	}
	i = 0 ;
	j= 0 ; 
	k = l ;
	while(i<lenA && j <lenB){
		if(A[i] <= B[j]){
			arr[k]=A[i] ;
			i++ ;
		}
		else{
			arr[k] = B[j] ;
			j++ ;
		}
		k++ ;
	}
	
	while(i<lenA){
		arr[k] = A[i] ; 
		i++ ;
		k++ ;
	}
	while(j<lenB){
		arr[k] = B[j] ; 
		j++ ;
		k++ ;
	}
}

void mergesort(int arr[], int low, int high)			// function to sort array using mergesort
{
    if (low < high) {
        int m = (low + high) / 2;
        mergesort(arr, low, m);
        mergesort(arr, m + 1, high);
        merge(arr, low, m, high);
    }
}


int main()							// main method
{
	pid_t pid;						// variable for process id
	int num_quick, num_merge ;
	
	printf("Enter number of elements in array to be sorted by quicksort: ") ;
	scanf("%d", &num_quick) ;
	
	printf("Enter elements in array to be sorted by quicksort: ") ;
	int arr_q[num_quick] ;
	for(int i = 0 ; i < num_quick ; i++)
		scanf("%d", &arr_q[i]) ;
		
	
	printf("Enter number of elements in array to be sorted by mergesort: ") ;
	scanf("%d", &num_merge) ;
	
	printf("Enter elements in array to be sorted by mergesort: ") ;
	int arr_m[num_merge] ;
	for(int i = 0 ; i < num_merge ; i++)
		scanf("%d", &arr_m[i]) ;

	pid=fork();						// using fork method to generate process id
	if(pid < 0){						// if process is not created
		exit(-1) ;
	}
	if(pid==0)						// in case of a child process
	{
		  printf("\n==============================================================================") ;
		  printf("\nThis is Child Process...%d",getpid());
		  printf("\nParent process Id is...%d",getppid());
		  printf("\nThis is orphan state");
		  sleep(10);
		  printf("\nPerforming Quick sort...\n");
		  quicksort(arr_q, 0, num_quick-1) ;
		  printf("\nAfter sorting\n");
		  printf("\n------------------------------------------------------------------------------\n") ;
		  for(int i = 0 ; i < num_quick ; i++ ){
		  	printf("%d, ", arr_q[i]) ;
		  }
		  printf("\n------------------------------------------------------------------------------\n") ;
		  printf("\nQuick sort complete\n");
		  printf("\n==============================================================================") ;
	}
	else
	{
	        printf("\n==============================================================================") ;
		printf("\nParent process...%d",getpid());
		printf("\n");
		printf("\nPerforming Merge sort...\n");
		mergesort(arr_m, 0, num_merge-1) ;
		printf("\nAfter sorting\n");
		printf("\n------------------------------------------------------------------------------\n") ;
		for(int i = 0 ; i < num_merge ; i++ ){
			printf("%d, ", arr_m[i]) ;
		}
		printf("\n------------------------------------------------------------------------------\n") ;
		printf("\nMerge sort complete\n");
		exit(0);
		printf("\n==============================================================================") ;
	}
	return(0);
}


/*Output
disha@disha-VirtualBox:~$ ./OsAssign2orphan 
Enter number of elements in array to be sorted by quicksort: 5
Enter elements in array to be sorted by quicksort: 5
2
3
4
1
Enter number of elements in array to be sorted by mergesort: 5
Enter elements in array to be sorted by mergesort: 9
6
7 
8
5

==============================================================================
Parent process...2194

Performing Merge sort...

After sorting

------------------------------------------------------------------------------
5, 6, 7, 8, 9, 
------------------------------------------------------------------------------

Merge sort complete

==============================================================================
This is Child Process...2196
Parent process Id is...1297
disha@disha-VirtualBox:~$ This is orphan state
Performing Quick sort...

After sorting

------------------------------------------------------------------------------
1, 2, 3, 4, 5, 
------------------------------------------------------------------------------

Quick sort complete

==============================================================================

*/