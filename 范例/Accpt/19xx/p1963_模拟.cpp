#include<stdio.h>
#include<string.h>
char str[9];
int main()
{
//	freopen("a.txt","r",stdin);
	int n,num;
	double x;
	scanf("%d%lf",&n,&x);
	while(scanf("%d",&num)!=EOF){
		int ok=1,hh,mm,ss;
		int time=0;
		for(int i=0;i<n;i++){
			scanf("%s",str);
			if(ok){
				if(!strcmp(str,"-:--:--")) ok=0;
				else{
					sscanf(str,"%d:%d:%d",&hh,&mm,&ss);
					time+=(hh*3600+mm*60+ss);
				}
			}
		}
		printf("%3d: ",num);
		if(ok){
			time=(int)(time/x+0.5);
			mm=time/60,ss=time%60;
			printf("%d:%02d min/km\n",mm,ss);
		}
		else puts("-");
	}
	return 0;
}
//1619461 2006-02-06 10:31:45 Accepted 1963 C++ 00:00.01 392K ZojMj 