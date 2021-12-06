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

void RoundRobin(int processIds[], int burstTime[], int temp[], int arrivalTime[], int n, int quantum) // function to implement round robin algorithm
{
	
	int tot = 0, i = 0, x = n, count = 0 ;
	
	int wait_time=0 , turn_around_time=0;
	for(tot = 0, i=0 ; x!=0;){
		if(temp[i] <=quantum && (temp[i] > 0)){    // if time is less than quantum
			tot = tot + temp[i] ;
			temp[i] = 0 ;
			count = 1 ;
		}
		else if(temp[i]>0){			     // if time is greater than quantum
			temp[i] = temp[i] - quantum ;
			tot += quantum ; 
		}
		
		
		if(temp[i] == 0 && count==1){		 
			x--;
			wait_time = wait_time + tot - arrivalTime[i] - burstTime[i];
			turn_around_time += (tot-arrivalTime[i]) ;
			count = 0 ;
			
		}
		if(i == n-1) i=0 ;
		else if(arrivalTime[i+1] <=tot) i++ ;
		else i=0 ;
	}								
	float avq_wait_time = (wait_time*1.0) / n ;			// calculating average wait time
	
	float avg_turn_around_time = (turn_around_time*1.0) / n ;	// calculating average turn around time
	
	printf("\nAverage waiting time is: %f", avq_wait_time) ;
	printf("\nAverage turn around time is: %f", avg_turn_around_time) ;
}

void main(){								// main function
	int n ; 
	printf("Enter number of processes: ") ;
	scanf("%d", &n) ;
	int processIds[n], burstTime[n], temp[n], arrivalTime[n], quantum ;
	for(int i = 0 ; i < n ; i++){
		printf("\nEnter process id: ") ;
		scanf("%d", &processIds[i]) ;
		printf("\nEnter burst time: ") ;
		scanf("%d", &burstTime[i]) ;
		printf("\nEnter arrival time: ") ;
		scanf("%d", &arrivalTime[i]) ;
		temp[i] = burstTime[i] ;
	}
	printf("Enter quantum value: ") ;
	scanf("%d", &quantum) ;
	
	RoundRobin(processIds, burstTime, temp, arrivalTime, n ,quantum) ;
}