// Name: Disha Chavan
// Class: TE 10		Batch: L 10
// Roll No: 33212
// Producer consumer problem


#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define BufferSize 5	// maximum items that can be stored in buffer 

sem_t empty,full;	// semaphore for buffer full, empty	
pthread_mutex_t mutex;	// mutex
int count = 0 ;
int in = 0;
int out = 0;
int buffer[BufferSize];// buffer array

void *producer(void *p)//producer function
{   
    
    for(int i = 0 ; i< BufferSize; i++){		
    	sem_wait(&empty) ;
    	pthread_mutex_lock(&mutex) ;	// lock variable to enter in critical section
    	//--------------------------critical section----------
    	if(count>=BufferSize){
    		printf("\nThe Buffer is full\n") ;
    	}
    	else{
    		buffer[in] = rand()%100 ;	// produce and add element in buffer
    		printf("\nProducer: %d Produced Item: %d\n",*((int*)p) , buffer[in]) ;
    		in = (in+1)%BufferSize ;
    		count++ ;
    	}
    	
    	//--------------------------critical section----------
    	pthread_mutex_unlock(&mutex) ;	// unlock variable as critical section is over
    	
    	sem_post(&full) ;

    }
    

}
void *consumer(void *p)//producer function
{   

    for(int i = 0 ; i< BufferSize; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);	// lock variable to enter in critical section
        //--------------------------critical section----------
        if(count<=0){
    		printf("\nThe Buffer is empty\n") ;
    	}
    	else{
    		printf("\nConsumer %d: consumed Item %d\n",*((int*)p) , buffer[out]);
    		out = (out+1)%BufferSize ;
    		count-- ;
    	}
        int item = buffer[out];
        //--------------------------critical section----------
      
        pthread_mutex_unlock(&mutex);	// unlock variable as critical section is over
        sem_post(&empty);
      
    }
  
}

int main()	// main function
{   

    pthread_t pro_th[BufferSize],con_th[BufferSize];	// producer and consumer threads
    pthread_mutex_init(&mutex, NULL);			// mutex
    sem_init(&empty,0,BufferSize);			// initialize semaphores
    sem_init(&full,0,0);
    
    int p,c ;
    printf("\nEnter number of producers: ");
    scanf("%d", &p) ;
    printf("\nEnter number of consumers: ");
    scanf("%d", &c) ;
    
    int arr[5] = {1,2,3,4,5}; 

	

    for(int i = 0; i < p; i++) {			// calling producer function
        pthread_create(&pro_th[i], NULL, producer, (void *)&arr[i]);
    }
    for(int i = 0; i < c; i++) {			// calling consumer function	
        pthread_create(&con_th[i], NULL, consumer, (void *)&arr[i]);
    }

    for(int i = 0; i < p; i++) {			// joining producer threads
        pthread_join(pro_th[i], NULL);
    }
    for(int i = 0; i < c; i++) {			// joining consumer threads
        pthread_join(con_th[i], NULL);
    }

    pthread_mutex_destroy(&mutex);			// destroy mutex and semaphore before ending
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}


/*
Output: 
$ ./OsAssign4A

Enter number of producers: 2

Enter number of consumers: 2

Producer: 2 Produced Item: 83

Producer: 2 Produced Item: 86

Producer: 2 Produced Item: 77

Producer: 2 Produced Item: 15

Producer: 2 Produced Item: 93

Consumer 2: consumed Item 83

Consumer 2: consumed Item 86

Consumer 2: consumed Item 77

Consumer 2: consumed Item 15

Consumer 2: consumed Item 93

Producer: 1 Produced Item: 35

Producer: 1 Produced Item: 86

Producer: 1 Produced Item: 92

Producer: 1 Produced Item: 49

Producer: 1 Produced Item: 21

Consumer 1: consumed Item 35

Consumer 1: consumed Item 86

Consumer 1: consumed Item 92

Consumer 1: consumed Item 49

Consumer 1: consumed Item 21
*/