#include<stdio.h>
#include<time.h>
#include<string.h>
#define maxn 128
#define maxm 128000
#define max(a,b) ((a)>(b)?(a):(b))
char image[maxn][maxn+1];
int sz,top;
bool flag;
int ans=0;
struct TNode{

	int up,left,down,right;	
	char color;
	int count;
	bool processed;

	TNode *uc,*lc,*dc,*rc;

	void Construct(int,int,int,int);
	void Compress();
	bool Find(TNode *);
	bool Judge(TNode *);

}Tree[maxm],*root=&Tree[0];

void TNode::Construct(int u,int l,int d,int r)
{
	up=u,left=l,down=d,right=r;
	processed=0;
	if(u==d&&l==r){
		uc=lc=dc=rc=NULL;
		color=(image[u][l]=='1');
		count=1;
		return;
	}
	int midH=(u+d)>>1,midW=(l+r)>>1;
	uc=&Tree[top++];	lc=&Tree[top++];
	dc=&Tree[top++];	rc=&Tree[top++];
	uc->Construct(u,l,midH,midW);		rc->Construct(u,midW+1,midH,r);
	lc->Construct(midH+1,l,d,midW);		dc->Construct(midH+1,midW+1,d,r);
	if(uc->color!=-1
		&&uc->color==lc->color
		&&dc->color==rc->color
		&&uc->color==dc->color)
	{
		color=uc->color;
		count=1;
		uc=lc=rc=dc=NULL;
		return;
	}
	color=-1;
	count=1+uc->count+lc->count+dc->count+rc->count;
}
bool TNode::Judge(TNode* other)
{
	if(color!=other->color||count!=other->count) return 0;
	if(count==1) return 1;

	return uc->Judge(other->uc)
		&&rc->Judge(other->rc)
		&&lc->Judge(other->lc)
		&&dc->Judge(other->dc);
}
bool TNode::Find(TNode* other)
{
	if(!processed) return 0;
	if(color!=-1) return 0;
	if(Judge(other)) return 1;
	return (uc->Find(other)
		||rc->Find(other)
		||lc->Find(other)
		||dc->Find(other));
}
void TNode::Compress()
{
	if(color!=-1){	ans++; processed=1; return;	}

	if(root->Find(this))
	{
		processed=1;
		return ;
	}
	ans++;
	processed=1;
	uc->Compress(); rc->Compress();
	lc->Compress(); dc->Compress();
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		memset(image,'0',sizeof(image));
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%s",image[i]);
			image[i][m]='0';
		}
		m=max(n,m);
		for(sz=1;sz<m;sz<<=1);
		top=1;
		root->Construct(0,0,sz-1,sz-1);
		printf("%d ",root->count);
		ans=0;
		root->Compress();
		printf("%d\n",ans);
	} 
	return 0;
}
//1654013 2006-02-28 20:23:54 Accepted 1805 C++ 00:00.92 5956K OneYearOld 
/*
size不一样也可能压缩! 
比如
       o
oo  oo  oo  oo
oo  oo  oo  oo
跟
       o
o   o	 o   o
算一样的！..  
*/
