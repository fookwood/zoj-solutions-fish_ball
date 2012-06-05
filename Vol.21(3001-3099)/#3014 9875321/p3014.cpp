// 3058550 2008-09-03 19:00:52 Accepted 3014 C++ 00:00.00 392K 呆滞的慢板 

// 暴搜打表，本机运行之后获得的文件提交 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string code = "0123456789ABCDEF";
int val[128] = {};

typedef long long i64;

bool isPrime(i64 n, int s = 10) {
    if(n == 2) return true;
    if(n <= 1 || n % 2==0) return false;
    for( i64 i = 3; i * i <= n; i += 2 )
        if(n % i == 0)
            return false;
    return  true;
}

i64 toNum( string s, int base ) {
    i64 ans = 0;
    for( int i = 0; i < s.size(); ++i ) {
        ans *= base;
        ans += val[s[i]];
    }
    return  ans;
}

bool special( string s, int base ) {
    if( !isPrime( toNum( s, base ) ) )  return false;
    reverse( s.begin(), s.end() );
    if( !isPrime( toNum( s, base ) ) )  return false;
    return  true;
}

string  str, mx;
void DFS( int base, int v ) {
    if( special( str, base ) &&
        toNum( str, base ) > toNum( mx, base ) )
        mx = str;
    if( v <= 0 ) return;
    str += code[v];
    DFS( base, v - 1 );
    str.erase( str.size() - 1 );
    DFS( base, v - 1 );
}

int main() {
    
    freopen( "access.cpp", "w", stdout );

    for( int i = 0; i < 10; ++i ) val['0'+i] = i;
    for( int i = 0; i < 6; ++i )  val['A'+i] = 10 + i;
    
    puts( "#include <cstdio>\n" );
    
    puts( "int x;\n" );
    
    puts( "char* a[] = {" );
    
    for( int base = 0; base <= 16; ++base ) {
        str = mx = "";
        DFS( base, base - 1 );
        if( mx != "" )
                printf( "    \"%s\"%c\n",
                    mx.c_str(), base == 16 ? ' ' : ',' );
        else    puts( "    \"not special\"," );
    }
    
    puts( "};\n" );
    
    puts( "int main() {" );
    puts( "    while(scanf(\"%d\", &x) != EOF)" );
    puts( "        puts(a[x]);" );
    puts( "}" );
    
}
