//////////////////////////////////////////////////////////
//                     排序模板 v1.0                    //
//////////////////////////////////////////////////////////
//                                                      //
//                      模板参数                        //
// 1. T:      排序元素类型;                             //
//                                                      // 
//                        功能                          //
// 1. quicksort:    快速排序;                           //
// 2. mergesort:    归并排序，返回逆序对数;             //
//                                                      //
//                        备注                          //
// 1. 排序给出区间为左闭右闭区间;                       // 
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#ifndef SORT_XPER
#define SORT_XPER

#include <functional>
#include <algorithm>  

template<class T>
void quicksort(T a[], int begin, int end) {
    int i = begin, j = end;
    T   p = a[begin+end>>1];
    do {
        while(a[i] < p) i++;
        while(p < a[j]) j--;
        if(i <= j) std::swap(a[i++], a[j--]);
    } while(i < j);
    if(i < end)   quicksort(a, i, end);
    if(j > begin) quicksort(a, begin, j);
}

template<class T>
int mergesort(int begin, int end, T a[], T t[]) {
    if(end - begin <= 0) return 0;
    int mid = begin + end >> 1, ans = 0,
        p1 = begin, p2 = mid + 1, i = begin;
    ans += mergesort(begin, mid, a, t);
    ans += mergesort(mid+1, end, a, t);
    while(p1 <= mid || p2 <= end) {
        if(p2 > end)            t[i++] = a[p1++];
        else if(p1 > mid)       t[i++] = a[p2++];
        else if(a[p1] < a[p2])  t[i++] = a[p1++];
        else { ans += mid + 1 - p1; t[i++] = a[p2++]; }
    }
    for(i = begin; i <= end; i++) a[i] = t[i];
    return  ans;
}

#endif // SORT_XPER


#include <iostream>
using namespace std;

int T, N, A[1000000], B[1000000];

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        int N3 = N * N * N, pos;
        for(int i = 0; i < N3; ++i) {
            scanf("%d", A + i);
            if(A[i] == 0) pos = i;
        }
        while(pos % N) { swap(A[pos], A[pos - 1]); --pos; }
        while(pos / N) { swap(A[pos], A[pos - N]); pos -= N; }
        puts(
            mergesort(1, N3 - 1, A, B) & 1 ?
            "Puzzle can be solved." :
            "Puzzle is unsolvable."
        );
    }
}
