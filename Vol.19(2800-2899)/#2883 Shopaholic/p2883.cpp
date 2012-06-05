// 明显全部要买，并且折扣的个数有且仅有 N/3 个，
// 于是先排序，然后贪心从大往小取，每次取 3 个。

#include <cstdio>

int partition(int A[], int l, int r) {
  int p = A[l], i = l, j = r + 1;
  int temp;
  do {
    do {i++;} while(A[i] > p);
    do {j--;} while(A[j] < p);
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

int main() {
	int	T,	N,	A[20000],	sum; 
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d", &N );
		sum = 0;
		for( int i = 0; i < N; i++ )
			scanf( "%d", A + i );
		quickSort( A, 0, N - 1 );
		for( int i = 2; i < N; i += 3 )
			sum += A[i];
		printf( "%d\n", sum );
	} 
} 
