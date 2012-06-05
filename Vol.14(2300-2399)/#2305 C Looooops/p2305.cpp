// 1692672 2008-11-08 00:17:02 Accepted  2305 C++ 710 184 呆滞的慢板 

// 求最小的 N，使得 A + C * N == B (mod 2^k)
// 也就是求模线性方程 C * N == B - A (mod 2^k) 的最小解。 

#include <iostream>
#include <algorithm>
using namespace std;

#ifdef WIN32
typedef __int64 i64;
#else
typedef long long i64;
#endif

//扩展Euclid求解gcd(a,b)=ax+by
i64 ext_gcd(i64 a,i64 b,i64& x,i64& y){
	i64 t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}

//求解模线性方程ax=b (mod n)
//返回解的个数,解保存在sol[]中
//要求n>0,解的范围0..n-1
i64 modular_linear(i64 a,i64 b,i64 n){
	i64 d,e,x,y,i;
	d=ext_gcd(a,n,x,y);
	if (b%d)
		return -1;
	e=(x*(b/d)%n+n)%n;
	i64 ans = e;
	for (i=0;i<d;i++)
	   ans = min(ans, (e+i*(n/d))%n);
	return ans;
}

i64 A, B, C, k, M;

int main() {
    while(cin >> A >> B >> C >> k && k) {
        M = 1ll << k;
        B = (B - A + M) % M;
        i64 N = modular_linear(C, B, M);
        if(N == -1)
            puts("FOREVER");
        else
            cout << N << endl;
    }
}
