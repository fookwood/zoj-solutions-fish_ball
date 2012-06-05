// PERFORMER: ELF
// DATE: Dec. 9th, 2007
// TITLE: Fire Net

#include <iostream>
using namespace std;

bool isValid(int b[4][4], int num, int i, int j)
{ int k;
  for(k=i;k>=0;k--) { if(b[k][j]==2) return 0; if(b[k][j]==1) break;}
  for(k=i;k<num;k++){ if(b[k][j]==2) return 0; if(b[k][j]==1) break;}
  for(k=j;k>=0;k--) { if(b[i][k]==2) return 0; if(b[i][k]==1) break;}
  for(k=j;k<num;k++){ if(b[i][k]==2) return 0; if(b[i][k]==1) break;}
  return 1;   
}

int weight(int b[4][4], int num, int i, int j)
{ int m, w=0;
  m=i+1; while(b[m][j]!=1&&m!=num) { m++, w--; }
  m=i-1; while(b[m][j]!=1&&m!=-1) { m--, w--; }
  m=j+1; while(b[i][m]!=1&&m!=num) { m++, w--; }
  m=j-1; while(b[i][m]!=1&&m!=-1) { m--, w--; }
  return w;
}

int main()
{ int num, i, j, k;
  int b[4][4];
  char a[4][5];
  int count[500]={}, cnt=0;
  while(cin>>num)
  { if(num==0) break;
    // Input Procedure!
    for(i=0;i<num;i++) cin>>*(a+i);
    // Change with numbers!
    for(i=0;i<num;i++)
    for(j=0;j<num;j++)
      b[i][j]=(a[i][j]!='.');
    // Weight value Calculate!
    int c[4][4]={};
    for(i=0;i<num;i++)
    for(j=0;j<num;j++)
    if(!b[i][j])
    for(k=0;k<num;k++)
    { b[i][j]=weight(b,num,i,j); }
    // Fill with blockhouses!
    for(k=0;k>=-2*(num);k--)
    for(i=0;i<num;i++)
    for(j=0;j<num;j++)
    if(b[i][j]==k&&isValid(b,num,i,j))
    b[i][j]=2;
    // Calculate the count of the blockhouses!
    for(i=0;i<num;i++)
    for(j=0;j<num;j++)
    if(b[i][j]==2)
    count[cnt]++;
    cnt++;
    // Display!
    #define DISPLAY
    #ifndef DISPLAY
    for(i=0;i<num;i++)
    { for(j=0;j<num;j++)
      { cout<<b[i][j]<<'\t'; }
      cout<<endl;
    }
    #endif
  }
  // Output! 
  for(i=0;i<cnt;i++) cout<<count[i]<<endl;
  return 0;
}


