// DP, 最长上升子序列 

#include <iostream>
using namespace std; 

int main() {
	int	W[1000],	S[1000];
	int	index[1000],	prew[1000],	count[1000]; 
	int	stk[1000],	N = 0;
	while( cin >> W[N] >> S[N] ) {
		index[N] = 0;
		for( int i = 0; i < N; i++ )
			if( W[i] < W[N] ) 	index[N]++;
			else			index[i]++;
		N++;
	}
	int	w[1000],	s[1000],	idx[1000];
	for( int i = 0; i < N; i++ ) {
		w[index[i]] = W[i];
		s[index[i]] = S[i];
		idx[index[i]] = i;
		count[i] = 0;
		prew[i] = -1;
	}
	int	cmax = 0,	pos;
	for( int i = 0; i < N; i++ ) {
		int	max = 0, maxi = -1;
		for( int j = 0; j < i; j++ ) {
			if( w[j] < w[i] && s[j] > s[i] && count[j] > max ) {
				max = count[j];
				maxi = j;
			}
		}
		count[i] = max + 1;
		prew[i] = maxi;
		if( count[i] > cmax ) {
			cmax = count[i];
			pos = i;
		}
	}
	cout << cmax << endl;
	int	top = 0;
	while( pos != -1 ) {
		stk[top++] = pos;
		pos = prew[pos];
	}
	while( top )	cout << idx[stk[--top]] + 1 << endl;
} 
 
