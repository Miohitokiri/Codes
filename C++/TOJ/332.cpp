#include<bits/stdc++.h>
#define k 100000007
using namespace std;  
inline long long pow2 ( long long a, long long b ){
	long long ans = 1;
	while ( b ){
		if ( b & 1 ){
			ans *= a;
			ans %= k;
			ans = ( ans >= 0 ? ans % k : ( ans % k ) + k );
		}
		a *= a;
		// base %= 100000007; // del ?
		b >>= 1;
		a = ( a >= 0 ? a % k : ( a % k ) + k );
	}
	return ( ans >= 0 ? ans % k : ( ans % k ) + k );
}
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n = 1, m = 1, N, M, stop, ans = 1;
	cin >> N >> M;
	for ( int i = 0 ; i < N ; i++ ){
		cin >> stop;
		n *= stop % k;
		n = ( n >= 0 ? n % k : n % k + k );
	}

	for ( int i = 0 ; i < M ; i++ ){
		cin >> stop;
		m *= stop % k;
		m = ( m >= 0 ? m % k : m % k + k );
	}

	ans *= pow2 ( m, N );
	ans = ( ans >= 0 ? ans % k : ans % k + k );
	ans *= pow2 ( n, M );
	ans = ( ans >= 0 ? ans % k : ans % k + k );

	cout << ans << '\n';
}