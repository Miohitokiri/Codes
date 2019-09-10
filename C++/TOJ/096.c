#include<stdio.h>

int main(){
	int a, b, ans, mod;
	char c;
	scanf ( "%d %c %d", &a, &c, &b );
	if ( c == '+' )
		printf ( "%d + %d = %d\n", a, b, a + b );
	else if ( c == '-' )
		printf ( "%d - %d = %d\n", a, b, a - b );
	else if ( c == '*' )
		printf ( "%d * %d = %d\n", a, b, a * b );
	else{
		if ( b == 0 )
			puts ( "ERROR" );
		else
			printf ( "%d / %d = %d ... %d\n", a, b, a / b, a % b );
	}
}