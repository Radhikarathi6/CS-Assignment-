# CS-Assignment- 
## Question 
Write a multithreaded sorting program that works as follows: A list of integers
is divided into two smaller lists of equal size. Two separate threads (which we
will term sorting threads) sort each sublist using a sorting algorithm of your
choice. The two sublists are then merged by a third thread—a merging thread
—which merges the two sublists into a single sorted list.
Because global data are shared cross all threads, perhaps the easiest way
to set up the data is to create a global array. Each sorting thread will work on
one half of this array. A second global array of the same size as the unsorted
integer array will also be established. The merging thread will then merge
the two sublists into this second array. Graphically, this program is structured
according to Figure 4.20.
This programming project will require passing parameters to each of the
sorting threads. In particular, it will be necessary to identify the starting index
from which each thread is to begin sorting. Refer to the instructions in Project
1 for details on passing parameters to a thread. 
The parent thread will output the sorted array once all sorting threads have exited.

## Detailed Explanation
We first import all the necessary libraries required for the program. 
Next, a global parameter NUMBER_OF_THREADS is defined and array size, SIZE is defined.
Two arrays of size = SIZE is also initialized. 
A structure named A is defined and the structure variable is called parameters.
To sort and merge the array, we make use of bubble sort algorithm. 
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
sorter and merger threads are created to perform sorting and merging. 

pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg); 

pthread is created using the following syntax. here thread - returns the thread id, attr - Set to NULL if default thread attributes (detached state, scheduling poilcy,scheduling paramerter,inheritsched attribute, scope, guard size, stack address, stack size) are used, void * (*start_routine) - pointer to the function to be threaded (Function has a single argument: pointer to void), *arg - pointer to argument of function (To pass multiple arguments, send a pointer to a structure)

To terminate a thread, void pthread_exit(void *retval); is used, where retval - Return value of thread.

join function is defined by - int pthread_join(pthread_t thread, void **retval); 
The pthread_join() function waits for the thread specified bythread to terminate. If that thread has already terminated, then pthread_join() returns immediately.  The thread specified by thread must be joinable.
If retval is not NULL, then pthread_join() copies the exit status of the target thread
If multiple threads simultaneously try to join with the samenthread, the results are undefined.  If the thread calling pthread_join() is canceled, then the target thread will remain joinable i.e., it will not be detached.

The malloc or memory allocation method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. ptr = (cast-type*) malloc(byte-size)
