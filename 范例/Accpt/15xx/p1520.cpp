// after finish the cryptcow I start with zoj again
// algorithm    :Dp 0-1 backball
// time         :2005/04/14


#include <iostream.h>

#define  MAX    2000

bool    Reach[MAX],chose[MAX];
        // 0-1 DP
int     M,L,N;
        // the number of two kinds sweat

int     Sum;
int     from[MAX],num[MAX];
        // the number chosed before

void Input();
void Dp();
void output(bool ans);

void output(bool ans)
{
int     i,j,total;
if (ans) {
total=0;
for (i=0;i<N;i++)
        if (chose[i]) total++;
cout<<total;
for (i=0;i<N;i++)
        if (chose[i]) cout<<' '<<i+1;
cout<<endl;
} else
        cout<<"Impossible to distribute"<<endl;
}



void Dp()
{
int     i,j;
for (i=1;i<=M;i++) {
        Reach[i]=false;
        from[i]=0;
        }
        
Reach[0]=true;

Sum=0;

for (i=0;i<N;i++) {
        Sum += num[i];
        for (j=M;j>=num[i];j--)
                if ( ! Reach[j] && Reach[j-num[i]] ) {
                        Reach[j]=true;
                        from[j]=i;
                }
}

for (i=M;i>=0;i--)
        if (Reach[i]) break;

if (Sum>M+L || Sum - i > L ) {
        output(0);
}
        else {
        j=i;
        for (i=0;i<N;i++) chose[i]=false;
        for (i=j;i>0;i-=num[from[i]]) {
                chose[from[i]]=true;
        }
        output(1);                            
        }
}

// Just for input
void Input()
{
int     i;
cin>>M>>L;
if (M==0 && L==0) {
        exit(0);
}

cin>>N;
for (i=0;i<N;i++) {
        cin>>num[i];
}
}



main()
{
while (1) {
        Input();
        Dp();
}
}
 