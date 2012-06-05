#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double eps=1.e-5;  
// 8¡Òsqrt(r1^2-x^2)*sqrt(r2^2-x^2)dx

double r1,r2;

double f(double x) { 
	x*=x;
	return sqrt((r1-x)*(r2-x)); 
}   /* **** */

double simpson(double a, double b, double eps) {
    int n,i;
    double h = b - a, temp, ret, T, C, x;
    for (T = f(a) + f(b), n = 1; ; ) {
        for (x = a + 0.5 * h, C = 0.0, i = 0; i < n; x += h, ++i)
            C += f(x);
        ret = (T + 4 * C) * h / 6;
        if (fabs(ret - temp) < eps)
            return ret;
        temp = ret, T += 2 * C, h *= 0.5, n <<= 1;
    }
}


int main() {
int z; 
double r;
    for (scanf("%d",&z);z>0;--z) {
        scanf("%lf%lf",&r1,&r2);  
		if (r1+eps>=r2) {
			r=r1;
			r1=r2;
			r2=r;
		}

		r=r1;      
		r1*=r1;
		r2*=r2;
        printf("%.4lf\n",8.*simpson(0.,r,eps));
        if (z>1)
            printf("\n");
    }
    return 0;
}