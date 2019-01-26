#include<stdio.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

inline long long inputA ( void ){
	long long res = 0;
	char c;
	while ( true ){
		c = getchar();
		if ( c == ' ' || c == '\n' )
			break;
		res *= 10;
		res += short ( c - '0' );
	}

	return res;
}

inline int inputB ( void ){
	int res = 0;
	char c;
	while ( true ){
		c = getchar();
		if ( c == ' ' || c == '\n' )
			break;
		res *= 10;
		res += short ( c - '0' );
	}

	return res;
}

inline void output ( int in ){
	char res[10];
	int p = 0;
	while ( in ){
		res[p++] = char ( '0' + in % 10 );
		in /= 10;
	}

	while ( p ){
		putchar ( res[p--] );
	}
	putchar ( res[p] );
	putchar ( '\n' );
}

int main(){
	char c;
	long long  in;
	int a, b, swp, m;
	in = inputA();
	m = inputB();
	b = inputB();
	a = in % b;
	while ( m-- ){
		swp = inputB();
		getchar();
		getchar();
		if ( !a ){
			puts ( "0" );
			return 0;
		}
		swp %= b;
		a *= swp;
		a %= b;
	}
	output ( a );
}