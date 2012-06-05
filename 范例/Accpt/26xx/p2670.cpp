#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,k=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(i==j){
					if(i!=n-1) printf("0");
					else printf("100");
				}
				else printf("1");
				if(j==n-1) printf("\n");
				else putchar(' ');
			}
		puts("");
	}
	return 0;
}
//1675409 2006-03-11 23:28:49 Accepted 2670 C++ 00:00.00 388K OneYearOld 