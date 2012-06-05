#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <cmath>
using namespace std;

#define MAX_NODE 105

typedef int Graph[MAX_NODE][MAX_NODE];
typedef double Graph1[MAX_NODE][MAX_NODE];
Graph G;
Graph1 C;                                        //capacity
Graph1 f;                                        //flow
Graph1 R;                                        //Residual
int h[MAX_NODE];                        //height
double e[MAX_NODE];                        //excess
int current[MAX_NODE];      //position in the adjacent list of vertices
int deg[MAX_NODE];          //degree
int n;                                          //number of vertices
int s;                                          //source
int t;                                          //sink
const double inf = 1.e10;
const double eps = 1.e-6;
void INSERT_EDGE(int x,int y,double w)
{
     R[x][y]=C[x][y]=w;
	 R[y][x]=C[y][x]=w;
     G[x][deg[x]++]=y;
     G[y][deg[y]++]=x;
}
void INITIALIZE_PREFLOW()
{
        int u;
        memset(h,0,sizeof(h));
        memset(e,0,sizeof(e));
        memset(f,0,sizeof(f));
        h[s]=n;
        for(u=0;u<n;u++){
                f[s][u]=C[s][u];
                f[u][s]=-C[s][u];
                e[u]=C[s][u];
                e[s]-=C[s][u];
                R[s][u]=C[s][u]-f[s][u];
                R[u][s]=C[u][s]-f[u][s];
        }
}

void PUSH(int u,int v)
{
        double d;
        d=e[u]<R[u][v]?e[u]:R[u][v];
        f[u][v]+=d;
        f[v][u]-=d;
        R[u][v]-=d;
        R[v][u]+=d;
        e[u]-=d;
        e[v]+=d;
}

void RELABEL(int u)
{
        int min_h=INT_MAX;
		int v,i;
        for(i=0;i<deg[u];i++){
                v=G[u][i];
                if (R[u][v]>0&&h[v]<min_h) min_h=h[v];
        }
        h[u]=min_h+1;
}

void DISCHARGE(int u)
{
        int v;
        while(e[u]>0){
                v=G[u][current[u]];
                if (current[u]==deg[u]){
                        RELABEL(u);
                        current[u]=0;
                }
                else if (R[u][v]>0&&h[u]==h[v]+1) PUSH(u,v);
                else current[u]++;
        }
}

double RELABEL_TO_FRONT()
{
        int u,old_height;
		double ret=0;
        list<int> L;
        list<int>::iterator it;
        memset(current,0,sizeof(current));
        INITIALIZE_PREFLOW();
        for(u=0;u<n;u++)if (u!=s&&u!=t) L.push_back(u);
        for(it=L.begin();it!=L.end();it++){
                u=*it;
                old_height=h[u];
                DISCHARGE(u);
                if (h[u]>old_height){
                        L.erase(it);
                        L.push_front(u);
                        it=L.begin();
                }
        }
        for(u=0;u<n;u++) ret+=f[s][u];
        return ret;
}

typedef long long ll;
typedef vector<int> vi;
#define mset(a,x) memset(a,x,sizeof(a))
#define ABS(a) ((a) >= 0 ? (a) : -(a))
struct node {
       int x, y;
	   double c;
};
node edg[405];
bool res[405];
bool use[405];
double high, low, mid;
double rr;
int m;
bool check(double mid) {
     mset(use, 0);
     mset(deg, 0);
	 mset(R, 0);
	 mset(C, 0);
	 mset(f, 0);
	 double tres = 0;
	 int i;
     for (i = 0; i < m; i++) {
		  if (edg[i].c - mid <= 0) {
		      tres += edg[i].c - mid;
			  use[i] = 1;
		  }
		  else {
              INSERT_EDGE(edg[i].x,edg[i].y,edg[i].c - mid);
		  }
	 }
	 tres += RELABEL_TO_FRONT();
	 for (i = 0; i < m; i++) {
	      if (!use[i] && ((h[edg[i].x] >= n && h[edg[i].y] < n) || (h[edg[i].y] >= n && h[edg[i].x] < n)))
			  use[i] = 1;
	 }
	 if (tres <= eps)
		 return 1;
	 else
		 return 0;
}
void solve() {
	 mset(res, 0);
	 low = 0;
	 high = 1.e8;
	 rr = 1.e8;
     while (high-low > eps) {
	        mid = (high+low)/2.0;
            if (check(mid)) {
				if (rr > mid) {
			        memcpy(res, use, sizeof(use));
			        rr = mid;
				}
				high = mid;
			}
			else {
			    low = mid;
			}
	 }

	 int cnt(0), i, r = 0;
	 for (i = 0; i < m; i++)
		  if (res[i]) cnt++;
	 printf("%d\n", cnt);
	 for (i = 0; i < m; i++)
		  if (res[i]) printf("%d%c", i+1, ((++r) == cnt)?'\n':' ');
}
int main()
{
    freopen("input", "r", stdin);
    freopen("test.out", "w", stdout);
	int i, j;
	bool fir = 1;
	while (scanf("%d%d", &n, &m) == 2) {
	       if (fir) fir = 0;
		   else puts("");
		   s = 0;
		   t = n-1;
           for (i = 0; i < m; i++) {
		        scanf("%d%d%lf", &edg[i].x, &edg[i].y, &edg[i].c);
				--edg[i].x;
				--edg[i].y;
		   }
           solve();
	}
	return 0;
}
