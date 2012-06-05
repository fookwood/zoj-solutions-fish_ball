const int fprec = 100; // floating-point precision

HP zero=0;

class FS{public:
    FS();  void SetZero(); 
    FS(int inte) { (*this)=inte; }
    FS(char *s)  { (*this)=s;    }
    FS operator=(char *s); FS operator=(int inte);
    FS operator+(FS b); FS operator-(FS b);
    FS operator*(FS b); FS operator/(FS b);
    friend ostream& operator<<(ostream &cout, FS x);    
    int sign,prec;
    HP num;
};

void FS::SetZero(){ sign=1; num=0; prec=0; }

FS::FS() { SetZero(); }

ostream& operator<<(ostream &cout,FS x)
{
    if(x.sign<0) cout<<"-";
    int i,k,low=1;
    for(i=x.num.len; i>x.prec; i--) cout<<x.num.s[i];
    if( x.num.len<=x.prec) cout<<"0";
    if( x.num.Compare(zero)==0 ) { cout<<".0"; return cout; }
    k=i;
    while( k>0 && x.num.s[k]==0 ) k--;
    if(k==0) { cout<<".0"; return cout; }
    cout<<".";
    if( x.num.len<x.prec ) for(int j=0;j<x.prec-x.num.len;j++) cout<<"0";
    while(x.num.s[low]==0) low++;
    while(i>=low ) cout<<x.num.s[i--];
    return cout;
}

FS FS::operator=(int inte)
{
    prec = 0;
    if( inte>=0 ) { sign =  1; num =  inte; } 
        else      { sign = -1; num = -inte; }
    return (*this);
}

FS FS::operator=(char *s)
{
    int p,i,j,l;
    SetZero();
    if( s[0]=='-' ) { sign = -1; s++; };
    if( s[0]=='+' ) { sign =  1; s++; };
    l = strlen(s);
    for(p=0; p<l; p++) if( s[p]=='.' ) break;
    if( p==l ) prec = 0; else prec = l-1-p;
    for(i=l-1,j=0; i>=0; i--) if( s[i]!='.' ) num.s[++j] = s[i]-'0';        
    while(j>1 && num.s[j]==0) --j;  num.len = j;
    return (*this);
}

void LShift(FS &a,int sl)
{
    a.prec+=sl; a.num.len+=sl; int i;   
    for(i=a.num.len; i>sl; i--) a.num.s[i]=a.num.s[i-sl];
    while(i>0) a.num.s[i--]=0;
}

void RShift(FS &a,int sl)
{
    a.prec-=sl; a.num.len-=sl; int i;
    for(i=1; i<=a.num.len; i++) a.num.s[i]=a.num.s[i+sl];
}

FS FS::operator+(FS b)
{
    FS c;
    if( prec>b.prec ) LShift(b,prec-b.prec); else
    if( prec<b.prec ) LShift((*this),b.prec-prec);
    if( sign==b.sign) {
        c.sign=sign; c.prec=prec; c.num=num+b.num;
        if( c.num.Compare(zero)==0 ) c.SetZero();
    } else  {
        c.prec=prec;
        if( num.Compare(b.num)==0) c.SetZero(); else
        if( num.Compare(b.num)>0 ) { c.sign=sign; c.num=num-b.num; } else
        if( num.Compare(b.num)<0 ) { c.sign=b.sign; c.num=b.num-num; }
        if( c.num.Compare(zero)==0 ) c.SetZero();
    }
    if( c.prec > fprec ) RShift( c, c.prec - fprec );
    return c;
}

FS FS::operator-(FS b)
{
    b.sign = - b.sign;  
    FS c = (*this) + b;
    b.sign = - b.sign;
    return c;
}

FS FS::operator*(FS b)
{
    FS c; 
    c.sign = sign * b.sign ; 
    c.prec = prec + b.prec ;
    c.num  = num  * b.num  ;
    if( c.num.Compare(zero)==0 ) c.SetZero();
    if( c.prec > fprec ) RShift( c, c.prec - fprec );
    return c;
}

FS FS::operator/(FS b)  // 355/133 = 3.1415929203539823008849557522124
{
    FS c,d;  // c = d / b
    d = (*this); LShift(d, fprec);
    c.sign = d.sign * b.sign ;
    c.prec = d.prec;
    LShift(d , b.prec);
    c.num =  d.num / b.num;
    if( c.prec > fprec ) RShift( c, c.prec - fprec );
    return c;
}


#include <iostream>
using namespace std;

const double PI = acos(-1.0);

int main() {
    FS H, R;
    while(cin >> H >> R && H) {
        FS D = sqrt(3.0) * H / 2.0;
        if(R > H) {
            cout << FS(1.0) << endl;
        }
        else if(R < D) {
            cout << PI * R * R / 3.0 / D * H << endl;
        }
        else {
            
        }
    }
}
