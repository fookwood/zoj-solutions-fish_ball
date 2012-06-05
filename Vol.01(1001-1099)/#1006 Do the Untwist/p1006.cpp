// PERFORMER: ELF
// DATE: Dec. 11th, 2007
// TITLE: Do the Untwist
#include <iostream>
#include <cmath>
#define MAXLINE 100
#define MAXLEN 300
using namespace std;
int mod(int a,int b)
{ return (a<0)?a%b+b:a%b; 
}
class cryptCode
{ public:
    cryptCode(){};
    bool inputc()
    { cin>>key; if(key==0) return 0;
      cin>>cipherText;len=cipherText.size(); return 1;
    }
    bool inputp()
    { cin>>key; if(key==0) return 0;
      cin>>plainText;len=plainText.size(); return 1;
    }
    void outputc(){cout<<cipherText;}
    void outputp(){cout<<plainText;}
    void plain2cipher();
    void cipher2plain();
  private:
    static string code;
    string plainText;
    string cipherText;
    int len;
    int key;
};
void cryptCode::cipher2plain()
{ int i,plainCode[MAXLEN],cipherCode[MAXLEN];
  for(i=0;i<len;i++)
  for(int j=0;j<28;j++)
  { if(cipherText[i]==code[j])
    { cipherCode[i]=mod(j+i,28); break; }
  }
  for(i=0;i<len;i++)
  plainCode[mod(key*i,len)]=cipherCode[i];
  for(i=0;i<len;i++)
  plainText+=code[plainCode[i]];
}
void cryptCode::plain2cipher()
{ int i,plainCode[MAXLEN],cipherCode[MAXLEN];
  for(i=0;i<len;i++)
  for(int j=0;j<28;j++)
  { if(plainText[i]==code[j])
    { plainCode[i]=j; break; }
  }
  for(i=0;i<len;i++)
  { cipherCode[i]=mod(plainCode[mod((key*i),len)]-i,28);
  }
  for(i=0;i<len;i++)
  cipherText+=code[cipherCode[i]];
}
string cryptCode::code="_abcdefghijklmnopqrstuvwxyz.";
int main()
{ cryptCode cc[MAXLINE];
  int line=0,i;
  while(cc[line].inputc())
  cc[line++].cipher2plain();
  for(i=0;i<line;i++)
  { cc[i].outputp(); cout<<endl; }
  cc[i].outputp();
  return 0;
}
