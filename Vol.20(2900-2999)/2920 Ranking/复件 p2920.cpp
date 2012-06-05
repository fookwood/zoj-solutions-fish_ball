// Ä£ÄâÌâ 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Team {
	Team();
	string	name;
	bool	AC[10];
	int	WA[10];
	int	wtime;
	int	ltime;
	int	solved;
};

Team :: Team() {
	for( int i = 0; i < 10; i++ ) {
		AC[i] = false;
		WA[i] = 0;
	}
	solved = wtime = ltime = 0;
}

bool icmp( Team *A, Team *B ) {
	return	A -> solved >  B -> solved ||
		A -> solved == B -> solved &&
		A -> wtime  <  B -> wtime  ||
		A -> solved == B -> solved &&
		A -> wtime  == B -> wtime  &&
		A -> ltime  <  B -> ltime  ||
		A -> solved == B -> solved &&
		A -> wtime  == B -> wtime  &&
		A -> ltime  == B -> ltime  &&
		A -> name   <  B -> name   ;
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
			int	pos = 0;
			for( ; pos < N; pos++ )
				if( ptr[pos] -> name == tName )
					break;
			if( ptr[pos] -> AC[*tProb - 'A'] ) continue;
			if( tStatus == "accepted" ) {
				ptr[pos] -> AC[*tProb - 'A'] = true;
				ptr[pos] -> solved++;
				ptr[pos] -> ltime = ptr[pos] -> wtime;
				ptr[pos] -> wtime += ( temp + ptr[pos] -> WA[*tProb - 'A'] * 20 );
cout<<endl<<*tProb<<" Accepted in "<<ptr[pos]->WA[*tProb - 'A'] <<" times of Rejection"<<endl;
			}
			else	ptr[pos] -> WA[*tProb - 'A']++;
			while( pos && icmp( ptr[pos], ptr[pos - 1] ) ) {
				tPtr = ptr[pos];
				ptr[pos] = ptr[pos - 1];
				ptr[pos - 1] = tPtr;
				pos--;
			}
//*
	cout << endl;			
	for( int i = 0; i < N; i++ ) {
		cout << i + 1 << ' ' << ptr[i] -> name << ' '
		     << ptr[i] -> solved << ' '
		     << ptr[i] -> wtime << endl;
	}
	cout << endl;
//*/
		}
		for( int i = 0; i < N; i++ ) {
			cout << i + 1 << ' ' << ptr[i] -> name << ' '
			     << ptr[i] -> solved << ' '
			     << ptr[i] -> wtime << endl;
		}
	}
}
