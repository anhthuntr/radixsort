# Assignment (CSCE3110): Radix Sort

Author: Tran Anh Thu Nguyen (trananhthunguyen@my.unt.edu)

The purpose of this assignment is to implement an efficient variable-base radix sort for integers

## Usage
To compile and execute the program, use the following command
```
$ g++ -std=c++11 radixsort.cpp -o radix
$ ./radix <base>
```
in which \<base> is the user-input base that you MUST include in the command-line, or else the program wouldn't run

For example, you would like to sort integers with base 10, the command is
```
$ g++ -std==c++11 radixsort.cpp -o radix
$ ./radix 10
```
## Program Descriptions
- Program should accept one command-line argument for the supported base (i.e., 2 
for binary, 8 for octal, 10 for decimal, and 16 for hexadecimal) that will be used in the 
radix sort. If the user does not enter a base as the command-line argument, program will display a message and be terminated.

- Program will execute with different sizes of data structure (10, 100, 1000, 10000), only unsorted and sorted array is displayed for size 10 to show the radix sort is working properly

- The data structure is populated with random seeded numbers in integral sequences, range value between 0 - 100000 (inclusively)

- For each data structure size, radix sort will be run 10 times to measure the time 
needed for sorting in nanoseconds, excluding the time to generate the random numbers, 
sorting time is displayed for each pass, then the average sorting time is computed.

- See sample output above (with different bases) for more information.

*Note: Chrono library is used in this program to deal with measuring the time, which is only supported in C++11 or above, make sure to include the flag ```-std=c++11``` when compile to avoid warning. [Read more about Chrono](https://www.geeksforgeeks.org/chrono-in-c/).

