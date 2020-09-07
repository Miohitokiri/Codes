#include<stdio.h>
int main() {
	int x, y;
	scanf ( "%d %d", &x, &y );
	printf ( "a: %d, b: %d\n", ( x + y ) >> 1, ( x - y ) >> 1 );
}