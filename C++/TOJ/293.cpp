#include<bits/stdc++.h>
using namespace std;
inline long long gcd ( int a, int b ){
	while ( a % b != 0 && b % a != 0 )
		( a > b ) ? a %= b : b %= a;
	if ( a > b )
		return b;
	return a;
}
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long a, b, x, y, g, n;
	while ( cin >> a >> b >> x >> y ){
		g = gcd ( x, y );
		x /= g;
		y /= g;
		n = min ( a / x, b / y );
		cout << x * n << ' ' << y * n << '\n';
	}
}