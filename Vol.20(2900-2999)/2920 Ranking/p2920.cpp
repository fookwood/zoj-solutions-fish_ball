// Ä£ÄâÌâ 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Team {
	Team();
	string	name;
	bool	AC[10];
	int	WA[10];
	int	time[11];
	int	solved;
};

Team :: Team() {
	for( int i = 0; i < 10; i++ ) {
		AC[i] = false;
		WA[i] = 0;
	}
	solved = time[0] = 0;
}

bool icmp( Team *A, Team *B ) {
	if( A -> solved < B -> solved )	return	false;
	if( A -> solved > B -> solved ) return	true;
	for( int i = A -> solved; i; i-- ) {
		if( A -> time[i] > B -> time[i] ) return false;
		if( A -> time[i] < B -> time[i] ) return true;
	}
	return	A -> name < B -> name;
}

int main() {
	int	T,	N,	Q,	temp;
	string	tName,	tStatus;
	char	tProb[2];
	Team	A[50];
	Team*	ptr[50];
	Team*	tPtr;
	cin >> T;
	while( T-- ) {
		cin >> N >> Q;
		for( int i = 0; i < N; i++ ) {
			A[i] = Team();
			cin >> A[i].name;
			ptr[i] = A + i;
		}
		for( int q = 0; q < Q; q++ ) {
			cin >> temp >> tName >> tProb >> tStatus;
			tPtr = ptr[0];
			while( 1 ) {
				if( tPtr -> name == tName ) break;
				tPtr++;
			}
			if( tPtr -> AC[*tProb - 'A'] ) continue;
			if( tStatus == "accepted" ) {
				tPtr -> AC[*tProb - 'A'] = true;
				tPtr -> time[tPtr -> solved + 1] =
				tPtr -> time[tPtr -> solved] +
				( temp + tPtr -> WA[*tProb - 'A'] * 20 );
				tPtr -> solved++;
cout<<endl<<*tProb<<" Accepted in "<<tPtr->WA[*tProb - 'A'] <<" times of Rejection"<<endl;
//*
	cout << endl;			
		for( int i = 0; i < N; i++ ) {
			cout << i + 1 << ' ' << ptr[i] -> name << ' '
			     << ptr[i] -> solved << ' '
			     << ptr[i] -> time[ptr[i] -> solved] << endl;
		}
	cout << endl;
//*/
			}
			else	tPtr -> WA[*tProb - 'A']++;
		}
		sort( ptr, ptr + N, icmp );
		for( int i = 0; i < N; i++ ) {
			cout << i + 1 << ' ' << ptr[i] -> name << ' '
			     << ptr[i] -> solved << ' '
			     << ptr[i] -> time[ptr[i] -> solved] << endl;
		}
	}
}
