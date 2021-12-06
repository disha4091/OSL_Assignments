// Name: Disha Chavan
// Class: TE 10		Batch: L 10
// Roll No: 33212
// Reader writer problem

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sem ;				// binary semaphore
pthread_mutex_t mutex ; 		// mutex variable
int count = 1 ;			// shared variable which will be shared by both reader and writer
int readerNum = 0 ;			// count for read 

void* writer(void *w){			// writer function

	sem_wait(&sem) ;		// wait for access 
	count = count*2 ;		// change value of shared variable
	
	printf("\nWriter %d modified count to %d\n", (*((int*)w)), count) ;
	sem_post(&sem) ;		// signal that semaphore value is now changed
}

void* reader(void *r){			// reader function

	pthread_mutex_lock(&mutex) ;	// acquire lock so that no other read or write can be performed
	readerNum++; 			// read count incremented
	if(readerNum == 1){		// if this is the first read all operations should wait
		sem_wait(&sem) ;
	}
	
	pthread_mutex_unlock(&mutex) ;
	printf("\nReader %d: read count = %d\n", *((int*)r), count) ;
	
	pthread_mutex_lock(&mutex) ;
	readerNum--;  			// read count decremented
	if(readerNum == 0){		// if it was the last read operation, other operations can now be allowed
		sem_post(&sem) ;
	}
	
	pthread_mutex_unlock(&mutex); // release the mutual exclusion lock
	
}

void main(){
	pthread_t read[10], write[5] ;	// threads for read and write operations
	pthread_mutex_init(&mutex, NULL) ;	// initialing mutex
	sem_init(&sem, 0, 1) ;			// since it is a binary semaphore, initialing with 1 and 0
	
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};	// array to be used for numbering
	
	for(int i=0; i<10; i++){		// calling read function
		pthread_create(&read[i], NULL, (void*)reader, (void*)&arr[i]) ;
	}  
	
	for(int i=0; i<5; i++){		// calling write function
		pthread_create(&write[i], NULL, (void*)writer, (void*)&arr[i]) ; 
	}
	for(int i=0; i<10; i++){		// combining threads for read operation
		pthread_join(read[i], NULL) ;
	}  
	
	for(int i=0; i<5; i++){		// combining threads for write operation
		pthread_join(write[i], NULL) ; 
	}
	
	pthread_mutex_destroy(&mutex) ; 	// destroy mutex and semaphore at the end og=f the program
	sem_destroy(&sem); 
 }
 
 
 /*
 Output:
 disha@disha-VirtualBox:~$ ./OsAssign4B

Reader 4: read count = 1

Reader 5: read count = 1

Reader 1: read count = 1

Reader 8: read count = 1

Reader 9: read count = 1

Reader 6: read count = 1

Reader 3: read count = 1

Reader 10: read count = 1

Reader 2: read count = 1

Writer 1 modified count to 2

Reader 7: read count = 2

Writer 2 modified count to 4

Writer 4 modified count to 8

Writer 5 modified count to 16

Writer 3 modified count to 32
*/