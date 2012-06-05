// PERFORMER: ELF
// DATE: Dec. 19th, 2007
// TITLE: Jugs
#include <iostream>
using namespace std;

struct Jugs
{ Jugs(int a=0,int b=0):prew(0){}
  friend bool equal(Jugs x,Jugs y);
  void get(int &i,int &j){i=a;j=b;}
  Jugs* prew; // The preview Jugs
  int oper;   // The operator the Jug come from
  int a,b;
};
// Next proccesing
void proc(int a,int b,int &A,int &B,int index)
{ int remain;
  switch(index)
  { case 0: A=0; return;                      // Empty A
    case 1: B=0; return;	                  // Empty B
	case 2: A=a; return;                      // Fill A
	case 3: B=b; return;                      // Fill B
	case 4: remain=(A>b-B)?b-B:A;             // Pour A,B
    A=A-remain;B=B+remain;return;
	case 5: remain=(B>a-A)?a-A:B;             // Pour B,A
    A=A+remain;B=B-remain;return;
  }
}
// Display of result
void output(int index)
{ switch(index)
  { case 0: cout<<"empty A"<<endl; break;
    case 1: cout<<"empty B"<<endl; break;
	case 2: cout<<"fill A"<<endl; break;
	case 3: cout<<"fill B"<<endl; break;
	case 4: cout<<"pour A B"<<endl; break;
	case 5: cout<<"pour B A"<<endl; break;
  }
}

int main()
{ int a,b,c;
  int i,j,k,m,n,p,q;
  int status[200][200];
  Jugs node[200][200];
  while(cin>>a>>b>>c)
  { // Initialization
    for(j=0;j<=a;j++)
    for(k=0;k<=b;k++)
    { status[j][k]=1;
      node[j][k]=Jugs(a,b);
    }
    // Processing
    j=0;k=0;
    status[j][k]=2;

    while(status[0][c]!=2&&status[a][c]!=2)
    { for(j=0;j<=a;j++)
      for(k=0;k<=b;k++)
      if(status[j][k]==2)
      status[j][k]=3;
      for(j=0;j<=a;j++)
      for(k=0;k<=b;k++)
      if(status[j][k]==3)
      { status[j][k]=0;                    // Next
        for(i=0;i<6;i++)
        { m=j;n=k;
          proc(a,b,m,n,i);
          if(status[m][n]==1)
          { status[m][n]=2;
            node[m][n].prew=&(node[j][k]);
            node[m][n].oper=i;
          }
        }
      }
    }
    for(j=0;j<=a;j+=a)
    if(status[j][c]==2)                   // Reached
    { int l=0,r[100];
      m=j;n=c;
      Jugs *u=&(node[j][c]);
      while(u->prew)
      { r[l++]=u->oper;
        u=u->prew;
        u->get(m,n);
      }
      for(l--;l>=0;l--)
      { output(r[l]); }
      cout<<"success"<<endl;
      break;
    }
  }
  return 0;
}
