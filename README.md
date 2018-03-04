Matrix Sum
=============

This was built as a solution to problem 345 (Matrix Sum) of Project Euler.
The problem involves computing the Matrix Sum of matrices. 
The Matrix Sum of a matrix is defined as the maximum sum of matrix elements with each element being the only one in his row and column.
An obvious solution to this problem involves a brute force search, which has exponential time complexity.

A speed up that I implemented involves pruning the search tree at each point by checking
if it's possible that the running sum can exceed the maximum sum found so far. This greatly
increases the time required to find the matrix sum.

Usage
-----
The project can be built using `make`. Run the following from the project directory.

```
make
```

This will generate the C object files and the program executable. Run the following command to run the program:

```
./maxsum {matrix_file}
```

where `{matrix_file}` is a matrix text file. Two matrix files (matrix1.txt and matrix2.txt) are given
as examples. To clean the build artifacts, run the following:

```
make clean
```


[MIT](LICENSE)
