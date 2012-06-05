// 2953594 2008-06-20 23:02:30 Accepted 2240 C++ 00:00.01 848K 呆滞的慢板 

// 无聊菜题，纯粹英语阅读...

/* Quote 翻译 From Jesse

问题描述：
    
    给一串字符串，要求输出它压缩后的表达形式。压缩规则如下：

    1.  如果有2-9个相同的连续字符，则被编写成2个字符形式，
        第一个是连续字符的个数。第二个是该字符本身。
    
    2.  如果有9个以上相同的连续字符，则前9个被当作一个字符串来压缩，
        余下的按一个字符串来压缩。

    3.  如果不是相同的连续字符，则在他们的前面和后面分别输出1，
        中间为他们字符串本身。
        
    4.  如果出现字符1，则输出两个 1，即 11。

    *.  注意第四条只适用于非连续的时候，连续的时候不用变成 11
        测试过之后才搞清楚的，题目说的不清楚 

*/ 

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string  input;
    
    while( getline( cin, input ) ) {
    
        while( input.size() ) {
                        
            int i = 1;
            for( ; i < input.size(); ++i )
                if( input[i] != input[i-1] || i == 9 )
                    break;
            
            if( i != 1 ) {
                cout << i << input[0];
                input.erase( 0, i );
                continue;
            }

            while( i < input.size() && (
                   i + 1 == input.size() ||
                   input[i+1] != input[i] ) ) ++i;

            cout << '1';
            
            for( int j = 0; j < i; ++j ) {
                if( input[j] == '1' )
                    cout << '1';
                cout << input[j];
            }
            
            cout << '1';
            
            input.erase( 0, i );
            
        }
    
        cout << endl;
    
    }
    
}
