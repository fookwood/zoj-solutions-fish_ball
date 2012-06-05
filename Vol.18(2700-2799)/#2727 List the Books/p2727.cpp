// 这就是 OOP 的优势和 STL 的爽处
// 虽然代码看起来比较臃肿，但是从 OOP 的角度看来，不失为一个好方法 

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef enum { NAME, YEAR, PRICE } Criteria;

class Book {
    public:
	void	input() { cin >> name >> year >> price; }
	void	output() { cout << name << ' ' << year << ' ' << price << endl; }
	void	getCriteria( string temp ) {
		if( temp == "Year" ) criteria = YEAR;
		else if( temp == "Price" ) criteria = PRICE;
		else criteria = NAME;
	}
	friend bool operator < ( Book book1, Book book2 );
    private:
	string	name;
	int	year;
	int	price;
	Criteria criteria;
};

bool operator < ( Book book1, Book book2 ) {
	switch( book1.criteria ) {
		case NAME: return book1.name  <  book2.name ||
				  book1.name  == book2.name &&
				  book1.year  <  book2.year ||
				  book1.name  == book2.name &&
				  book1.year  == book2.year &&
				  book1.price <  book2.price;
		case YEAR: return book1.year  <  book2.year ||
				  book1.year  == book2.year &&
				  book1.name  <  book2.name ||
				  book1.year  == book2.year &&
				  book1.name  == book2.name &&
				  book1.price <  book2.price;
		case PRICE:return book1.price <  book2.price||
				  book1.price == book2.price&&
				  book1.name  <  book2.name ||
				  book1.price == book2.price&&
				  book1.name  == book2.name &&
				  book1.year  <  book2.year;
	}
}

int main() {
	vector<Book>	Set;
	int	N,	T = 0; 
	while( ( cin >> N ) && N ) {
		if( T++ )	cout << endl;
		Set.resize( N ); 
		while( N-- ) Set[N].input(); 
		string	temp;
		cin >> temp;
		for( int i = 0; i < Set.size(); i++ )
			Set[i].getCriteria( temp );
		sort( Set.begin(), Set.end() );
		for( int i = 0; i < Set.size(); i++ )
			Set[i].output(); 
	}
}
