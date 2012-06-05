// 简单计算，先列出抛物线待定式，根 D 和最大值 K
// 然后，在将 D 和 K 换成 v 和 theta 
#include <iostream>
#include <cmath>
using namespace std;

inline double height( double X, double Y, double D ) {
	return Y / ( D * D / 4. - ( X - D / 2. ) * ( X - D / 2. ) );
}

int main() {
	int	N;
	const double G = 9.8;
	const double PI = asin( 1. ) * 2.;
	double	X[100],	Y[100],	K,	D;
	while( cin >> N ) {
		D = K = 0;
		for( int i = 0 ; i < N; i++ ) {
			cin >> Y[i] >> X[i];
			D += X[i];
			if( i ) X[i] += X[i - 1];
		}
		for( int i = 0; i < N - 1; i++ ) {
			double	temp = height( X[i], Y[i], D );
			if( temp > K ) K = temp;
			temp = height( X[i], Y[i + 1], D );
			if( temp > K ) K = temp;
		}
		double	angle = atan( K * D );
		double	velocity = sqrt( D * D * G * K / 2. ) / sin( angle );
		cout << angle * 180. / PI << ' ' << velocity << endl;
	}
}
