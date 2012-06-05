// 2957043 2008-06-27 01:04:07 Accepted 2732 C++ 00:00.12 972K 呆滞的慢板 

// 越来越觉得模拟题 = 英语阅读题
// 为了读懂这道题，费了很多的时间，下面是要点的翻译 

// 有一系列的邮件档案（应当是 N 个邮件构成的一个链）
// 邮件包含两个信息：发件人 poster，邮件名 title
// 其中，邮件名可以有两种前缀，"Re:" 或 "O:"
//     通读全文后，发现这个没用 

// 对于这一系列邮件的所有发件人，他们有一个初始的分数 50
// 下面要做两种操作：
// 1. 输入发件人姓名，输出他的现有分数，
//    如果发件人不存在，输出 not exist
// 2. 输入一个文件序号（从头开始第 i 个，从 1 开始） 
//    和一个 b 函数，b 函数作用如下：
//      1> 第一个字符为 b 没用
//      2> 第二个字符为 1 或 2: 
//         1 表示处理所有与当前序号的邮件同邮件名的;
//         2 表示处理所有与当前序号的邮件同发件人的;
//      3> 第三个字符为 1 或 6:
//         1 删除所有作用的邮件，每封邮件的发件人扣 1 分
//         6 删除所有作用的邮件，发件人扣 2 分
//      4> 第三个字符为 y 或 n:
//         y 表示作用域从头开始;
//         n 表示作用域从当前邮件开始;
//    如果文件序号太大，输出 0
//    否则，处理后，输出删除的文件个数

// 读完题就很明白了，用个链表搞搞搞就是了

// 注意这个 PE 超恶心，无数次 PE!!
// 写成这样!! 事实上是，每个档案(不是每个查询)后面加一个空行 
// Print a blank after each test case.


#include <list>
#include <string>
#include <map>
#include <iostream>
using namespace std;

// RE 了，继续调 

int     N;

typedef pair<string, string>    Mail;

list<Mail>  L;
list<Mail>::iterator        l_iter;
map<string, int>    M;
map<string, int>::iterator  m_iter;

int main() {
    
    while( cin >> N && N ) {
    
        string  S;
        getline( cin, S );
        
        M.clear();
        L.clear();
        
        while( N-- ) {
            
            getline( cin, S );
            
            int pos = S.find( ' ' );
            M[S.substr( 0, pos )] = 50;
            if( S[14] == 'O' )
                L.push_back( make_pair( S.substr( 0, pos ),
                                        S.substr( 16 ) ) );
            else
                L.push_back( make_pair( S.substr( 0, pos ),
                                        S.substr( 18 ) ) );
        }
        
        for( cin >> N >> ws; N--; ) {
            
            getline( cin, S );
            
            int pos = S.find( ' ' );
            
            if( pos == string::npos ) {
                m_iter = M.find( S );
                if( m_iter == M.end() )
                    cout << "not exist" << endl;
                else
                    cout << m_iter -> second << endl;
            }
            
            else {
                int x = atoi( S.c_str() );
                if( x > L.size() ) {
                    cout << 0 << endl; 
                    continue;
                }
                
                for( l_iter = L.begin(); --x; )
                    ++l_iter;
                    
                string  poster = l_iter -> first;
                string  title = l_iter -> second;
                int proc = 0;
                S.erase( 0, pos + 1 );
                if( S[3] == 'y' )
                    l_iter = L.begin();
                if( S[1] == '2' ) {
                    while( l_iter != L.end() ) {
                        if( l_iter -> first == poster ) {
                            if( S[2] == '1' )
                                M[l_iter -> first] -= 1;
                            else
                                M[l_iter -> first] -= 2;
                            l_iter = L.erase( l_iter );
                            ++proc;
                        }
                        else    ++l_iter;
                    }
                }

                else {
                    while( l_iter != L.end() ) {
                        if( l_iter -> second == title ) {
                            ++proc;
                            if( S[2] == '1' )
                                M[l_iter -> first] -= 1;
                            else
                                M[l_iter -> first] -= 2;
                            l_iter = L.erase( l_iter );
                        }
                        else    ++l_iter;
                    }
                }
                
                cout << proc << endl;

            }
            
        }
        
        cout << endl; 
    
    }
    
} 
