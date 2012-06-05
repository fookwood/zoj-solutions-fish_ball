#include <iostream.h>

int     n;
long    sum[7],num[7][7],minsum[8];
long    ans;

void    Readin();
void    Search(int      depth);

void    Search(int      depth)
{
int     i,j;
long    minsum_simple;
bool    big;

if (depth==n) {
        long    max;
        max=-99999999;
        for (int i=0;i<n;i++) if (sum[i]>max) max=sum[i];
        if (max<ans) ans=max;
        return;
}

for (i=0;i<n;i++) {
        big=false;
        minsum_simple=-99999999;
        for (j=0;j<n;j++) {
                sum[j]+=num[depth][(j+i)%n];
                if (sum[j]/*+minsum[i+1]*/>ans) big=true;
                if (sum[j]>minsum_simple) minsum_simple=sum[j];
                }
        if (minsum_simple+minsum[depth+1]>ans) big=true;
        if ( ! big) Search(depth+1);
        for (j=0;j<n;j++)
                sum[j]-=num[depth][(j+i)%n];
        }
}


void    Readin()
{
int     i,j;
for (i=0;i<n;i++) {
        minsum[i]=9999999;
        for (j=0;j<n;j++) {
                cin>>num[i][j];
                if (num[i][j]<minsum[i]) minsum[i]=num[i][j];
        }
}
minsum[n+1]=0;
for (i=n-2;i>=0;i--) minsum[i]+=minsum[i+1];
}



main()
{
while (cin>>n && n!=-1) {
        Readin();
        for (int i=0;i<n;i++) sum[i]=num[0][i];
        ans=99999999;
        Search(1);
        cout<<ans<<endl;
}
}
