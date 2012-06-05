#include <iostream.h>
#include <math.h>

#define _T double
#define float double

int     a[3], b[4]={0,0,0,1};
float     r[3];

long    f(long x);
long    up(long x);

inline void swap(_T & a,_T & b)
{
        _T t=a;a=b;b=t;
}

long up(long x)
{
return a[2] * x * x + a[1] * x + a[0];
}

long f(long x)
{
return  x*x*x + b[2] * x * x + b[1] * x + b[0];
}


void work();

void work()
{
int     i;
long    j,q;
int     t;
t=0;

q=abs(b[0]);

if (q!=0)
for (j =1;j<=long( sqrt(q) );j++) {
        if (f(j)==0) r[t++]=j;
        if (f(-j)==0) r[t++]=-j;
        if (f(q/j)==0) r[t++]=q/j;
        if (f(-q/j)==0) r[t++]=-q/j;
        }
        else {
        r[t++]=0;
        r[t++]=( - b[2] - sqrt(b[2] * b[2] - 4*b[1]) )/2;
        r[t++]=( - b[2] + sqrt(b[2] * b[2] - 4 * b[1]) ) /2;
        }

if (r[0]>r[1]) swap(r[0],r[1]);
if (r[0]>r[2]) swap(r[0],r[2]);
if (r[1]>r[2]) swap(r[1],r[2]);

cout.precision(0);
cout.setf(ios::fixed);
cout<<r[0]<<' '<<r[1]<<' '<<r[2];
cout.precision(2);
cout.setf(ios::fixed);

cout << ' ' <<up(r[0])/ (r[0]-r[1]) / (r[0]-r[2])
<<' '<<up(r[1])/(r[1]-r[0])/(r[1]-r[2])<<' '
<<up(r[2])/(r[2]-r[0])/(r[2]-r[1])<<endl;
}

main()
{
while (1) {
        for (int i=0;i<3;i++) cin>>a[i];
        for (int i=0;i<3;i++) cin>>b[i];
        if (a[0]==0 && a[1]==0 && a[2]==0) break;
        work();
        }
}
