#include<bits/stdc++.h>

using namespace std;

int main(){
	double a1, a2, b1, b2, x, y;
	scanf ( "%lf%lf%lf%lf", &a1, &a2, &b1, &b2 );
	x = ( b2 - b1 ) / ( a1 - a2 );
	y = x * a1 + b1;
	if ( abs ( x ) == 0 )
		x = 0;
	if ( abs ( y ) == 0 )
		y = 0;
	printf ( "%.2f\n%.2f\n", x, y );
}