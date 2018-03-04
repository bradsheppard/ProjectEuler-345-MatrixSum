Matrix Sum
=============

This was built as a solution to problem 345 (Matrix Sum) of Project Euler.
The problem involves computing the Matrix Sum of matrices. 
The Matrix Sum of a matrix is defined as the maximum sum of matrix elements with each element being the only one in his row and column.
An obvious solution to this problem involves a brute force search, which has exponential time complexity.

A speed up that I implemented involves pruning the search tree at each point by checking
if it's possible that the running sum can exceed the maximum sum found so far. This greatly
increases the time required to find the matrix sum.



[MIT](LICENSE)
