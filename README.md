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
The parent thread will output the sorted array once all sorting threads have
exited.

## Detailed Explanation
We first import all the necessary libraries required for the program. 
Next, a global parameter N is defined and an array a[] is defined.
A structure named Arr is defined and the structure variable is called Array.
To sort and merge the array, we make use of merge sort. 
The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm. 
In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.

