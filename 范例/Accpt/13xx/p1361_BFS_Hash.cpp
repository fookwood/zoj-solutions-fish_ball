// zj1361.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
bool map[20][20];
const int dr[4]={0,-1,0,1};
const int dc[4]={-1,0,1,0};
struct State{
    char headr;
	char headc;
	char body[7];
	char step;
}queue[500000],temp;
bool reach[20][20][1<<14];
int n,m,l;
int hash(State a){
    int key,i;
	key=0;
	for(i=0;i<l-1;i++)
		key=key*4+a.body[i];
	return key;
}
int bfs(){
    int head,tail,i,j,key,r,c,r1,c1;
	if(temp.headr==0&&temp.headc==0)
		return 0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			memset(reach[i][j],0,1<<(2*l-2));
	key=hash(temp);
	reach[temp.headc][temp.headc][key]=1;
	queue[0]=temp;
	for(head=0,tail=1;head!=tail;head++){
	    temp=queue[head];
        for(i=0;i<4;i++){
			r=temp.headr+dr[i];
			c=temp.headc+dc[i];
			if(r==0&&c==0)
				return temp.step+1;
			if(r<0||r>=n||c<0||c>=m||map[r][c])
				continue;
		    r1=temp.headr;
			c1=temp.headc;
			for(j=0;j<l-1;j++){
			    r1=r1+dr[temp.body[j]];
				c1=c1+dc[temp.body[j]];
				if(r==r1&&c==c1)
					break;
			}
            if(j<l-1)
				continue;
            queue[tail].headr=r;
			queue[tail].headc=c;
			queue[tail].body[0]=(i+2)%4;
			for(j=1;j<l-1;j++)
				queue[tail].body[j]=temp.body[j-1];
            key=hash(queue[tail]);
			if(reach[r][c][key])
				continue;
			reach[r][c][key]=1;
			queue[tail].step=temp.step+1;
			tail++;
		}
	}
	return -1;
}
int main(int argc, char* argv[])
{
	int i,j,k,r,c,r1,c1,cs;
	cs=0;
    while(scanf("%d%d%d",&n,&m,&l),n){
		scanf("%d%d",&temp.headr,&temp.headc);
		r1=temp.headr;
		c1=temp.headc;
		for(i=0;i<l-1;i++){
			scanf("%d%d",&r,&c);
		    for(j=0;j<4;j++)
				if(r1+dr[j]==r&&c1+dc[j]==c){
					temp.body[i]=j;
					break;
				}
            r1=r;
			c1=c;
		}
		temp.headr--;
		temp.headc--;
		temp.step=0;
		memset(map,0,sizeof(map));
        scanf("%d",&k);
        for(i=0;i<k;i++){
			scanf("%d%d",&r,&c);
		    map[r-1][c-1]=1;
		}
	    printf("Case %d: %d\n",++cs,bfs());
	}
	return 0;
}