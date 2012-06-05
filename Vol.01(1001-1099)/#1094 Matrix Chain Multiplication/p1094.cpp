// PERFORMER: ELF
// DATE: Dec. 9th, 2007
// TITLE: Matrix Chain Multiplication
// 2827458 2008-04-06 17:27:37 Accepted 1094 C++ 00:00.00 840K 呆滞的慢板 

#include <iostream>
#include <string> 
#define MAXLINE 100 
#define BUFSIZE 26 
using namespace std; 
class Matrix
{ public:
    Matrix(){};
    Matrix(char a,long m,long n):name(a),x(m),y(n){mul=0;}
    void input();
    friend Matrix operator * (Matrix,Matrix);
    friend Matrix* select(char,Matrix*,int,Matrix*,int);
    char getName(){return name;}
    void setName(char c){name=c;} 
    void display();
  private:
    char name;
    long mul;
    long x;
    long y;
};
// 通过字符在矩阵类数组中选中名字对应的矩阵
Matrix* select(char c,Matrix* set,int num,Matrix* temp,int index)
{ if(isupper(c)) 
  for(int i=0;i<num;i++)
  if(set[i].name==c) return set+i;
  for(int i=0;i<index;i++)
  if(temp[i].name==c) return temp+i;
  return 0;
}
// 实现矩阵相乘，mul为累加运算次数，取-1时为error 
Matrix operator * (Matrix a,Matrix b)
{ Matrix c(a.name,a.x,b.y);
  c.mul=a.mul+b.mul+a.x*b.x*b.y;
  if(a.y!=b.x||a.mul==-1||b.mul==-1) c.mul=-1;
  return c; 
}
// 从标准流输入矩阵
void Matrix::input()
{ cin>>name>>x>>y;
  mul=0;
} 
// 显示矩阵的累计运算次数 
void Matrix::display()
{ if(mul==-1) cout<<"error"<<endl;
  else cout<<mul<<endl;
}
// 显示字符串式子第一个字符的值 
void show(string str,Matrix *set,int num,Matrix *temp,int index)
{ for(int i=0;i<str.length();i++)
  if(isalpha(str[i]))
  select(str[i],set,num,temp,index)->display(); 
} 
// 执行字符串表达式 
bool exec(string &str, Matrix *set, int num, Matrix *temp, int &index)
{ Matrix *p,*q;
  for(int i=0;i<str.length()-1;i++)
  { if(isalpha(str[i+1])&&isalpha(str[i]))
    { p=select(str[i+1],set,num,temp,index);
      q=select(str[i],set,num,temp,index);
    }
    if(isupper(str[i+1])&&isupper(str[i])) 
    { temp[index]=(*q)*(*p);
      temp[index].setName('a'+index);
      str[i]=('a'+index); str.erase(i+1,1);
      index++; return 1; 
    }
    if(isupper(str[i+1])&&islower(str[i])) 
    { *q=(*q)*(*p);
      str.erase(i+1,1); return 1;
    }
    if(isalpha(str[i])&&islower(str[i+1]))
    { char t=p->getName();
      *p=(*q)*(*p); p->setName(t);
      str.erase(i,1); return 1;    
    }
    if(str[i+1]==')')              // 后括号消除 
    { str.erase(i+1,1);
      for(;i>=0;i--) if(str[i]=='(')
      { str.erase(i,1); return 1; }
    }
  }
  return 0; 
}


int main()
{ Matrix set[26],temp[BUFSIZE];
  string str[MAXLINE],*s=str; 
  int num,i;
  int index=0;
  cin>>num;
  for(i=0;i<num;i++) set[i].input();
  int line=0; 
  while(1)
  { cin>>*(s++);
    if(cin.eof()) break; 
    line++; 
  }
  for(i=0;i<line;i++)
  { index=0;         // 缓冲区标号 
    while(exec(str[i],set,num,temp,index));
    show(str[i],set,num,temp,index);
  }
  return 0;
}


