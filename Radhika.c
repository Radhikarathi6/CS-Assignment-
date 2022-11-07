#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define NUMBER_OF_THREADS 2

void *sorter(void *params);    /* thread that performs basic sorting algorithm */
void *merger(void *params);    /* thread that performs merging of results */

int list[SIZE] = {7,1,8,3,4,2,6,9,12,15};
int result[SIZE];

typedef struct A
{
    int from_index;
    int to_index;
} parameters;

int main (int argc, const char * argv[])
{
    int i;
    pthread_t workers[NUMBER_OF_THREADS]; /* establish the first sorting thread */
    parameters *data = (parameters *) malloc (sizeof(parameters));
    data->from_index = 0;
    data->to_index = (SIZE/2) - 1;
    pthread_create(&workers[0], NULL, sorter, data); /* establish the second sorting thread */
    data = (parameters *) malloc (sizeof(parameters));
    data->from_index = (SIZE/2);
    data->to_index = SIZE - 1;
    pthread_create(&workers[1], NULL, sorter, data); /* now wait for the 2 sorting threads to finish */
    for (i = 0; i < NUMBER_OF_THREADS - 1; i++)
        pthread_join(workers[i], NULL); /* establish the merge thread */
    data = (parameters *) malloc(sizeof(parameters));
    data->from_index = 0;
    data->to_index = (SIZE/2);
    pthread_create(&workers[2], NULL, merger, data); /* wait for the merge thread to finish */
    pthread_join(workers[2], NULL); /* output the sorted array */
    return 0;
}

void *sorter(void *params)
{
    parameters* p = (parameters *)params; 
    //SORT
    int begin = p->from_index;
    int end = p->to_index+1;
    int z;
    for(z = begin; z < end; z++)
    {
        printf("The array recieved is: %d\n", list[z]);
    }
    printf("\n");
    int i,j,t,k;
    for(i=begin; i< end; i++)
    {
        for(j=begin; j< end-i-1; j++)
        {
            if(list[j] > list[j+1])
            {
                t = list[j];
                list[j] = list[j+1];
                list[j+1] = t;
            }
        }
    }
    for(k = begin; k< end; k++){
            printf("The sorted array: %d\n", list[k]);
    }
    int x;
    for(x=begin; x<end; x++)
    {
            result[x]=list[x] ;
    }
    printf("\n");
    pthread_exit(0);
}

void *merger(void *params)
{
    parameters* p = (parameters *)params;
    //MERGE
    int begin = p->from_index;
    int end = p->to_index+1;
    int i,j,t;
    for(i=begin; i< end; i++)
    {
        for(j=begin; j< end-i; j++)
        {
            if(result[j] > result[j+1])
            {
                t = result[j];
                result[j] = result[j+1];
                result[j+1] = t;
            }
        }
    }
    int d;
    for(d=0; d<SIZE; d++)
    {
        printf("The final resulting array is: %d\n", result[d]);
    }
    pthread_exit(0);
}