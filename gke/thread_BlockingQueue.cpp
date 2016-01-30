// Queue
// -get, push, pop, size

// BlockingQueue API
// -push, size, pop, get -> 

#include<iostream>
#include<pthread.h>

using namespace std;


pthread_mutex_t blockQueue;
pthread_mutex_t handlerForQueuePop;
pthread_mutex_t handlerForQueueGet;

int queue_size[100];
int startq = 0;
int endq = -1;
int sizeofQueue() 
{
    int size = 0;
    pthread_mutex_lock(&blockQueue);


    size = endq - startq + 1;
    pthread_mutex_unlock(&blockQueue);
    
    return size;
}

bool queue_push(int val)
{
   //Error handling

 pthread_mutex_lock(&blockQueue); 
 queue_size[++endq] = val;
 pthread_mutex_unlock(&blockQueue);   

 return true;

}

int queue_get() 
{
    int ret = -1;
    pthread_mutex_lock(&handlerForQueueGet);
    
    while(1)
    {
        pthread_mutex_lock(&blockQueue);
        if(endq >= startq)
        {
            pthread_mutex_unlock(&blockQueue);
            break;
        }
        pthread_mutex_unlock(&blockQueue);
    }

    pthread_mutex_lock(&blockQueue);
    ret = queue_size[startq];

    pthread_mutex_unlock(&blockQueue); 
    
    pthread_mutex_unlock(&handlerForQueueGet);
    return ret;
}

int queue_pop() 
{

    int ret = -1;
    
    pthread_mutex_lock(&handlerForQueueGet);
    
    while(1)
    {
        pthread_mutex_lock(&blockQueue);
        if(endq >= startq)
        {
            pthread_mutex_unlock(&blockQueue);
            break;
        }
        pthread_mutex_unlock(&blockQueue);
    }

    pthread_mutex_lock(&blockQueue);
    ret = queue_size[startq++];

    pthread_mutex_unlock(&blockQueue); 
    pthread_mutex_unlock(&handlerForQueueGet);
    return ret;
}


int main()
{

    //Test cases for blocking queue 
    queue_push(11);
    queue_push(4);
    queue_push(5);
    cout<<sizeofQueue()<<endl;
    cout<<queue_get()<<endl;
    cout<<queue_pop()<<endl;
    cout<<sizeofQueue()<<endl;
    queue_push(9);
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    cout<<queue_pop()<<endl;
    //Waits forever since the queue is empty
    cout<<queue_pop()<<endl;

    return 0;

}



