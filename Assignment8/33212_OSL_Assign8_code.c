// Name: Disha Chavan
// Class: TE 10		Batch: L 10
// Roll No: 33212
// Disk scheduling algorithms

#include<stdio.h>
#include<stdlib.h>

void SSTF(){
	int n, start ;
	printf("\nEnter number of requests: ");
	scanf("%d", &n) ;
	int seq[n] ;
	printf("\nEnter sequence of requests: ");
	for(int i=0; i<n; i++){
		scanf("%d", &seq[i]) ;
	}
	
	printf("\nEnter initial position: ");
	scanf("%d", &start) ;
	
	int cnt = 0;
	int totalHeadMovement = 0;
	printf("\n------------------------------------------------------------------ ");
	printf("\nResult sequence: \n");
	while(cnt != n){
		int min=10000, temp, pos ;
		for(int i=0; i<n; i++){
			temp = abs(seq[i] - start);
			if(min>temp){
				min=temp;
				pos = i ; 
			}
		}
		printf(" %d ", min) ;
		totalHeadMovement += min ;
		start = seq[pos] ;
		seq[pos] = 10000;
		cnt++ ;
		
	}
	printf("\n------------------------------------------------------------------ ");
	printf("\n\nTotal head movement is: %d", totalHeadMovement) ;
	
}

void SCAN(){
	int n, start, size, move ;
	printf("\nEnter number of requests: ");
	scanf("%d", &n) ;
	int seq[n] ;
	printf("\nEnter sequence of requests: ");
	for(int i=0; i<n; i++){
		scanf("%d", &seq[i]) ;
	}
	
	printf("\nEnter initial position: ");
	scanf("%d", &start) ;
	printf("Enter total disk size\n");
	scanf("%d",&size);
	printf("Enter the direction for head movement\n1.high\t2.low\n");
	scanf("%d",&move);
	printf("\n------------------------------------------------------------------ ");
	printf("\nResult sequence: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++)
		{
		    if(seq[j]>seq[j+1])
		    {
		        int temp;
		        temp=seq[j];
		        seq[j]=seq[j+1];
		        seq[j+1]=temp;
		    }

		}
    	}

	    int index,i;
	    for( i=0;i<n;i++)
	    {
		if(start < seq[i])
		{
		    index=i;
		    break;
		}
	    }
	   
	    // if movement is towards high value
	    int totalHeadMovement = 0;
	    if(move==1)
	    {
		for( i=index;i<n;i++)
		{
		    totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		    printf(" %d ", seq[i]) ;
		    start = seq[i];
		}
		//  last movement for max size 
		totalHeadMovement=totalHeadMovement+abs(size-seq[i-1]-1);
		start = size-1;
		for( i=index-1;i>=0;i--)
		{
		     totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		     printf(" %d ", seq[i]) ;
		     start = seq[i];
		    
		}
	    }
	    // if movement is towards low value
	    else
	    {
		for( i=index-1;i>=0;i--)
		{
		    totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		    printf(" %d ", seq[i]) ;
		    start = seq[i];
		}
		//  last movement for min size 
		totalHeadMovement = totalHeadMovement+abs(seq[i+1]-0);
		start = 0;
		for( i=index;i<n;i++)
		{
		     totalHeadMovement = totalHeadMovement +abs(seq[i]-start);
		     printf(" %d ", seq[i]) ;
		     start = seq[i];
		    
		}
	    }
	    printf("\n------------------------------------------------------------------ ");
	    printf("\nTotal head movement is %d",totalHeadMovement);
}

void CLOOK(){

	int n, start, move ;
	printf("\nEnter number of requests: ");
	scanf("%d", &n) ;
	int seq[n] ;
	printf("\nEnter sequence of requests: ");
	for(int i=0; i<n; i++){
		scanf("%d", &seq[i]) ;
	}
	
	printf("\nEnter initial position: ");
	scanf("%d", &start) ;
	printf("Enter the direction for head movement\n1.high\t2.low\n");
	scanf("%d",&move);
	
	printf("\n------------------------------------------------------------------ ");
	printf("\nResult sequence: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++)
		{
		    if(seq[j]>seq[j+1])
		    {
		        int temp;
		        temp=seq[j];
		        seq[j]=seq[j+1];
		        seq[j+1]=temp;
		    }

		}
    	}

	    int index,i;
	    for( i=0;i<n;i++)
	    {
		if(start < seq[i])
		{
		    index=i;
		    break;
		}
	    }
	   
	    // if movement is towards high value
	    int totalHeadMovement = 0;
	    if(move==1)
	    {
		for( i=index;i<n;i++)
		{
		    totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		    printf(" %d ", seq[i]) ;
		    start = seq[i];
		}
		 for( i=0;i<index;i++)
		{
		     totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		     printf(" %d ", seq[i]) ;
		     start = seq[i];
		    
		}
	    }
	    
	    else
	    {
		for(i=index-1;i>=0;i--)
		{
		    totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		    printf(" %d ", seq[i]) ;
		    start = seq[i];
		}
		
		for(i=n-1;i>=index;i--)
		{
		     totalHeadMovement = totalHeadMovement+abs(seq[i]-start);
		     printf(" %d ", seq[i]) ;
		     start=seq[i];
		    
		}
	    }
    printf("\n------------------------------------------------------------------ ");
    printf("\nTotal head movement is %d",totalHeadMovement);
    
}
void main(){
	int choice = 0;
	while(choice!=4){
		printf("\nEnter choice\n1.SSTF\n2.SCAN\n3.CLOOK\n ");
		scanf("%d", &choice) ;
		
		switch(choice){
			case 1: SSTF() ;
			break ;
			case 2: SCAN() ;
			break ;
			case 3: CLOOK() ;
			break ;
		}
	}
}