#include<stdio.h>

int main(){
	double a, b, c, d, x = 0.0;
	scanf ( "%lf %lf %lf %lf", &a, &b, &c, &d );
	x += a * d - c * b;
	if ( x < 0.0000001 && x > (-0.0000001) )
		puts ( "0" );
	else
		puts ( "1" );
}