#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#define maxn 21
bool visited[maxn];
int g[maxn][maxn];
int n,m;
int s,t;
int Max;
struct CPath{
	int node[maxn];
	int dist;
	bool friend operator < (const CPath &p1,const CPath &p2)
	{
		if(p1.dist!=p2.dist) return p1.dist<p2.dist;
		int i,j;
		for(i=0,j=0;p1.node[i]&&p2.node[j]&&p1.node[i]==p2.node[j];i++,j++);
		return p1.node[i]<p2.node[j];
	}
}path[maxn*maxn];
int ans;
int stk[maxn];
void search(int node,int dist,int cnt)
{
	if(dist>Max) return;
	if(node==t){
		path[ans].dist=dist;
		stk[cnt]=0;
		memcpy(path[ans].node,stk,sizeof(stk));
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(g[node][i]!=-1&&!visited[i]){
			visited[i]=true;
			int sav=stk[cnt];
			stk[cnt]=i;
			search(i,dist+g[node][i],cnt+1);
			visited[i]=false;
			stk[cnt]=sav; 
		}
}
int main()
{
//	freopen("a.txt","r",stdin);
	int tt=1;
	while(scanf("%d%d",&n,&m),n!=-1){
		if(tt!=1) putchar(10);
		memset(g,-1,sizeof(g));
		int p1,p2,dist;
		while(m--){
			scanf("%d%d%d",&p1,&p2,&dist);
			g[p2][p1]=g[p1][p2]=dist;
		}
		scanf("%d%d",&s,&t);
		scanf("%d",&Max);
		memset(visited,0,sizeof(visited));
		ans=0;
		visited[s]=1;
		stk[0]=s;
		memset(path,0,sizeof(path));
		search(s,0,1);
		printf("Case %d:\n",tt++);
		if(ans==0) puts(" NO ACCEPTABLE TOURS");
		else {
			sort(path,path+ans);
			for(int i=0;i<ans;i++)
			{
				printf(" %d:",path[i].dist);
				for(int j=0;path[i].node[j];j++)
					printf(" %d",path[i].node[j]);
				putchar(10);
			}
		}
	}
	return 0;
}
//1724787 2006-03-30 19:47:52 Accepted 2406 C++ 00:00.00 480K OneYearOld 
//tmd看这是什么输出格式...前面居然有空格..