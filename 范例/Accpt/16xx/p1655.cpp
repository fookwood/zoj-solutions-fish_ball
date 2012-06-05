#include <iostream.h>
#include <stdio.h>


long    n,m;
double  save[101];
double  dis[101][101],maxget[101];
bool    team[101];

void dij();

void dij()
{
int     i,k;
double  max,ans;
for (i=1;i<=n ;i++) team[i]=0;

maxget[n]=1;
do
{
        k=-1;
        max=-1e10;

        for (i=1;i<=n;i++)
                if (! team[i] && maxget[i]>max)
                        {
                        max=maxget[i];
                        k=i;
                        }

        if (k>0)
                {
                team[k]=1;
                for (i=1;i<=n;i++)
                        if (! team[i] && dis[k][i]>-1e10 &&
                                maxget[k] * dis[k][i]>maxget[i])
                                maxget[i]=maxget[k] * dis[k][i];
                }
        else break;
} while (1);

ans=0;
for (i=1;i<=n-1;i++) ans+=save[i] * maxget[i];
printf("%.2f\n",ans);
}

main()
{
long    i;
long    a,b;
double  temp;
while (cin>>n)
        {
        cin>>m;
        for (i=1;i<=n-1;i++) cin>>save[i];

        for (a=1;a<=n;a++)
                {
                for (b=1;b<=n;b++) dis[a][b]=-1e10;
                maxget[a]=1e-10;
                }


        for (i=1;i<=m;i++)
                {
                cin>>a>>b>>temp;
                temp=1-temp;
                if (temp>dis[a][b])
                        {
                        dis[a][b]=temp;
                        dis[b][a]=temp;
                        }
                }

        dij();
        }
}
