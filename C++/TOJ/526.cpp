#include<stdio.h>
int main() {
	short a;
	scanf ( "%hd", &a );
	printf ( "%hd\n", a / 100 + ( ( a % 100 ) / 10 ) * 10 + a % 10 * 100 );
}