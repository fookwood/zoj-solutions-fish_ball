// 3052145 2008-08-27 11:26:39 Accepted 1465 C++ 00:00.03 496K 呆滞的慢板 

// 使用别人的凸包模块 

// CONVEX HULL I
// modified by rr 不能去掉点集中重合的点
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

const double PI = acos( -1.0 ); 

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int main() {

    point   A[1000],    B[1000];
    
    int n,  s;
    
    int     T,  N,  L;
    
    point   P;
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &N, &L );
        
        for( int i = 0; i < N; ++i )
            scanf( "%lf%lf", &A[i].x, &A[i].y );
        
        _graham( N, A, s=0, B );
        
        double  ans = 2.0 * PI * L;
        
        for( int i = 0; i < s; ++i )
            ans += hypot(B[i].x-B[(i+1)%s].x,B[i].y-B[(i+1)%s].y);

        printf( "%d\n", int( ans + 0.5 ) );
        
        if( T ) puts( "" );
        
    }
    
}
