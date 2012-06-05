// 2982060 2008-07-16 10:52:36 Accepted 2699 C++ 00:01.12 4948K 呆滞的慢板 

// 问题描述：
// 有一个图，N 个顶点由 M 条有向边连接
//   现在要对图上的 K 个顶点做标记，使得：
//   1. 图上所有的顶点，都存在路径可以通向一个标记的顶点；
//   2. 图上所有的顶点，都可以从某个标记的顶点达到。
// 问这样的标记方法共有多少种？ 

// 术语：
//   1. 覆盖：假设在整个图中已经对某些顶点进行标记，那么
//      对于某个顶点，满足上述两个条件的，称该顶点被覆盖；
//   2. 强分量：一个有向图中的某些顶点子集（包括连接他们的边），
//      如果 1) 对于此子图中任意两点，存在相互到达的路径；
//           2) 在图中加入任意一个顶点之后此子图不具有 1) 性质；
//      那么称此子图为强分量；
//   3. 核心 DAG：一个有向图可以分解成若干个强分量，那么仅考虑
//      可达性的时候，可以将这些强分量等效成一个顶点，强分量之间
//      若存在路径，则等效成一个有向边，那么等效出来的图是一个 DAG， 
//      称为该图的核心 DAG。 

// 这是一个有向图的可达性以及组合数学的问题：
// 下面阐述几个事实：
//   1. 假设图中有 N* 个强分量，那么在每个强分量中标记一个顶点，
//      都可以覆盖所有的强分量中的顶点。
//   2. 定理：对于一个 DAG，他所有顶点被覆盖的充要条件是：
//      它的所有源点和汇点都被标记。
//   3. 推论：对于任意一个有向图，要覆盖所有的顶点，充要条件是：
//      所有在核心 DAG 中处于源点和汇点的强分量中，至少有一个
//      顶点被标记。

// 寻找一个有向图的强分量和核心 DAG 可以在线性时间内达到，那么
// 问题转化成下述组合数学的问题：
//   1. 已经找出了 W 个源点或汇点强分量 Ti(1=1..W)；
//   2. 每个这样的强分量包含了 U[i] 个顶点，加起来一共有 U 个顶点；
//   3. 不在这些顶点以外的还有 V 个顶点； 
//   3. 假设在这样一组 U[i] 里面取 C 个数的组合，每个 U[i] 
//      至少取一个，for(W<=C<=K)，共有 X(C)组合；
//   4. 剩下的可标记顶点数为 U = K - C，在其余顶点中取组合
//      Y(C) = comb(V,K-C)；
//   5. 最后的结果应该是：sigma(X(C)*Y(C)) (for(W<=C<=K)) 

// 怎么去解决这个组合问题，可以应用 DP：
// 对于 vector U, U[i]  ( 0 <= i < U.size() )
// 如果要往里面放 C 个数，并且至少放一个
// 构造 DP 表：DP[U.size()][K]
//   1. 初值 DP[0][j] = comb(U[0], j)
//   2. 递推 DP[i][j] = sigma_t( DP[i-1][t] * comb(U[i], j-t)
//   3. 约束 DP[i][j] = 0，当 (j<=i) 
// 貌似这些组合数可以飙到很大，因此要使用大数模板 

#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>
using namespace std;

#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

int read(bignum_t a,istream& is=cin){
	char buf[MAX*DIGIT+1],ch;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>buf))	return 0;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}

void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
}

int comp(const bignum_t a,const bignum_t b){
	int i;
	if (a[0]!=b[0])
		return a[0]-b[0];
	for (i=a[0];i;i--)
		if (a[i]!=b[i])
			return a[i]-b[i];
	return 0;
}

int comp(const bignum_t a,const int b){
	int c[12]={1};
	for (c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}

int comp(const bignum_t a,const int c,const int d,const bignum_t b){
	int i,t=0,O=-DEPTH*2;
	if (b[0]-a[0]<d&&c)
		return 1;
	for (i=b[0];i>d;i--){
		t=t*DEPTH+a[i-d]*c-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	for (i=d;i;i--){
		t=t*DEPTH-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	return t>0;
}

void add(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

void add(bignum_t a,const int b){
	int i=1;
	for (a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void sub(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]-=b[i])<0)
			a[i+1]--,a[i]+=DEPTH;
	for (;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const int b){
	int i=1;
	for (a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const bignum_t b,const int c,const int d){
	int i,O=b[0]+d;
	for (i=1+d;i<=O;i++)
		if ((a[i]-=b[i-d]*c)<0)
			a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
	for (;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t c,const bignum_t a,const bignum_t b){
	int i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for (c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
		for (j=1;j<=b[0];j++)
			if ((c[i+j-1]+=a[i]*b[j])>=DEPTH)
				c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for (c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}

void mul(bignum_t a,const int b){
	int i;
	for (a[1]*=b,i=2;i<=a[0];i++){
		a[i]*=b;
		if (a[i-1]>=DEPTH)
			a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
	}
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t b,const bignum_t a,const int c,const int d){
	int i;
	memset((void*)b,0,sizeof(bignum_t));
	for (b[0]=a[0]+d,i=d+1;i<=b[0];i++)
		if ((b[i]+=a[i-d]*c)>=DEPTH)
			b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH;
	for (;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
	for (;!b[b[0]]&&b[0]>1;b[0]--);
}

void div(bignum_t c,bignum_t a,const bignum_t b){
	int h,l,m,i;
	memset((void*)c,0,sizeof(bignum_t));
	c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1;
	for (i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
		for (h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!c[c[0]]&&c[0]>1;c[0]--);
	c[0]=c[0]>1?c[0]:1;
}

void div(bignum_t a,const int b,int& c){
	int i;
	for (c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sqrt(bignum_t b,bignum_t a){
	int h,l,m,i;
	memset((void*)b,0,sizeof(bignum_t));
	for (i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
		for (h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!b[b[0]]&&b[0]>1;b[0]--);
	for (i=1;i<=b[0];b[i++]>>=1);
}

int length(const bignum_t a){
	int t,ret;
	for (ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);
	return ret>0?ret:1;
}

int digit(const bignum_t a,const int b){
	int i,ret;
	for (ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);
	return ret%10;
}

int zeronum(const bignum_t a){
	int ret,t;
	for (ret=0;!a[ret+1];ret++);
	for (t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);
	return ret;
}

void comp(int* a,const int l,const int h,const int d){
	int i,j,t;
	for (i=l;i<=h;i++)
		for (t=i,j=2;t>1;j++)
			while (!(t%j))
				a[j]+=d,t/=j;
}

void convert(int* a,const int h,bignum_t b){
	int i,j,t=1;
	memset(b,0,sizeof(bignum_t));
	for (b[0]=b[1]=1,i=2;i<=h;i++)
		if (a[i])
			for (j=a[i];j;t*=i,j--)
				if (t*i>DEPTH)
					mul(b,t),t=1;
	mul(b,t);
}

void combination(bignum_t a,int m,int n){
	int* t=new int[m+1];
	memset((void*)t,0,sizeof(int)*(m+1));
	comp(t,n+1,m,1);
	comp(t,2,m-n,-1);
	convert(t,m,a);
	delete []t;
}

void permutation(bignum_t a,int m,int n){
	int i,t=1;
	memset(a,0,sizeof(bignum_t));
	a[0]=a[1]=1;
	for (i=m-n+1;i<=m;t*=i++)
		if (t*i>DEPTH)
			mul(a,t),t=1;
	mul(a,t);
}

#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))

int read(bignum_t a,int &sgn,istream& is=cin){
	char str[MAX*DIGIT+2],ch,*buf;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>str)) return 0;
	buf=str,sgn=1;
	if (*buf=='-') sgn=-1,buf++;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	if (a[0]==1&&!a[1]) sgn=0;
	return 1;
}

struct bignum{
	bignum_t num;
	int sgn;
public:
inline bignum(int xx = 0){memset(num,0,sizeof(bignum_t));num[0]=1;num[1]=xx;sgn=0;}
inline int operator!(){return num[0]==1&&!num[1];}
inline bignum& operator=(const bignum& a){memcpy(num,a.num,sizeof(bignum_t));sgn=a.sgn;return *this;}
inline bignum& operator=(const int a){memset(num,0,sizeof(bignum_t));num[0]=1;sgn=SGN(a);add(num,sgn*a);return *this;};
inline bignum& operator+=(const bignum& a){if(sgn==a.sgn)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memcpy(num,a.num,sizeof(bignum_t));sub(num,t);sgn=a.sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)memcpy(num,a.num,sizeof(bignum_t)),sgn=a.sgn;return *this;}
inline bignum& operator+=(const int a){if(sgn*a>0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memset(num,0,sizeof(bignum_t));num[0]=1;add(num,ABS(a));sgn=-sgn;sub(num,t);}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)sgn=SGN(a),add(num,ABS(a));return *this;}
inline bignum operator+(const bignum& a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret+=a;return ret;}
inline bignum operator+(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret+=a;return ret;}
inline bignum& operator-=(const bignum& a){if(sgn*a.sgn<0)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memcpy(num,a.num,sizeof(bignum_t));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)add(num,a.num),sgn=-a.sgn;return *this;}
inline bignum& operator-=(const int a){if(sgn*a<0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memset(num,0,sizeof(bignum_t));num[0]=1;add(num,ABS(a));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)sgn=-SGN(a),add(num,ABS(a));return *this;}
inline bignum operator-(const bignum& a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret-=a;return ret;}
inline bignum operator-(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret-=a;return ret;}
inline bignum& operator*=(const bignum& a){bignum_t t;mul(t,num,a.num);memcpy(num,t,sizeof(bignum_t));sgn*=a.sgn;return *this;}
inline bignum& operator*=(const int a){mul(num,ABS(a));sgn*=SGN(a);return *this;}
inline bignum operator*(const bignum& a){bignum ret;mul(ret.num,num,a.num);ret.sgn=sgn*a.sgn;return ret;}
inline bignum operator*(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));mul(ret.num,ABS(a));ret.sgn=sgn*SGN(a);return ret;}
inline bignum& operator/=(const bignum& a){bignum_t t;div(t,num,a.num);memcpy(num,t,sizeof(bignum_t));sgn=(num[0]==1&&!num[1])?0:sgn*a.sgn;return *this;}
inline bignum& operator/=(const int a){int t;div(num,ABS(a),t);sgn=(num[0]==1&&!num[1])?0:sgn*SGN(a);return *this;}
inline bignum operator/(const bignum& a){bignum ret;bignum_t t;memcpy(t,num,sizeof(bignum_t));div(ret.num,t,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*a.sgn;return ret;}
inline bignum operator/(const int a){bignum ret;int t;memcpy(ret.num,num,sizeof(bignum_t));div(ret.num,ABS(a),t);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*SGN(a);return ret;}
inline bignum& operator%=(const bignum& a){bignum_t t;div(t,num,a.num);if (num[0]==1&&!num[1])sgn=0;return *this;}
inline int operator%=(const int a){int t;div(num,ABS(a),t);memset(num,0,sizeof(bignum_t));num[0]=1;add(num,t);return t;}
inline bignum operator%(const bignum& a){bignum ret;bignum_t t;memcpy(ret.num,num,sizeof(bignum_t));div(t,ret.num,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn;return ret;}
inline int operator%(const int a){bignum ret;int t;memcpy(ret.num,num,sizeof(bignum_t));div(ret.num,ABS(a),t);memset(ret.num,0,sizeof(bignum_t));ret.num[0]=1;add(ret.num,t);return t;}
inline bignum& operator++(){*this+=1;return *this;}
inline bignum& operator--(){*this-=1;return *this;};
inline int operator>(const bignum& a){return sgn>0?(a.sgn>0?comp(num,a.num)>0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<0:0):a.sgn<0);}
inline int operator>(const int a){return sgn>0?(a>0?comp(num,a)>0:1):(sgn<0?(a<0?comp(num,-a)<0:0):a<0);}
inline int operator>=(const bignum& a){return sgn>0?(a.sgn>0?comp(num,a.num)>=0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<=0:0):a.sgn<=0);}
inline int operator>=(const int a){return sgn>0?(a>0?comp(num,a)>=0:1):(sgn<0?(a<0?comp(num,-a)<=0:0):a<=0);}
inline int operator<(const bignum& a){return sgn<0?(a.sgn<0?comp(num,a.num)>0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<0:0):a.sgn>0);}
inline int operator<(const int a){return sgn<0?(a<0?comp(num,-a)>0:1):(sgn>0?(a>0?comp(num,a)<0:0):a>0);}
inline int operator<=(const bignum& a){return sgn<0?(a.sgn<0?comp(num,a.num)>=0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<=0:0):a.sgn>=0);}
inline int operator<=(const int a){return sgn<0?(a<0?comp(num,-a)>=0:1):(sgn>0?(a>0?comp(num,a)<=0:0):a>=0);}
inline int operator==(const bignum& a){return (sgn==a.sgn)?!comp(num,a.num):0;}
inline int operator==(const int a){return (sgn*a>=0)?!comp(num,ABS(a)):0;}
inline int operator!=(const bignum& a){return (sgn==a.sgn)?comp(num,a.num):1;}
inline int operator!=(const int a){return (sgn*a>=0)?comp(num,ABS(a)):1;}
inline int operator[](const int a){return digit(num,a);}
friend inline istream& operator>>(istream& is,bignum& a){read(a.num,a.sgn,is);return is;}
friend inline ostream& operator<<(ostream& os,const bignum& a){if(a.sgn<0)os<<'-';write(a.num,os);return os;}
friend inline bignum sqrt(const bignum& a){bignum ret;bignum_t t;memcpy(t,a.num,sizeof(bignum_t));sqrt(ret.num,t);ret.sgn=ret.num[0]!=1||ret.num[1];return ret;}
friend inline bignum sqrt(const bignum& a,bignum& b){bignum ret;memcpy(b.num,a.num,sizeof(bignum_t));sqrt(ret.num,b.num);ret.sgn=ret.num[0]!=1||ret.num[1];b.sgn=b.num[0]!=1||ret.num[1];return ret;}
inline int length(){return ::length(num);}
inline int zeronum(){return ::zeronum(num);}
inline bignum C(const int m,const int n){combination(num,m,n);sgn=1;return *this;}
inline bignum P(const int m,const int n){permutation(num,m,n);sgn=1;return *this;}
};

typedef bignum BigNum;


int     N,  M,  K,  x,  y;

// 原有向图 
bool    G[101][101];

// 某个顶点所属的强分量，以及强分量总个数 
int     id[101],    scnt;

// 决定 DFS 是正向图搜索还是逆图搜索 
bool    rev;

// postI 是一个栈，记录了深搜弹出序 
vector<int> postI;

// 核心 DAG 图 
bool    DAG[101][101]; 

// 各个强分量包含的顶点个数
vector<int> allComponent;

// 核心 DAG 的出入度表 
int     dag_in[101],    dag_out[101]; 

// 作为核心 DAG 中源点或汇点的分量各自具有的顶点数
vector<int> U,  U_acc;

// 求组合的动态规划表
BigNum  DP[101][101]; 

// 求组合数 
BigNum comb( int n, int m ) {
    BigNum ret( 1 );
    m = m < ( n - m ) ? m : ( n - m );
    for( int i = n - m + 1; i <= n; ret *= (i++) );
    for( int i = 1; i <= m; ret /= (i++) );
    return  m < 0 ? 0 : ret;
}



// 计算逆图的深搜弹出序 ( rev == true )
// 或者正图的强分量     ( rev == false )
void DFS( int w ) {
    id[w] = scnt;
    if( rev ) {
        for( int i = 1; i <= N; ++i )
        if( G[i][w] && id[i] == -1 )
            DFS( i );
    }
    else {
        for( int i = 1; i <= N; ++i )
        if( G[w][i] && id[i] == -1 )
            DFS( i );
    }
    postI.push_back( w );
}




int main() {
    
    while( cin >> N >> M >> K ) {
    
        memset( G, 0, sizeof( G ) );
        
        for( int i = 0; i < M; ++i ) {
            cin >> x >> y;
            G[x][y] = true;
        }
        
        // Kosaraju 算法 
        memset( id, -1, sizeof( id ) );
        postI.clear();
        scnt = 0;   rev = true; 
        for( int i = 1; i <= N; ++i )
            if( id[i] == -1 )
                DFS( i );
        memset( id, -1, sizeof( id ) );
        scnt = 0;   rev = false; 
        for( int pos = N - 1; pos >= 0; --pos ) {
            if( id[postI[pos]] == -1 ) {
                DFS( postI[pos] );
                ++scnt;
            }
        }
        
        // 计算各个强分量具有的顶点数 
        allComponent.assign( scnt, 0 );
        for( int i = 1; i <= N; ++i )
             ++allComponent[id[i]]; 
        
        // 强分量计算完毕，构造核心 DAG
        memset( DAG, 0, sizeof( DAG ) );
        for( int i = 1; i <= N; ++i )
            for( int j = 1; j <= N; ++j )
                if( G[i][j] ) 
                    if( id[i] != id[j] )
                        DAG[id[i]][id[j]] = true;
        
        // 计算出入度表，以确定该分量是否为源点或汇点 
        memset( dag_in, 0, sizeof( dag_in ) );
        memset( dag_out, 0, sizeof( dag_out ) );
        for( int i = 0; i < scnt; ++i ) {
            for( int j = 0; j < scnt; ++j ) {
                if( DAG[i][j] ) {
                    ++dag_out[i];
                    ++dag_in[j]; 
                }
            }
        }
        
        // 计算出 U
        U.clear(); 
        for( int i = 0; i < scnt; ++i )
            if( dag_in[i] == 0 || dag_out[i] == 0 )
                U.push_back( allComponent[i] );
        
        // 计算 U 向量的全组合数
        sort( U.begin(), U.end() );
        U_acc = U;
        for( int i = 1; i < U.size(); ++i )
            U_acc[i] += U_acc[i-1];
        
        // 动态规划 
        for( int i = 0; i < 101; ++i )
            for( int j = 0; j < 101; ++j )
                DP[i][j] = 0;
        
        for( int j = 1; j <= U[0]; ++j )
            DP[0][j] = comb( U[0], j );
        for( int i = 1; i < U.size(); ++i ) {
            for( int j = i + 1; j <= U_acc[i]; ++j ) {
                for( int k = 1; j - k; ++k ) {
                    DP[i][j] += DP[i-1][j-k] * comb( U[i], k );
                }
            }
        }
        
        BigNum  ans = 0;
        for( int k = U.size(); k <= U_acc.back() && k <= K; ++k )
            ans += DP[U.size() - 1][k] * comb( N - U_acc.back(), K - k );
        
        
        cout << ans << endl << endl;
        
    }
    
}
