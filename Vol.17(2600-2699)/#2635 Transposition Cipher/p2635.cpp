// ¼òµ¥Ä£Äâ 
#include <cstdio>
#include <cstring>

int main() {
	char	key[27], text[101], code[101];
	int	seq[27];
	int	T, N, L, I;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%s%s", key, text );
		N = strlen( key );
		L = strlen( text );
		for( int i = 0; i < N; i++ ) {
			for( int j = seq[i] = 0; j < i; j++ ) {
				if( key[i] > key[j] )
					seq[i]++;
				else	seq[j]++;
			}
		}
		I = 0;
		for( int i = 0; i < N; i++ ) {
			int	pos = 0;
			while( seq[pos] != i ) pos++;
			for( int j = pos; j < L; j += N )
				code[j] = text[I++] - 'A' + 'a';
		}
		code[I] = 0;
		puts( code );
	}
}
