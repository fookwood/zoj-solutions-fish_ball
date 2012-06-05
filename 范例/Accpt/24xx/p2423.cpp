#include <iostream.h>
#include <math.h>

bool    map[8][730][730];
int     num[8];

void MakeMap();
void Print(int n);

void Print(int n)
{
int     i,j,k;
for (i=1;i<=num[n];i++) {
        for (j=num[n];! map[n][i][j];j--);
        for (k=1;k<=j;k++)
                if (map[n][i][k]) cout<<'X';
                else cout<<' ';
        cout<<endl;
}
cout<<'-'<<endl;
}


void MakeMap()
{
int     i,j,k,len;

num[1]=1;
for (i=2;i<8;i++) num[i]=num[i-1] * 3;

for (i=1;i<=7;i++) for (j=1;j<730;j++) for (k=1;k<730;k++) map[i][j][k]=false;

map[1][1][1]=true;
len=1;
for (i=2;i<=7;i++) {
        for (j=1;j<=len;j++) {
                for (k=1;k<=len;k++) {
                        map[i][j][k]=
                        map[i][j][len+len+k]=
                        map[i][j+len][len+k]=
                        map[i][j+len+len][k]=
                        map[i][j+len+len][k+len+len]=
                        map[i-1][j][k];
                        }
        }
        len*=3;
}
}

main()
{
int     n;
MakeMap();
while (cin>>n && n!=-1) {
        Print(n);
}
}
 