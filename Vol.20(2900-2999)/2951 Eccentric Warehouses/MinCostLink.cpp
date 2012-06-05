\begin{lstlisting}
#define maxn 350
#define maxm 100000 // maxm*2
const int inf=0x3fffffff;

int c[maxm],f[maxm],w[maxm],ev[maxm],be[maxm],next[maxm],value[maxn];
int nbs[maxn],pnt[maxn],open[maxn],oldque[maxn],d[maxn],mk[maxn],num=0;

void AddEdge(int u,int v,int cc,int ww) // Remember to set nbs[1..n]=num=0
{
    next[++num]=nbs[u];    nbs[u]=num; be[num]=num+1;
    ev[num]=v; c[num]=cc;  f[num]=0; w[num]=ww;
    next[++num]=nbs[v];    nbs[v]=num; be[num]=num-1;
    ev[num]=u; c[num]=0 ;  f[num]=0; w[num]=-ww;
}

void mincost(int n,int s,int t,int &flow,int &cost)
{
    int cur,tail,tl,i,j,u,v;
    memset(f,0,sizeof(f)); flow=0; cost=0;
    do{ memset(d,0,sizeof(d));
        for(i=1;i<=n;i++) value[i]=inf; 
        open[0]=s; d[s]=0x3fffffff; tail=value[s]=0;
        while(tail>=0){
            memset(mk,0,sizeof(mk)); 
            memcpy(oldque,open,sizeof(open));
            for(tl=tail,pnt[s]=cur=0,tail=-1; cur<=tl; cur++)
            for(u=oldque[cur],j=nbs[u];j;j=next[j]){ v=ev[j];
                if(f[j]<c[j] && value[u]<inf && value[u]+w[j]<value[v]){
                    if(!mk[v]){ mk[v]=1; open[++tail]=v;};
                    pnt[v]=j; value[v]=value[u]+w[j];
                    if(d[u]<c[j]-f[j]) d[v]=d[u]; else d[v]=c[j]-f[j];
                }
            }
        }
        if(value[t]==inf) return;
        flow+=d[t]; cost+=d[t]*value[t];
        for(u=t;u!=s;u=ev[be[j]]){j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j];}      
    } while(d[t]>0);
}
\end{lstlisting}
