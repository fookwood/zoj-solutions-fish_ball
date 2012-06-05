// This is a Dp program
// time         2005//04//17

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define   MAX   1e10;

int     n;
struct  num {
        double     x,y;
}       pos[200];
int     minnum[200];

double   ans[200][2];


void Readin();
double   Work();
bool    comp1(const num & a, const num & b);
double maxone  (double a,double b);
double minone  (double a,double b);
double   dis(double a,double b,double c,double d);

double dis(double a,double b,double c, double d)
{
return sqrt( (a-b) * (a-b) + (c-d) * (c-d));
}


double maxone(double a ,double b)
{
return a>b?a:b;
}

double minone(double a, double b)
{
return a<b?a:b;
}


bool comp1(const num & a , const  num & b)
{
return a.y<b.y;
}


double Work()
{
int     i,j;
float   min,up,down;




/*for (i=0;i<n;i++) {
        cout<<pos[i].x<<' '<<pos[i].y<<endl;
} */

sort(pos , pos + n, comp1);

ans[0][0]=ans[0][1]=MAX;

/*cout<<"here are the position:"<<endl;

for (i=0;i<n;i++) {
        cout<<pos[i].x<<' '<<pos[i].y<<endl;
} */



for (i=1;i<n;i++) {
        min=MAX;
        for (j=0;j<i;j++)
                if ( sqrt((pos[i].x-pos[j].x)* (pos[i].x - pos[j].x)
                + (pos[i].y-pos[j].y) * (pos[i].y-pos[j].y))<min) {
                min=sqrt((pos[i].x-pos[j].x) * (pos[i].x - pos[j].x)
                + (pos[i].y-pos[j].y) * (pos[i].y-pos[j].y));
                minnum[i]=j;
                }
}

for (i=1;i<n;i++) {
        up=dis (pos[i].x,pos[i-1].x,pos[i].y,pos[i-1].y);
        up=minone(up,ans[i-1][0]);
        if (i-1!=minnum[i]) up=minone(up,dis(pos[i].x,pos[minnum[i]].x,pos[i].y-1,pos[minnum[i]].y-1));
        down= dis (pos[i].x,pos[i-1].x,pos[i].y-1,pos[i-1].y+1);
        down=minone(down,ans[i-1][1]);
        if (i-1!=minnum[i]) down=minone(down,dis(pos[i].x,pos[minnum[i]].x,pos[i].y-1,pos[minnum[i]].y-1));
        ans[i][0] = maxone (up,down);

        up=dis(pos[i].x,pos[i-1].x,pos[i].y,pos[i-1].y);
        up=minone(up,ans[i-1][1]);
        if (i-1!=minnum[i]) up=minone(up,dis(pos[i].x,pos[minnum[i]].x,pos[i].y+1,pos[minnum[i]].y-1));
        down= dis (pos[i].x,pos[i-1].x,pos[i].y+1,pos[i-1].y-1);
        down=minone (down ,ans[i-1][0]);
        if (i-1!=minnum[i]) down=minone (down ,dis(pos[i].x,pos[minnum[i]].x,pos[i].y+1,pos[minnum[i]].y-1));
        ans[i][1] = maxone (up,down);
}


if (ans[n-1][0]>ans[n-1][1]) return ans[n-1][0];
        else return ans[n-1][1];

}


// input 
void Readin()
{
int i;
cin>>n;
if (n==0) exit(0);
for (i=0;i<n;i++) cin>>pos[i].x>>pos[i].y;
}

main()
{
cout.precision(3);
cout.setf(ios::fixed);
while (1) {
        Readin();
        cout<<Work()<<endl;
}
}
 