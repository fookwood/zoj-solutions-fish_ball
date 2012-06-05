#include <iostream.h>
#define max 100000


long    minway[9999];
int     start,goal;
long    line[9999];
long    order[5];

void init();
void Work();
void print(long x);
long add(long p,int q);
long sub(long p,int q);
long change(long p,int  q);

long change(long p,int q)
{
long d;
d=p;
d-=p % order[q] / order[q-1] * order[q-1];
d-=p % order[q+1] / order[q] * order[q];
d+=p % order[q] / order[q-1] * order[q];
d+=p % order[q+1] / order[q] * order[q-1];
return d;
}

long sub(long p,int q)
{
if (p % order[q] / order[q-1] ==1)
        return p+order[q-1] * 8;
        else return p-order[q-1];
}
long add(long p,int q)
{
if (p % order[q] / order[q-1] ==9 )
        return p-order[q-1]*8;
        else return p+order[q-1];
}



void init()
{
for (int i=1111;i<=9999;i++) minway[i]=max;
}

void print(long x)
{
cout<<minway[x]<<endl;
return;
}

void Work()
{
int temp;
int open=1,closed=1;

line[1]=start;
minway[start]=0;
if (start==goal) {
        cout<<0<<endl;
        return;
}

do {
        for (int i=1;i<=4;i++) {
                temp=add(line[open],i);
                if (minway[line[open]]+1<minway[temp]) {
                minway[temp]=minway[line[open]]+1;
                line[++closed]=temp;
                }
                
                if (temp==goal) {print (temp ); return ;};

                temp=sub(line[open],i);
                if (minway[line[open]]+1<minway[temp]) {
                line[++closed]=temp;
                minway[temp]=minway[line[open]]+1;
                if (temp==goal) {print(temp); return ;};
                }

                if (i<4) {
                temp=change(line[open],i);
                if (minway[line[open]]+1<minway[temp]) {
                        line[++closed]=temp;
                        minway[temp]=minway[line[open]]+1;
                        if (temp==goal) {print (temp) ; return ;};
                }
                }
        }
        open++;
} while (open<=closed);

}

main()
{
int part;


order[0]=1;
for (int i=1;i<5;i++) order[i]=order[i-1]*10;

cin>>part;
for (;part>0;part--) {
        init();
        cin>>start>>goal;
        Work();
}
}
 