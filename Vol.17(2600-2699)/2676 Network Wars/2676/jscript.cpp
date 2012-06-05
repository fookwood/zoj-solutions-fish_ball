#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

FILE *inf;	/* judge's input file */
FILE *ans;	/* judge's output file */
FILE *ouf;	/* user's output file */

#define maxs 128
#define maxn 101
#define maxm 401

int n, m, i, j;
long ja, jc, pa, pc;	//should be long long
int a[maxm], b[maxm], c[maxm];
bool u[maxm];
bool g[maxn][maxn];
bool vis[maxn];
int path[410];
void quit(char* prompt) 
{
	printf("%s\n",prompt);
	fclose(inf);
	fclose(ans);
	fclose(ouf);
	exit(-1);
}

bool dfs(int x, int dep)
{
	int ii;

    if ( x == n ) {
    	for (int i = 0; i < dep; ++i) {
    		cout << path[i] << " ";    		
    	}
    	cout << endl;    	
    	return true;
    }
    
	vis[x] = true;

    for ( ii = 1; ii<= n; ++ii )
        if (!vis[ii] && g[x][ii]) {
        	path[dep] = ii;
        	vis[ii] = true;
            if ( dfs(ii, dep + 1) )
                return true;
        }

	return false;
}

int main(int argc, char *argv[])
{
	int ii,jj;
	
	inf = fopen("input", "r");
	ans = fopen("output", "r");
	ouf = fopen(argv[1], "r");
	int now = 0;
	while ( fscanf(inf,"%d",&n) != EOF ) {
		for ( ii=0; ii<maxm; ++ii ) {
			a[ii] = b[ii] = c[ii] = 0;
			u[ii] = false;
		}
		for ( ii=0; ii<maxn; ++ii ) {
			vis[ii] = false;
			for ( jj=0; jj<maxn; ++jj) {
				g[ii][jj] = false;
			}
		}	
		//cout << "case : " << ++now << endl;
		fscanf(inf,"%d",&m);
		for ( i = 1; i<= m; ++i ) {
			fscanf(inf,"%d",&a[i]);
			fscanf(inf,"%d",&b[i]);
			fscanf(inf,"%d",&c[i]);
			u[i] = false;

			//assert(not g[a[i]][b[i]]);

			g[a[i]][b[i]] = true;
			g[b[i]][a[i]] = true;
		}
	
		fscanf(ans,"%d",&ja);
		jc = 0;
		for ( i = 1; i<= ja; ++i ) {
			fscanf(ans,"%d",&j);
			jc = jc + c[j];
		}
	
		fscanf(ouf,"%d",&pa);	//pa := ouf.readlongint;
		if ( (pa < 1) || (pa > m) ) {
			char s[128];
			sprintf(s,"invalid number of wires bought: %d of %d", pa, m);
			quit(s);
		}
	
		pc = 0;
		for ( i = 1; i<=pa; ++i ) {
			fscanf(ouf,"%d",&j);	//j := ouf.readlongint;
			if ( (j < 1) || (j > m)) {
				char s[128];
				sprintf(s,"invalid wire bought: %d of %d", j, m);
				quit(s);
			}
			if (u[j]) {
				char s[128];
				sprintf(s,"wire bought twice: %d", j);
				quit(s);
			}
			u[j] = true;
			g[a[j]][b[j]] = false;
			g[b[j]][a[j]] = false;
			//cout << a[j] << " " << b[j] << endl;
			pc = pc + c[j];
		}
		//cout << pa << endl;
		for (int i = 1; i <= n; ++i) vis[i] = false;	
		if (dfs(1, 0)) 
			quit("there is path from outer world to president");

		if (pc * ja > jc * pa) {
			printf("expected: %.6f, found: %.6f', [jc %d/ ja %d, pc %d/ pa %d])\n", 1.0*jc/ja, 1.*pc/pa, jc, ja, pc, pa);
			quit("'expected: %.6f, found: %.6f', [jc / ja, pc / pa])");
		}
		if (pc * ja < jc * pa)
			quit("_fail, format('expected: %.6f, found: %.6f', [jc / ja, pc / pa])");
		//printf("%d/%d\n", pc, pa);
	}
	printf("Accepted!\n");
	return 0;
}
