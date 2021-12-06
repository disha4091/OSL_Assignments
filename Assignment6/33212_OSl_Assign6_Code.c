// Name: Disha Chavan
// Class: TE 10		Batch: L 10
// Roll No: 33212
// Page Replacement algorithm

# include<stdio.h>
# define MAX 10 ;

void fifo(){					// function to perform fifo page replacement algorithm
	int frame_size, n;			// variables for frame size nad number of pages
	printf("\nEnter frame size: ") ;
	scanf("%d", &frame_size) ;
	printf("\nEnter number of pages in sequence: ") ;
	scanf("%d", &n) ;
	
	int input_seq[10] ;			// array containing page sequence
	printf("\nEnter page sequence: ") ;
	for(int i = 0; i<n; i++){
		scanf("%d", &input_seq[i]) ;
	}
	
	int frame[frame_size]; 		// array representing frame
	for(int i=0; i<frame_size; i++){	// initializing frame as -1 as it contains no pages
		frame[i] = -1 ;
	}
	
	int fault=0;				// variable for counting faults occured
	printf("\nInput\tFrame") ;
	for(int i=0; i<n; i++){		// loop will run for all the pages in the sequence
		int flag = 0; 
		for(int j=0; j<frame_size; j++){	//loop will run for all pages in th e frame
			if(input_seq[i] == frame[j]){	// if the page is found in frame it is a hit
				flag ++;
				fault--;
			}
		}
		fault++ ;
		if((fault<=frame_size) && (flag == 0)){// if page is absent add in the frame
			frame[i] = input_seq[i] ;
		}
			
		else if(flag==0) {
			frame[(fault-1)%frame_size] = input_seq[i] ;
		}
		printf("\n%d",i) ;	
		for(int k=0; k<frame_size; k++){
			printf("\t%d", frame[k]) ;
		}
		
	} 
	printf("\nTotal Page Faults: %d\n", fault);
    
}

void optimunReplacement(){					// function to perform optimum page replacement algorithm
	int frame_size, n;					// variables for frame size nad number of pages
	printf("\nEnter frame size: ") ;
	scanf("%d", &frame_size) ;
	printf("\nEnter number of pages in sequence: ") ;
	scanf("%d", &n) ;
	
	int input_seq[10] ;			// array containing page sequence
	printf("\nEnter page sequence: ") ;
	for(int i = 0; i<n; i++){
		scanf("%d", &input_seq[i]) ;
	}
	
	int frame[frame_size]; 		// array representing frame
	for(int i=0; i<frame_size; i++){	// initializing frame as -1 as it contains no pages
		frame[i] = -1 ;
	}
	
	int flag1, flag2, flag3, fault=0;
	int temp[frame_size] ;
	int pos, max1;
	printf("\nInput\tFrame") ;
	for(int i=0; i<n; i++){		// for all pages in sequence given
		flag1 = 0; flag2=0 ;
		for(int j=0; j<frame_size; j++){	// in case of hit
			if(input_seq[i] == frame[j]){
				flag1 = 1;
				flag2 = 1 ;
				break ;
			} 
		}
		
		if(flag1 == 0){		
			for(int j=0; j<frame_size; j++){
				if(frame[j] == -1){		// if frame has empty location
					fault++ ;
					frame[j] = input_seq[i] ;	// add page directly
					flag2 = 1 ;
					break ;
				}
			}	
		}
		if(flag2 == 0){
			flag3 = 0 ;
			for(int j = 0 ; j<frame_size; j++){	// temp array to find least occurance in future
				temp[j]=-1; 
				for(int k=i+1; k<n; k++){	
					if(frame[j] == input_seq[k]){
						temp[j] = k ;
						break ; 
					}
				}
			}
			
			for(int j=0 ; j<frame_size; j++){	// if it does not occur ahead in sequence
				if(temp[j] == -1){
					pos = j ;
					flag3 = 1 ;
					break ;
				}
			}
			
			if(flag3 == 0){
				pos = 0 ;
				max1 = temp[0] ;		// finding min no of occurances
				for(int j=1 ; j<frame_size; j++){
					if(temp[j] > max1){
						max1 = temp[j] ;
						pos = j ;
					}
				}
			}
			frame[pos] = input_seq[i] ;		// add at obtained position
			fault ++ ;
			
		}
		printf("\n%d",i) ;	
		for(int k=0; k<frame_size; k++){
			printf("\t%d", frame[k]) ;
		}
	}
	printf("\nTotal Page Faults: %d\n", fault);
	
}
int findLRU(int temp[], int n){		// function to help in finding least recently used page
	int i, min1 = temp[0], pos=0 ;
	for(int i=1 ; i<n; i++){
		if(temp[i] <min1){
		min1 = temp[i] ;
		pos = i ;
		}
	}
	return pos ;
}
void LRU(){					// function to perform LRU page replacement algorith,
	int frame_size, n;			// variables for frame size nad number of pages
	printf("\nEnter frame size: ") ;
	scanf("%d", &frame_size) ;
	printf("\nEnter number of pages in sequence: ") ;
	scanf("%d", &n) ;
	
	int input_seq[10] ;			// array containing page sequence
	printf("\nEnter page sequence: ") ;
	for(int i = 0; i<n; i++){
		scanf("%d", &input_seq[i]) ;
	}
	
	int frame[frame_size], temp[frame_size]; // array representing frame		
	for(int i=0; i<frame_size; i++){	// initializing frame as -1 as it contains no pages
		frame[i] = -1 ;
	}
	
	int flag1, flag2, count=0, fault = 0,pos;
	printf("\nInput\tFrame") ;
	for(int i=0; i<n ; i++){			// for all pages in sequence
		flag1 = 0; flag2 = 0;
		for(int j=0 ;j<frame_size; j++){	
			if(frame[j] == input_seq[i]){	// in case of hit
				count++ ;
				temp[j] = count ;
				flag1 = 1 ;
				flag2 = 1 ;
				break ;
			}
		}
		if(flag1 == 0) {
			for(int j=0; j<frame_size; j++){
				if(frame[j] == -1){	// if frame is empty
					count++ ;
					fault++ ;
					frame[j] = input_seq[i] ;
					temp[j] = count ;
					flag2 = 1 ;
					break ;
				}
			}
		}
		if(flag2 == 0){			
			pos = findLRU(temp, frame_size) ;	// finding position using helper function
			count++ ;
			fault++ ;
			frame[pos] = input_seq[i] ;
			temp[pos] = count ;
		}
		printf("\n%d",i) ;	
		for(int k=0; k<frame_size; k++){
			printf("\t%d", frame[k]) ;
		}
	}
	printf("\nTotal Page Faults: %d\n", fault);
}
void main(){
	int choice=0 ;
	do{	
		printf("\n=============================================================\n") ;
		printf("\nEnter choice: \n1.FCFS(fifo) page replacement algorithm\n2.Optimum age replacement algorithm\n3.LRU age replacement algorithm\n4.Exit") ;
		printf("\n=============================================================\n") ;
		scanf("%d", &choice) ;
		switch(choice){
			case 1 : fifo() ;
			break ;
			case 2 : optimunReplacement() ;
			break ;
			case 3: LRU() ;
			break ;
		}
	}while(choice!=4) ;
}