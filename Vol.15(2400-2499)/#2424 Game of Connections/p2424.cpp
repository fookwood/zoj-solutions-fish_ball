// 2887313 2008-05-03 19:36:25 Accepted 2424 C++ 00:00.13 940K 呆滞的慢板

// 递推式不难，就是数值范围变态了一点，大部分的篇幅都放在大整数上了 
// 递推式是这样的，假设 n 的情况有 DP[n] 种，DP[0] = DP[1] = 1 
// 那么，对于每个 DP[n]，选取任意一个点作为划分
// 然后，他要选取另一个点连线，这些点只能是偶数编号的
//      (使得划分的两边都有偶数个点)
// 然后这种前提下的情况应该是划分两边点数的 DP[] 值之积 (乘法原理)
// 然后将这些情况都累加(加法原理)，即可得到递推公式，DP即可。 

#include <deque>
#include <iostream>
#include <iomanip>
using namespace std;

class BigNum {

    deque<int>  V;

public:
    
    BigNum() : V( 1, 0 ) {}
    
    BigNum( const BigNum& num ) : V( num.V ) {}
    
    BigNum( int val ) : V( 0 ) {
        while( val > 10000 ) {
            V.push_back( val % 10000 );
            val /= 10000;
        }
        V.push_back( val );
    }
    
    friend BigNum& operator += ( BigNum& num1, BigNum num2 );
    
    friend BigNum  operator << ( BigNum& num, int n );
    
    friend BigNum& operator *= ( BigNum& num, const int& k );
    
    friend BigNum  operator *  ( BigNum& num1, BigNum num2 );
    
    friend ostream& operator << ( ostream& os, BigNum num );

};

// 相加自增量运算符 
BigNum& operator += ( BigNum& num1, BigNum num2 ) {
    
    if( num1.V.size() > num2.V.size() )
        num2.V.resize( num1.V.size() );
    else
        num1.V.resize( num2.V.size() );

    int carry = 0;
    
    for( int i = 0; i < num1.V.size(); ++i ) {
        num1.V[i] += ( num2.V[i] + carry );
        carry = num1.V[i] / 10000;
        num1.V[i] %= 10000;
    }

    if( carry ) num1.V.push_back( 1 );

}

// 重载左移运算符 
BigNum operator << ( BigNum& num, int n ) {

    BigNum  ans( num );
    while( n-- > 0 )
        ans.V.push_front( 0 );
    return  ans;

}

// 数乘自赋值运算符 
BigNum& operator *= ( BigNum& num, const int& k ) {

    int carry = 0;
    for( int i = 0; i < num.V.size(); ++i ) {
        num.V[i] *= k;
        num.V[i] += carry;
        carry = num.V[i] / 10000;
        num.V[i] %= 10000; 
    }
    if( carry ) num.V.push_back( carry );

}

// 相乘运算符 
BigNum operator * ( BigNum& num1, BigNum num2 ) {

    BigNum  temp,   ans;

    for( int i = 0; i < num1.V.size(); ++i ) {
        temp = num2 << i;
        temp *= num1.V[i];
        ans += temp;
    }
    
    return  ans;

}

// 重载流插入运算符 
ostream& operator << ( ostream& os, BigNum num ) {
    
    os << num.V.back();
    
    for( int i = num.V.size() - 2; i >= 0; --i )
        os << setw( 4 ) << setfill( '0' ) << num.V[i];
    
    return  os;
    
}

int main() {
    
    BigNum  DP[101];
    int     N;
    
    DP[0] = 1;
    DP[1] = 1;
    
    for( int i = 2; i < 101; ++i ) {

        DP[i] = 0;

        for( int j = 0; j < i; ++j )
            DP[i] += DP[j] * DP[i - j - 1]; 

    }

    while( ( cin >> N ) && N != -1 )
        cout << DP[N] << endl;

}
