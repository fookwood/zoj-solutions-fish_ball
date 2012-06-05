# include <iostream.h> 
# include <string.h> 
# include <stdlib.h> 
char map[9][9]; 
int n,m,t,di,dj; 
bool escape; 
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}}; 
 
void dfs(int si,int sj,int cnt) 
{ 
   int i,temp; 
   if(si>n||sj>m||si<=0||sj<=0) 
          return; 
   if(cnt==t&&si==di&&sj==dj)
          escape=1;
   if(escape)
          return; 
   temp=(t-cnt)-abs(si-di)-abs(sj-dj); 
   if(temp<0||temp&1)
          return; 
   for(i=0;i<4;i++){ 
      if(map[si+dir[i][0]][sj+dir[i][1]]!='X')
        { 
         map[si+dir[i][0]][sj+dir[i][1]]='X'; 
         dfs(si+dir[i][0],sj+dir[i][1],cnt+1); 
         map[si+dir[i][0]][sj+dir[i][1]]='.'; 
      } 
   } 
   return; 
} 
int main() 
{ 
       int i,j,si,sj; 
       while(cin>>n>>m>>t)
       { 
        if(n==0&&m==0&&t==0) 
               break; 
        int wall=0;
        for(i=1;i<=n;i++) 
         for(j=1;j<=m;j++)
               { 
            cin>>map[i][j]; 
            if(map[i][j]=='S') { si=i; sj=j; } 
            else if(map[i][j]=='D') { di=i; dj=j; } 
            else if(map[i][j]=='X') wall++; 
         } 
       if(n*m-wall<=t)
          {
                 cout<<"NO"<<endl;
                 continue;
          }
          escape=0; 
       map[si][sj]='X';
       dfs(si,sj,0); 
       if(escape) cout<<"YES"<<endl; 
       else cout<<"NO"<<endl; 
   } 
   return 0; 
}
