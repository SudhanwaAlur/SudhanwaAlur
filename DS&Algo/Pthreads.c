// Powered by Judge0
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 512
void *compute_pi(void*);
/*Pthread Prototypes
1) pthread_create(
    pthread_t *thread_handle,
    const pthread_attr_t *attribute,
    void* (*thread_function(void *)),
    void *arg
);

2) pthread_join(
    pthread_t thread,
    void **ptr
);
*/

int num_threads;
int hits[MAX_THREADS];
int sample_points;
int sample_points_per_thread;

int main(void) {
    pthread_t p_threads[MAX_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    printf("Enter the number of Threads:\n");
    scanf("%d",&num_threads);
    printf("Enter number of sample points\n");
    scanf("%d",&sample_points);
    sample_points_per_thread=sample_points/num_threads;
    int i;
    for(i=0;i<num_threads;i++)
    {
        hits[i]=i;
        pthread_create(&p_threads[i],&attr,compute_pi,(void*)&hits[i]);
    }
    int j;
    for(j=0;j<num_threads;j++)
    {
        pthread_join(p_threads[j],NULL);
    }
    return 0;
}
void *compute_pi(void *s)
{
   double rand_x,rand_y;
   int seed=*(int *)s;
   printf("Seed %d\n and Rand Max %d",seed,RAND_MAX);
   rand_x=(double)rand()/RAND_MAX;
   rand_y=(double)rand()/RAND_MAX;
   printf("X:%d and y:%d\n",rand_x,rand_y);
}

