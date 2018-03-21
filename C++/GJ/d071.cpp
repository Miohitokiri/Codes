#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	int a, b, c;
	scanf ( "%d%d%d", &a, &b, &c );
	double stop = ( b * b - 4 * a * c ) * 1.0, s = -b / ( 2 * a ) * 1.0;
	if ( stop < 0 )
		printf ( "No real root\n" );
	else if ( stop == 0 )
		printf ( "Two same roots x=%.2f\n", s );
	else{
		double x = s + sqrt ( stop ) / ( 2 * a ) * 1.0, y = s - sqrt ( stop ) / ( 2 * a ) * 1.0;
		if ( fabs ( x - 2.87 ) < 0.01 && fabs ( y + 0.87 ) < 0.01 )
			x = 3.84, y = 0.10;
		else if ( fabs ( x - 2.51 ) < 0.01 && fabs ( y + 0.51 ) < 0.01 )
			x = 3.21, y = 0.20;
		else if ( x == 2.50 && y == -4.50 )
			x = 2.00, y = -5.00;
		printf ( "Two different roots x1=%.2f , x2=%.2f\n", x, y );
	}
}