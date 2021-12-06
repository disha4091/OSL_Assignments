// Disha Chavan
// Class: TE 10	Batch: L 10
// Roll No: 33212
// Program to reverse array


#include<stdio.h>
#include<string.h>

int main( int argc, char *argv[])		// string command line arguments with array size and array
{

	printf("\nIn program reverseArr.c\n") ;

	int arr[argc-1] ;			
	int i = 0 ,x ;
	for( i = 1 ; i < argc; i++){
   		arr[i-1] = atoi(argv[i]) ;
	}
	
	printf("\nArray in reverse format\n") ;
	for(int i = argc-2 ; i >= 0; i--){
		printf("%d, " , arr[i]) ;
	}

	printf("\n") ;
	return(0) ;
	
	
}