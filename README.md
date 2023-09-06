# SC2001 Project 1: Integration of Mergesort & Insertion Sort

_Project Description_
In Mergesort, when the sizes of subarrays are small, the overhead of many recursive calls makes the algorithm inefficient. 
Therefore, in real use, we often combine Mergesort with Insertion Sort to come up with a hybrid sorting algorithm for better efficiency. 
The idea is to set a small integer S as a threshold for the size of subarrays. 
Once the size of a subarray in a recursive call of Mergesort is less than or equal to S,
the algorithm will switch to Insertion Sort, which is efficient for small-sized input.

Algorithm Design and Implementation
- pseudocode
- example
- source code

Algorithm Analysis (Theoretical)
- time complexity for all 3 cases

Algorithm Analysis (Empirical)
1. With the value of S fixed, plot the number of key comparisons over different sizes of the input list n.
3. With the input size n fixed, plot the number of key comparisons over different values of S. 
4. Using different sizes of input datasets, determine the optimal value for S

Comparing Hybrid Sort and the original Merge Sort algorithm
- performance: how much faster is it
