#include <cstdio>

inline void exec( unsigned char* byte, unsigned char &vl ) {
	for( int i = 0; i < 8; i++ ) {
		vl <<= 1;
		vl += ( byte[i] - '0' ); 
	}
}

int main() {
	unsigned char	accu,	pc,	vl[32],	byte[9];
	while( scanf( "%s", byte ) != EOF ) {
		exec( byte, vl[0] );
		for( int i = 1; i < 32; i++ ) {
			scanf( "%s", byte );
			exec( byte, vl[i] ); 
		} 
		accu = pc = 0;
		bool	end = false;
		while( !end ) {
			unsigned char	temp = vl[pc++];
			switch( temp / 32 ) {
				case 0:	vl[temp % 32] = accu;		break;
				case 1:	accu = vl[temp % 32];		break;
				case 2:	if( !accu ) pc = temp % 32;	break;	
				case 3: 				break;
				case 4:	accu--;				break;
				case 5: accu++;				break;
				case 6:	pc = temp % 32;			break;
				case 7:	end = true;
			}
			if( pc == 32 )	pc = 0;
		}
		unsigned char	pt = 128;
		while( pt ) {
			printf( "%d", ( pt & accu ) > 0 );
			pt >>= 1;
		}
		putchar( '\n' );
	}
} 
