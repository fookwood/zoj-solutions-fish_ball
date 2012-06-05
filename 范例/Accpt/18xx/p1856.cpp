#include<cstdio>
#include<cstdlib>
#define maxn 50001

typedef long long int64;

int cmp(const void *a,const void *b)
{
	return *(int64*)a-*(int64*)b;
}

int64 result[maxn];
int main()
{
	int64 p,q;
	for(int64 nn=0;nn<maxn;nn++)  result[nn]=nn*(nn-1);
	while(scanf("%lld%lld",&p,&q),p||q)
	{
		int64 sum,n;
		int64 *pt=NULL;
		for(sum=2;sum<=50000;sum++){
			if((sum*(sum-1)*p)%q!=0) continue;
			n=(sum*(sum-1)*p)/q;
			pt=(int64*)bsearch(&n,result,maxn,sizeof(int64),cmp);
			if(pt==NULL) continue;
			break;
		}
		if(sum==50001) puts("impossible");
		else printf("%d %d\n",pt-result,sum-(pt-result));
	}
	return 0;
}
//1670277 2006-03-09 18:14:42 Accepted 1856 C++ 00:00.35 828K OneYearOld 
//C(n,2)/C(n+m,2)=p/q,
//枚举m+n,然后二分找 (n+m)*(n+m-1)*p/q;
