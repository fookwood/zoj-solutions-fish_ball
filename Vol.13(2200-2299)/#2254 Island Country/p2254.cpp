// 2003013 2009-09-26 18:12:02 Accepted  2254 C++ 220 208 呆滞的慢板 

// 经典，LCS 转 LIS，前提是 LCS 的双方都是一个等长的置换。
// 将 LCS 混合置换之后，对于这个 置换之后的序列求 LIS 即可。
// 问题的做法就是按照优先级求出各自的顺序，然后做 LCS 即可。 

#include <iostream>
#include <algorithm>
using namespace std;

//最长单调子序列,复杂度O(nlogn)
//注意最小序列覆盖和最长序列的对应关系,例如
//"define _cp(a,b) ((a)>(b))"求解最长严格递减序列,则
//"define _cp(a,b) (!((a)>(b)))"求解最小严格递减序列覆盖
//可更改元素类型和比较函数
#define MAXN 1000
#define _cp(a,b) ((a)>(b))
typedef int elem_t;

int subseq(int n,elem_t* a){
	int b[MAXN],i,l,r,m,ret=0;
	for (i=0;i<n;b[l]=i++,ret+=(l>ret))
		for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1)
			if (_cp(a[b[m]],a[i]))
				l=m+1;
			else
				r=m-1;
	return ret;
}


int N, P[1000], Q[1000];
pair<int, int> A[1000], B[1000];

int main() {
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for(int i = 0; i < N; ++i) {
            cin >> B[i].first;
            B[i].second = i;
        }
        sort(A, A + N);
        sort(B, B + N);
        for(int i = 0; i < N; ++i)
            P[A[i].second] = i;
        for(int i = 0; i < N; ++i)
            Q[i] = -P[B[i].second];
        cout << subseq(N, Q) << endl;
    }
}
