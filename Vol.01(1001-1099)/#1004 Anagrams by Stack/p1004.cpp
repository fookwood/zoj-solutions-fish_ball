// PERFORMER: ELF
// DATE: Dec. 9th, 2007
// TITLE: Anagrams by Stack

#include <iostream>
#include <string>
#define MAXLEN 200 
using namespace std;

class Stack
{ public:
    Stack(){}
    void init();                // 标准输入输出流输入两行字符 
    void recvr();               // 恢复出栈入栈对数据造成的影响 
    bool push();                // 源串入栈一个字符 
    bool pop();                 // 目标串弹出一个字符 
    bool proc(char*);           // 接受操作字符串类似于"io"作出操作 
    bool check();               // 检查目标串与要求的字符串是否符合 
    void display();
  private:
    char a[MAXLEN];
    char at[MAXLEN], *p1;
    char b[MAXLEN];
    char bt[MAXLEN], *p2;
    char s[MAXLEN], *top;
    int count;
};

int main()
{ Stack word[10];
  int i=0; 
  while(1) 
  { word[i].init(); i++;
   if(cin.eof()) break; 
  }
  for(int j=0;j<=i-2;j++) word[j].display();
   return 0;
}

void Stack::init()
{ cin>>a; strcpy(at,a);
  cin>>b; strcpy(bt,"");
  count=(strlen(a)==strlen(b))?strlen(a):0;
  p1=at; p2=bt;
  *s='\0', top=s;
}
void Stack::recvr()
{ strcpy(at,a); strcpy(bt,"");
  p1=at; p2=bt; *s='\0', top=s;
}
bool Stack::push()
{ if(!(*p1)) return 0;
  *(top++)=*(p1++);
  *top='\0';
  return 1;
}
bool Stack::pop()
{ if(top==s) return 0;
  *(p2++)=*(--top);
  *top=*p2='\0';
  return 1;
}
bool Stack::proc(char* t)
{ for(char *tp=t;*tp;tp++)
  { if(*tp=='i') if(!push()) return 0;
    if(*tp=='o') if(!pop()) return 0;
  }
  return 1;
}
bool Stack::check()
{ return !strcmp(b,bt);} 
void Stack::display()
{ cout<<"["<<endl;
  int i=count,o=count,k; 
  char io[MAXLEN*2]="";
  bool mark[MAXLEN*2]={}; 
  while(1)
  { // 搜索一个io 
    while(o>0)
    { if(i==o) { mark[2*count-i-o]=0; io[2*count-(i--)-o]='i'; } 
      else if(i==0) { mark[2*count-i-o]=0; io[2*count-i-(o--)]='o'; }
      else if(o>i&&mark[2*count-i-o]) 
      { mark[2*count-i-o]=0; io[2*count-i-(o--)]='o'; }
      else if(o>i&&!mark[2*count-i-o]) 
      { mark[2*count-i-o]=1; io[2*count-(i--)-o]='i'; }  
    }
    // 输出一行io 
    recvr(); 
    proc(io);
    if(check())
    { for(k=0;k<2*count;k++) cout<<io[k]<<" "; cout<<endl; }
    // 检查是否结束并弹回 
    bool end=1; 
    for(k=2*count-1;k>=0;k--) 
    { if(mark[k]==1) { end=0; break; } 
      else { if(io[k]=='i') i++; else o++; }
    }
    if(io[k]=='i') i++; else o++;
    if(end) break;  
  } 
  cout<<"]"<<endl;
}
