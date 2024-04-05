# About the program
<p>This assignment is about making different sorting algorithms which are insert, heap, quick and shell sort. These programs will be used to sort a random number of arrays and then using graphs will be compared which is more accurate and efficient.<p>

# How to build each sorting program

<p>insert.c = Insertion Sort :-

Insertion Sort is a sorting algorithm that considers elements one at a time, placing them in their correct, ordered position.  Assume an array of size n. For each k in increasing value from 1 ≤ k ≤ n (using 1-based indexing), Insertion Sort compares the k-th element with each of the preceding elements in descending order until its position is found.<p>

<p>heap.c = Heap Sort:-

	The heap data structure is typically implemented as a specialized binary tree. There are two kinds of heaps: max heaps and min heaps. In a max heap, any parent node must have a value that is greater than or equal to the values of its children. For a min heap, any parent node must have a value that is less than or equal to the values of its children.

 The heap is typically represented as an array, in which for any index k, the index of its left child is 2k and the index of its right child is 2k +1. It’s easy to see then that the parent index of any index k should be b k 2 c. <p>

 <p>quick.c = recursive Quicksort.:- 

	Quicksort is a divide-and-conquer algorithm. It partitions arrays into two sub-arrays by selecting an element from the array and designating it as a pivot. Elements in the array that are less than the pivot go to the left sub-array, and elements in the array that are greater than or equal to the pivot go to the right sub-array<p>

<p> shell.c implements Shell Sort. 

	From the definition of the gap sequence generator, you should see that gaps are computed as b 3 k−1 2 c and the largest k is b log(2n+3) log(3) c, where n is the length of the array to sort. You are iterating over the gap sequence starting with the largest k first, making your way down to a gap size of 1. <p>

# Running the program

<p> Run make file then run make format . Then call sorting.c and type in the commands to input required feilds and run the sorting program of your choosing.

# Command line options

 <p>OPTIONS
                -a   Employs all sorting algorithms.
                -e   Enables Heap Sort.
                -i   Enables Insertion Sort.
                -s  Enables Shell Sort.
                -q  Enables Quicksort.
                -r  seed: Set the random seed to seed.
                -n  size : Set the array size to size.
                -p  elements : Print out elements number of elements from the array
                -h  Prints out program usage
<p>


