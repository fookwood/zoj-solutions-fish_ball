#include <iostream>
using namespace std;

void selectionSort(int A[], int size) {
  for(int i = 0; i < size - 1; i++) {
    int min = i;
    for(int j = i + 1; j < size; j++)
      if(A[j] < A[min]) min = j; 
    int temp = A[i];
    A[i] = A[min];
    A[min] = temp; 
  } 
} 

int main() {
	int	N,	A[15]; 
	while( cin >> A[N = 0] ) {
		if( A[0] == -1 ) break;
		while( cin >> A[++N] )
			if( !A[N] ) break; 
		selectionSort( A, N );
		int	count = 0; 
		for( int i = 0; i < N - 1; i++ )
			for( int j = i + 1; j < N; j++)
				if( A[j] == A[i] * 2 )
					count ++; 
		cout << count << endl;  
	}
} 
