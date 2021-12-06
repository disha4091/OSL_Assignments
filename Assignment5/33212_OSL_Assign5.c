// Name: Disha Chavan
// Class: TE 10		Batch: L 10
// Roll No: 33212
// Bankers algorithm

# include<stdio.h>
# define MAX 10 ;

int m , n ;		// m = number of resources and n = number of processes ;
void bankersAlgo(int allocation[n][m], int max[n][m], int available[m], int need[n][m] ){
	int finish[n], result[n] ;
	int index = 0 ;	
	for(int i=0; i<n ; i++){				// initialize finish array for processes with 0
		finish[i] = 0 ;
	}
	printf("\n===================================================================\n") ;
	printf("\nAllocation Matrix is: \n") ;
	
	for(int i=0;i<n ;i++){
		for(int j=0; j<m; j++){
			printf("%d ", allocation[i][j]) ;		
		}
		printf("\n") ;	
	}
	printf("\n===================================================================\n") ;	
	printf("\nMax Matrix is: \n") ;
	
	for(int i=0;i<n ;i++){
		for(int j=0; j<m; j++){
			printf("%d ", max[i][j]) ;	
		}
		printf("\n") ;	
	}
	printf("\n===================================================================\n") ;	
	printf("\nAvailable Matrix is: \n") ;
	
	for(int i=0;i<m ;i++){
		printf("%d ", available[i]) ;	
	}
	printf("\n===================================================================\n") ;	
	printf("\nNeed Matrix is: \n") ;
	
	for(int i=0;i<n ;i++){
		for(int j=0; j<m; j++){
			need[i][j] = max[i][j] - allocation[i][j] ; 	// calculating need matrix
			printf("%d ", need[i][j]) ;
			
		}
		printf("\n") ;	
	}
	printf("\n===================================================================\n") ;	

	
			
	for(int k=0; k<n; k++){
		for(int i=0 ; i<n ;i++){
			if(finish[i] == 0){				// if process is not finished
				int flag=0 ;
				for(int j=0;j<m;j++){			// checking if need matrix is less than or equal to the work/available matrix
					if(need[i][j]<=available[j])
						continue ;
					else{
						flag = 1 ;
						break ;
					}		
				}
				
				if(flag == 0){				// only if condition is satisfied
					result[index++] = i ;		// add process to result array/sequence
					for(int p=0; p<m; p++){	// add allocation of that process to the available matrix 
						available[p]+=allocation[i][p] ;
					}
					finish[i] = 1 ;		// mark process as finished
				}
			}
		}
	}
	printf("\n===================================================================\n") ;
	printf("\nSequence of processes is: ") ;
	for(int i=0 ;i<n; i++)
		printf("P%d, ", result[i]) ;
		
	printf("\n===================================================================\n") ;
}
void main(){
	
	printf("\nEnter number of process: ") ;
	scanf("%d",&n) ;
	printf("\nEnter number of resources: ") ;
	scanf("%d",&m) ;
	int allocation[n][m], max[n][m], available[m], need[n][m] ;
	
	printf("\n-------------------Enter allocation matrix:-------------------\n") ;	
	for(int i=0; i<n ; i++){				// input for allocation matrix
		for(int j=0 ; j<m ;j++){
			printf("\nEnter allocation[%d][%d]: ",i,j) ;
			scanf("%d", &allocation[i][j]) ;
		}
	}
	
	printf("\n-------------------Enter max matrix:-------------------\n") ;	
	for(int i=0; i<n ; i++){				// input for max matrix
		for(int j=0 ; j<m ;j++){
			printf("\nEnter max[%d][%d]: ",i,j) ;
			scanf("%d", &max[i][j]) ;
		}
	}
	
	printf("\n-------------------Enter available/work matrix:-------------------\n") ;	
	for(int i=0; i<m ; i++){				// input for work matrix
		printf("\nEnter available[%d]: ",i) ;
		scanf("%d", &available[i]) ;
		
	}
	bankersAlgo(allocation,max,available, need ); 
	do{
		int choice = 0 ;
		printf("\nDo you want to check for new request?\n1.Yes\t2.No") ;
		scanf("%d", &choice) ;
		if(choice==2){
			printf("\nThankyou") ;
			break ;
		}
		else{
			int p = 0 ;
			printf("\nEnter process number: ") ;
			scanf("%d", &p) ;
			printf("\nEnter values: ") ;
			int flag = 1 ;
			for(int i=0 ; i<m; i++){
				int  req ;
				scanf("%d", &req) ;
				if(req>need[p][i]){
					printf("\nError condition\n") ;
					flag =0 ;
					break ;
				}
				else{
					if(req > available[i]){
						printf("\nResources not available\n") ;
						flag = 0 ;
						break ;
						
					}
					else{
						available[i] = available[i] - req ;
						allocation[p][i] += req ;
						need[p][i] -= req ;
						
					}				
					
				}
			}
			if(flag == 1) {
				bankersAlgo(allocation,max,available, need ); 
			}
			
		}
	}while(1) ;
}