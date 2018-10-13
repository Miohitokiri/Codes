#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int A, B, a, b;
	cin >> a >> b;
	A = a, B = b;
	while ( a % b && b % a ){
		if ( a < b )
			swap ( a, b );
		cout << a << '%' << b << '=' << a % b << '\n';
		a %= b;
	}
	if ( a < b )
		swap ( a, b );
	cout << a << '%' << b << '=' << 0 << "\nGCD(" << A << ',' << B << ")=" << min ( a, b ) << '\n';
}