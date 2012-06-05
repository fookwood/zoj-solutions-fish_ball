// 1683640 2008-10-30 22:39:26 Accepted  2404 C++ 0 572 呆滞的慢板 

// 加权二分匹配，直接贴的浙大模板。 

//二分图最佳匹配,kuhn munkras算法,邻接阵形式,复杂度O(m*m*n)
//返回最佳匹配值,传入二分图大小m,n和邻接阵mat,表示权值
//match1,match2返回一个最佳匹配,未匹配顶点match值为-1
//一定注意m<=n,否则循环无法终止
//最小权匹配可将权值取相反数
#include <string.h>
#define MAXN 310
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}

#include <iostream>
#include <vector>
using namespace std;

char G[101][101];
int A[MAXN][MAXN], X[MAXN], Y[MAXN];
int N, M;

vector<pair<int, int> > H, m;

inline int abs(int x) {return x < 0 ? -x : x;}

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) +
            abs(a.second - b.second);
}

int main() {
    
    while(cin >> N >> M && N) {
        H.clear();
        m.clear();
        for(int i = 0; i < N; ++i) {
            cin >> G[i];
            for(int j = 0; j < M; ++j) {
                if(G[i][j] == 'm')
                    m.push_back(make_pair(i, j));
                if(G[i][j] == 'H')
                    H.push_back(make_pair(i, j));
            }
        }
        for(int i = 0; i < H.size(); ++i)
            for(int j = 0; j < H.size(); ++j)
                A[i][j] = -dist(H[i], m[j]);
        cout << -kuhn_munkras(H.size(), m.size(), A, X, Y) << endl;
    }
    
}
