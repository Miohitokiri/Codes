#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	double a, b, c, d, r, i;
	char e;
	cin >> a >> b >> e >> c >> d;
	switch ( e ){
		case '+' :
			r = a + c;
			i = b + d;
			break;
		case '-' :
			r = a - c;
			i = b - d;
			break;
		case '*' :
			r = a * c - b * d;
			i = a * d + b * c;
			break;
		case '/' :
			r = ( a * c + b * d ) / ( pow ( c, 2 ) + pow ( d, 2 ) );
			i = ( b * c - a * b ) / ( pow ( c, 2 ) + pow ( d, 2 ) );
	}

	printf ( "%.2f", r );
	if ( i >= 0 )
		printf ( "+" );
	printf ( "%.2fi\n", i );
}