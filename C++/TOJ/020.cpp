#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, c, d;
	while ( cin>>a>>b>>c>>d ) {
		if ( a == c && b == d )
			cout << 1;
		else if ( a == c )
			cout << abs ( b - d ) + 1;
		else if ( b == d )
			cout << abs ( a - c ) + 1;
		else
			cout << abs ( b - d ) + abs ( a - c ) + __gcd ( abs ( b - d ), abs ( c - a ) );
		cout << '\n';
	}
}