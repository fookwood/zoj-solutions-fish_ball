#include <iostream>
using namespace std;

int partition(int A[], int l, int r) {
  int p = A[l], i = l, j = r + 1;
  int temp;
  do {
    do {i++;} while(A[i] < p);
    do {j--;} while(A[j] > p);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  } while(i < j);
  temp = A[i];
  A[i] = A[j];
  A[j] = A[l];
  A[l] = temp;
  return j;
}

void quickSort(int A[], int l, int r) {
  if(l < r) {
    int s = partition(A, l, r);
    quickSort(A, l, s - 1);
    quickSort(A, s + 1, r);
  }
}

void quickSort(int A[], int n) {
  quickSort(A, 0, n - 1);
}

int	main() 
{
	int	N,	x[100];
	while ( cin >> N ) {
		if( !N ) break;
		for( int i = 0; i < N; i++ )
			cin >> x[i];
		quickSort(x, N);
		for( int i = 0; i < N - 1; i++)
			if( x[i] != x[i + 1] )
				cout << x[i] << ' ';
		cout << x[N - 1] << endl; 
	} 
}
