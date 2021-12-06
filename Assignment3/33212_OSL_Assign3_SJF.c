//Name: Disha Chavan
//Class: TE 10		Batch: L 10
// Roll No: 33212
// SJF Algorithm


#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

void SJF(int processIds[], int burstTime[], int temp[], int arrivalTime[], int n)	// function to perform SJF
{
	
	int time = 0, i = 0, x = n, count = 0, smallest,end ;
	
	int wait_time=0 , turn_around_time=0;
	for(time = 0; count != n ; time++){
		smallest = n ;					// initialize last index
		for(i=0;i<n;i++)				
		{
			if(arrivalTime[i] <= time && burstTime[i] < burstTime[smallest] && burstTime[i] > 0) 
				smallest = i;
		}
		burstTime[smallest] -- ;
		if(burstTime[smallest] == 0){
			count++ ;
			end = time+1 ;
			wait_time = wait_time + end - arrivalTime[smallest] - temp[smallest]; // calculating wait time
                  	turn_around_time = turn_around_time + end - arrivalTime[smallest];	// calculating turn around time
		}

	}
	float avq_wait_time = (wait_time*1.0) / n ;		    // average wait time
	
	float avg_turn_around_time = (turn_around_time*1.0) / n ; // average turn around time
	
	printf("\nAverage waiting time is: %f", avq_wait_time) ;
	printf("\nAverage turn around time is: %f", avg_turn_around_time) ;
}

void main()						// main function
{
	int n ; 
	printf("Enter number of processes: ") ;
	scanf("%d", &n) ;
	int processIds[n], burstTime[n+1], temp[n], arrivalTime[n];
	for(int i = 0 ; i < n ; i++){
		printf("\nEnter process id: ") ;
		scanf("%d", &processIds[i]) ;
		printf("\nEnter burst time: ") ;
		scanf("%d", &burstTime[i]) ;
		printf("\nEnter arrival time: ") ;
		scanf("%d", &arrivalTime[i]) ;
		temp[i] = burstTime[i] ;
	}

	burstTime[n] = 9999 ;				// initialing last burst time
	
	SJF(processIds, burstTime, temp, arrivalTime, n) ; // calling sjf algorithm
}