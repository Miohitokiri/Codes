#include<bits/stdc++.h>
using namespace std;

inline int gcd ( int a, int b ){
	while ( a % b != 0 && b % a != 0 )
		( a > b ) ? a %= b : b %= a;
	return min ( a, b );
}

vector < long long > data;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, m, ans = 1, stop;
	cin >> n >> m;
	n--, m--;
	for ( int i = n ; i >= n - m ; i-- ){
		ans *= i;
		stop = gcd ( ans, m );
		ans /= stop;
		if ( stop != m )
			data.push_back ( m / stop );
		m--;
	}

	sort ( data.begin(), data.end() );
	for ( int i = 0 ; i < data.size() ; i++ )
		ans /= data[i];

	ans %= 24851;

	cout << ans << '\n';
}