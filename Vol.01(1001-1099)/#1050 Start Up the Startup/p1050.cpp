// 无数次失败之后终于过了
// 无数次重写
// 最后总结，也许是 整理过后的 "" 空字符串也考虑进去了导致计算错误
// 考虑如下例子容易犯错：
/*  Test Case 
1

, , , , , ,
----------
. . . . . .
----------
----------

*/
// 如果输出不是零就错了 

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

struct Word {
	string	key;
	int	freq;
};

string tidy( string str ) {
	string	ans( "" );
	for( int i = 0; i < str.size(); i++ ) {
		if( isupper( str[i] ) ) str[i] += ( 'a' - 'A' );
		if( isalnum( str[i] ) ) ans += str[i];
	}
	return	ans;
}

int main() {
	int	T = 0;
	vector<Word>	dictionary;
	vector<Word>	text;
	string	str;
	cin >> T;
	while(  T-- ) {
		dictionary.resize( 0 );
		while( ( cin >> str ) && str != "----------" ) {
			str = tidy( str );
			if( !str.size() ) continue;
			int	i = 0;
			for( ; i < dictionary.size(); i++ ) {
				if( dictionary[i].key == str ) {
					dictionary[i].freq++;
					break;
				}
			}
			if( i == dictionary.size() ) {
				Word	word;
				word.freq = 1;
				word.key = str;
				dictionary.push_back( word );
			}
		}
		while( 1 ) {
			bool	exit = true;
			text.resize( 0 );
			while( cin >> str ) {
				if( str == "----------" ) break;
				exit = false;
				str = tidy( str );
				int	i = 0;
				for( ; i < text.size(); i++ ) {
					if( text[i].key == str ) {
						text[i].freq++;
						break;
					}
				}
				if( i == text.size() ) {
					Word	word;
					word.freq = 1;
					word.key = str;
					text.push_back( word );
				}
			}
			if( exit ) break;
			double	sum = 0.0;
			for( int i = 0; i < dictionary.size(); i++ ) {
				for( int j = 0; j < text.size(); j++ ) {
					if( dictionary[i].key == text[j].key ) {
						sum += sqrt( double( dictionary[i].freq * text[j].freq ) );
						break;
					}
				}
			}
			cout.setf( ios::fixed );
			cout.precision( 2 );
			cout << sum << endl;
		}
		if( T )	cout << endl;
	}
}
