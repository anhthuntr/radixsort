/*
** Name: Tran Anh Thu Nguyen 
** EUID: tn0273
** Course: CSCE3110
** Description: Implement an efficient variable-base radix sort for an integer array using C++
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std::chrono;
using namespace std;

void radixSort(int A[], int n, int base);
void countSort(int A[], int n, int pos, int base);
void getArray(int A[], int size);
void showArray(int A[], int size);
int getMax(int A[], int count);

int main(int argc, char *argv[]) {
	int base;
	int size;
	float sum, average;
	int *array = new int[size]; //allocate memory for the array
	bool flag=false;

	if (argc < 2) {
		cout<<"You have to include the supported base in command-line.\n";
		exit(1);
	} else {
		size=10;
		base=stoi(argv[1]); //capture the base in command-line

		// A for loop to run with different data structure size
		for (int k=0;k<4;++k) {
			getArray(array,size);
			cout<<"Radix Sort: base = "<<base<<" size = "<<size<<endl;	
			//radixSort(array,size, base);
			// Only output the data structure when the size is small
			if (size==10)
			{
				cout<<"Unsorted: "; showArray(array,size);
				flag=true;
			}

			//run radixsort 10 times to take measurements of the time needed to sort
			//using high resolution clock chrono for more precise time
			for (int i=0;i<10;i++) {		  
	   		    typedef std::chrono::high_resolution_clock Clock;
	   		    ios_base::sync_with_stdio(false);
			    auto start = Clock::now();
			    radixSort(array,size,base);
			    auto stop = Clock::now();
	  			auto duration = duration_cast<nanoseconds>(stop - start).count();
	  			//output sorted array only when size is 10
			    while (flag) {
			    	cout<<"Sorted: "; showArray(array,size);
			    	flag=false;
			    }
	 
	 			cout<<fixed<<setprecision(1);
			    cout << "Pass " << i+1 << ":   " 
			         << duration << " nanoseconds" << endl;
			    sum += static_cast<float>(duration);
			}

			average =	sum/10.0;
			cout<<"Average:   "<<average<< " nanoseconds" << endl;
			cout<<endl;
			size=size*10;
		}

	}

	delete [] array;

	return 0;
}

void getArray(int A[], int size) 
{
	srand(time(NULL));
	for (int i=0;i<size;++i)
		A[i]=static_cast<int>(rand()% 10001 + 0); //get random number in range 0-10000 (inclusively)
}

void showArray(int A[], int size)
{
	for (int i=0;i<size;++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

int getMax(int A[], int size)
{
	int max=A[0];
	for (int i=1;i<size;++i)
	{
		if (max<A[i])
		{
			max=A[i];
		}
	}
	return max;
}

void countSort(int A[], int n, int pos, int base)
{
	int output[n];
	//int count[base]={0}; //define count array, size is fixed
	int *count=new int[base]; //define count array, size is not fixed

	for (int i=0;i<base;++i)
		count[i]=0;

	for (int i=0; i<n; ++i)
		++count[(A[i]/pos)%base]; //fill the count array with the value at that index

	for (int i=1;i<base;++i)
		count[i]+=count[i-1]; //update count array that contain actual position of this digit

	for (int i=n-1; i>=0; --i)
	{
		output[count[(A[i]/pos)%base] - 1 ]=A[i]; //build new array
		--count[(A[i]/pos)%base];
	}
	for (int i=0;i<n;++i)
		A[i]=output[i]; //copy array with sorted number according to current digit

	delete [] count;
}

void radixSort(int A[], int n, int base)
{
	int max=getMax(A,n);
	for (int pos=1;max/pos>0;pos*=base)
		countSort(A,n,pos,base);
}

