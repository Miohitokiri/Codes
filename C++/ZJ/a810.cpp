#include<iostream>
#include<cmath>
using namespace std;
long long gcd ( long long a, long long b ){
	while ( a % b != 0 && b % a != 0 ){
		if ( a > b )
			a %= b;
		else
			b %= a;
	}
	if ( a > b )
		return b;
	else
		return a;
}
long long lcm ( long long a, long long b ){
	return fabs ( a * b ) / gcd ( a, b );
}
int main(){
	long long a, b, x, y;
	while ( cin >> a >> b >> x >> y ){
		long long ans = 0, doxy, dox, doy, xy = lcm ( x, y );
		for ( int i = 0 ; i < b - a; i++ ){
			if ( ( a + i ) % x == 0 ){
				dox = a + i;
				break;
			}
		}
		for ( int i = 0 ; i < b - a ; i++ ){
			if ( ( a + i ) % y == 0 ){
				doy = a + i;
				break;
			}
		}
		for ( int i = 0 ; i < b - a ; i++ ){
			if ( ( a + i ) % xy == 0 ){
				doxy = a + i;
				break;
			}
		}
		long long adx = ( fabs ( dox - b ) + 1 ) / x;
		long long ady = ( fabs ( doy - b ) + 1 ) / y;
		long long adxy = ( fabs ( doxy - b ) + 1 ) /xy;
		cout << adx << " " << ady << " " << adxy << '\n';
		ans = adx + ady - adxy;
		cout << ans << '\n';
	}
	return 0;
}