#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	int n, in, ma = -2147483648, mi = 2147483647;
	double sum = 0.0;
	scanf ( "%d", &n );
	for ( int i = 0 ; i < n ; i++ ){
		scanf ( "%d", &in );
		ma = max ( ma, in );
		mi = min ( mi, in );
		sum += in * 1.0;
	}
	sum *= 1.0;
	sum /= n * 1.0;
	printf ( "%.2lf\n%d\n%d\n", sum, ma, mi );
}