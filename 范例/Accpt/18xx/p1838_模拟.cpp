#include<stdio.h>
#include<string.h>
#define maxn 101
const char key[]="the quick brown fox jumps over the lazy dog";
char pass[256];
char str[maxn][82];
int main()
{
	bool first=0;
	while(gets(str[0])){
		if(first) putchar(10); first=1;
		int cnt=0;
		bool won=0;
		do{
			if(!won&&strlen(str[cnt])==43){
				memset(pass,0,sizeof(pass));
				int p=0;
				while(p<43){
					if(pass[str[cnt][p]]!=0&&pass[str[cnt][p]]!=key[p]) break;
					pass[str[cnt][p]]=key[p];
					p++;
				}
				if(p==43) {
					char ch,px;
					for(ch='a';ch<'z';ch++)
						for(px=ch+1;px<='z';px++)if(pass[px]==pass[ch]||!pass[ch]||pass[ch]==' ') goto ex;
ex:;
					if(ch=='z'&&pass[ch]&&pass[ch]!=' ') won=1;
				}
			}
			cnt++;
		}while(gets(str[cnt])&&str[cnt][0]);
		if(won)
			for(int i=0;i<cnt;i++){
				for(int j=0;str[i][j];j++)
					putchar(pass[str[i][j]]);
				putchar(10);
			}
		else puts("No solution.");
	}
	return 0;
}
//1638577 2006-02-18 21:08:26 Accepted 1838 C++ 00:00.01 400K OneYearOld 
