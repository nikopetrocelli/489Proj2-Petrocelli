#include <pthread.h>
#include "Semaphore.h"
pthread_mutex_t mutex;
pthread_cond_t condition;
int sem = 0;
/***********************************************************************************
 * Niko Petrocelli
 * CSCE 489 Project 2
 * 
 * 
 * 
 * ********************************************************************************/


/*************************************************************************************
 * Semaphore (constructor) - this should take count and place it into a local variable.
 *						Here you can do any other initialization you may need.
 *
 *    Params:  count - initialization count for the semaphore
 *
 *************************************************************************************/

Semaphore::Semaphore(int count) {
   
    sem = count;

    pthread_mutex_init(&mutex,NULL);
    
}


/*************************************************************************************
 * ~Semaphore (destructor) - called when the class is destroyed. Clean up any dynamic
 *						memory.
 *
 *************************************************************************************/

Semaphore::~Semaphore() {

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);


}


/*************************************************************************************
 * wait - implement a standard wait Semaphore method here
 *
 *************************************************************************************/

void Semaphore::wait() {

    pthread_mutex_lock(&mutex);
    while (sem <= 0){
        pthread_cond_wait(&condition, &mutex);
    }
    sem--;
    pthread_mutex_unlock(&mutex);

}


/*************************************************************************************
 * signal - implement a standard signal Semaphore method here
 *
 *************************************************************************************/

void Semaphore::signal() {

   pthread_mutex_lock(&mutex);
   sem++;
   pthread_cond_signal(&condition);
    
   pthread_mutex_unlock(&mutex);
    

}


