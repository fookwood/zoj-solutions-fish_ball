#include <iostream.h>
#include <stdio.h>


bool    whether[10001];
int     prime[10001];
int     m;
int     ans[10001][4];

void makeprime();
void work(int n);

void makeprime()
{
int     i,j;
for (i=0;i<=10000;i++) whether[i]=true;

for (i=2;i<=10000;i++)
        if (whether[i]) {
        for (j=2;j<=10000/i;j++) whether[i*j]=false;
        }
}

void work(int n)
{
int     i;

if (n==1) {
        ans[n][0]=0;
        return ;
        }
        
if (whether[n]) {
        ans[n][0]=1;
        ans[n][1]=n;
        return;
        }

if ( n%2==0 ) {
        for (i=n/2; !(whether[i] && whether[n-i]); i++);
        ans[n][0]=2;
        ans[n][2]=i;
        ans[n][1]=n-i;
        return;
        }

if (whether[n-2]) {
        ans[n][0]=2;
        ans[n][1]=2;
        ans[n][2]=n-2;
        return;
        }

                        
for (i=(n+2)/3; ans[n-i][0]!=2 || ans[n-i][2]>i || !whether[i];i++);
ans[n][0]=3;
ans[n][1]=ans[n-i][1];
ans[n][2]=ans[n-i][2];
ans[n][3]=i;
return;

if (ans[n-2][0]==2)
        {
        ans[n][0]=3;
        ans[n][1]=2;
        ans[n][2]=ans[n-2][1];
        ans[n][3]=ans[n-2][2];
        return;
        }

ans[n][0]=3;
ans[n][1]=3;

n-=3;

for (i=n/2; !(whether[i] && whether[n-i]);i++);

ans[n+3][3]=i;
ans[n+3][2]=n-i;

return;
}

main()
{
makeprime();
ans[0][0]=0;

for (int i=1;i<=10000;i++) work(i);

while (scanf("%ld\n",&m)>0) {
        printf("%d\n",ans[m][0]);
        if (ans[m][0]>=1) {
        printf("%ld",ans[m][ans[m][0]]);
        for (int i=ans[m][0]-1;i>=1;i--) {
        printf(" %d",ans[m][i]);
        }
printf("\n");
        }
        
}
}
