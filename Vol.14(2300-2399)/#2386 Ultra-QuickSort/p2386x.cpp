// 3032575 2008-08-12 20:58:38 Accepted 2386 C++ 00:00.73 4744K 呆滞的慢板 

// 困扰好久的题目，nlogn 求逆序对，结果会超 int，为此无数 WA 

#include <iostream>
using namespace std;

typedef long long i64;

template<class T>
i64 mergesort(int begin, int end, T a[], T t[]) {
    if(end - begin <= 0) return 0;
    i64 ans = 0;
    int mid = begin + end >> 1,
        p1 = begin, p2 = mid + 1, i = begin;
    ans += mergesort(begin, mid, a, t);
    ans += mergesort(mid+1, end, a, t);
    while(p1 <= mid || p2 <= end) {
        if(p2 > end) { t[i++] = a[p1++]; continue; }
        if(p1 > mid) { t[i++] = a[p2++]; continue; }
        if(a[p1] < a[p2]) t[i++] = a[p1++];
        else { ans += mid + 1 - p1; t[i++] = a[p2++]; }
    }
    for(i = begin; i <= end; i++) a[i] = t[i];
    return  ans;
}

int     N,  A[500000],  B[500000];

int main() {
    
    while( cin >> N && N ) {

        for( int i = 0; i < N; ++i )
            scanf( "%d", A + i );
        
        cout << mergesort( 0, N-1, A, B ) << endl;

    }
    
}
