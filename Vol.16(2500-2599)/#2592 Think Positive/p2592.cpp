// 1658543 2008-10-06 15:04:26 Accepted  2592 C++ 650 4092 呆滞的慢板 

// 贪心，假设原数组是 A[]，BK[] 是从尾部累加数组，FD[] 是从头部累加数组 
// BKMX[] 是从尾部累加最大值，FDMN[] 是从头部累加最小值
// 枚举 j，若 k > j，必须 BK[j]-BK[k] > 0，因此要求 BK[j]-BKMX[j+1] > 0
//         若 k < j，必须 BK[j]+FD[k] > 0，因此要求 BK[j]+FDMN[j-1] < 0
//         若 k == j，只需 A[j] > 0，另外要求总和 S > 0, BK[j] > 0
// 满足上述三个条件，该 j 即为合法，计数 +1
// 生成各数组及检验均为 O(1)，因此总体算法时间效率为 O(1)。 


#include <iostream>
#include <algorithm>
using namespace std;

int A[200000], FD[200000], BK[200000], S, N, T;
int BKMX[200000], FDMN[200000];

int main() {

    for(scanf("%d", &T); T--;) {
        scanf("%d", &N);
        for(int i = S = 0; i < N; ++i) {
            scanf("%d", A + i);
            S += A[i];
            FD[i] = A[i];
            if(i) FD[i] += FD[i-1];
        }
        for(int i = 0; i < N; ++i)
            BK[i] = S - FD[i] + A[i];
        
        if(S <= 0) {puts("0"); continue;}
        
        BKMX[N-1] = BK[N-1];
        for(int i = N-2; i >= 0; --i)
            BKMX[i] = max(BK[i], BKMX[i+1]);
            
        FDMN[0] = FD[0];
        for(int i = 1; i < N; ++i)
            FDMN[i] = min(FD[i], FDMN[i-1]);
            
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            bool yes = A[i] > 0 && BK[i] > 0;
            if(i < N-1 && BK[i] - BKMX[i+1] <= 0)
                yes = false;
            if(i > 0 && BK[i] + FDMN[i-1] <= 0)
                yes = false;
            ans += yes;
        }
        
        printf("%d\n", ans);

    }
}
