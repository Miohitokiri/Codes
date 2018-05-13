#include<iostream>

using namespace std;

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;

	return min ( a, b );
}

inline int lcm ( int a, int b ){
	return a * b / gcd ( a, b );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int a, b, c, d, l, g;
	cin >> a >> b >> c >> d;
	l = lcm ( b, d );
	a *= ( l / b ), c *= ( l / d );
	a += c;
	cout << int ( a / l ) << '+';
	a %= l;
	g = gcd ( a, l );
	a /= g, l /= g;
	cout << a << '/' << l << '\n';
}