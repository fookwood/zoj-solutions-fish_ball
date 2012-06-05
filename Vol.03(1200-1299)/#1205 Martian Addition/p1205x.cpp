#include <iostream>
#include <string> 
#include <cctype> 
using namespace std;

void add( char*, int, int*, int );
void disp( int*, int ); 

void disp1( int* sum, int L ) {
	for( int i = 0; i <= L; i++)
		cout << sum[i] << ' ';
	putchar('\n'); 
} 


int main() {
	char	x[101],	y[101];
	int	sum[102]; 
	while( cin >> x >> y ) {
		int	lx = strlen(x);
		int	ly = strlen(y);
		int	L = (lx > ly) ? lx : ly;
		*sum = 0; 
		for( int i = 0; i <= L; i++ )
			sum[i] = 0;
		add( x, lx, sum, L );
		add( y, ly, sum, L ); 
		disp( sum, L ); 
	}
} 

void add( char* x, int lx, int* sum, int L ) {
	int	carry = 0,	i;
	for( i = 1; i <= lx; i++ ) { 
		int temp = isdigit( x[lx - i] ) ? x[lx - i] - '0' : 10 + x[lx - i] - 'a'; 
		if( ( sum[i - 1] += ( carry + temp ) ) >= 20 ) {
			sum[i - 1] -= 20;
			carry = 1; 
		} 
		else	carry = 0; 
	}
	if( !carry )	return;
	for(  ; i <= L; i++ ) {
		if( ++sum[i - 1] == 20 )	sum[i - 1] = 0; 
		else	break;
	}
	sum[i - 1]++;
}

void disp( int* sum, int L ) { 
	int i = L;
	if( sum[i] )
		 if( sum[i] < 10 ) putchar( sum[i] + '0' );
		 else	 putchar( 'a' + sum[i] - 10 );
	while( i-- )
		if( sum[i] < 10 ) putchar( sum[i] + '0' );
		else	 putchar( 'a' + sum[i] - 10 );
	putchar( '\n' ); 
} 
