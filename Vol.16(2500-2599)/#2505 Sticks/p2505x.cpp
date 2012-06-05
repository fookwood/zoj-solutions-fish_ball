// 1654078 2008-10-02 17:59:04 Accepted  2505 C++ 20 304 呆滞的慢板 

// 数据结构题，使用类似并查集的数据结构：并查区间来动态维护连续区间。 
// ************************ 优化版 ************************ //
 
#include <cstdio>

int pre[4096], sum[4096];

inline int max(int x, int y) {return x > y ? x : y;}

int check(int k) {
    if(pre[k] == k) return k;
    return pre[k] = check(pre[k]);
}

int turn_on(int k) {
    if(k < 4095 && sum[k+1]) {
        pre[k+1] = k;
        sum[k] = sum[k+1] + 1;
    }
    else sum[k] = 1;
    if(k > 0 && sum[k-1]) {
        pre[k] = k-1;
        sum[check(k)] += sum[k];
    }
    return sum[check(k)];
}

void turn_off(int k) {
    int r = check(k), h = sum[r];
    sum[k+1] = r + h - k - 1;
	for(int i = k+1; i < r+h; ++i)
		pre[i] = k+1;
    sum[r] = k - r;
    sum[pre[k]=k] = 0;
}

int main() {
    int t, n, k;
    for(scanf("%d", &t); t--;) {
        int mx = 0;
        for(int i = 0; i < 4096; ++i) {
            sum[i] = 0;
            pre[i] = i;
        }
        for(scanf("%d", &n); n--;) {
            scanf("%d", &k);
            if(sum[k-1]) turn_off(k-1);
            else mx = max(mx, turn_on(k-1));
        }
        printf("%d\n", mx);
    }
}
