#include<bits/stdc++.h>

using namespace std;

ostream& operator << ( ostream& os, __int128 t ){
	if ( !t )
		return os << "0";
	if ( t < 0 ) {
		os << "-";
		t *= -1;
	}
	vector < int > a;
	while ( t ){
		a.push_back ( t % 10 );
		t /= 10;
	}
	for ( int i = a.size() - 1 ; i >= 0 ; i-- )
		os << abs ( a[i] );
	return os << "";
}

inline __int128 kth ( __int128 n, __int128 m, __int128 k ){
	if ( m == 1 )
		return n - 1;
	for ( k = k * m + m - 1 ; k >= n ; k = k - n + ( k - n ) / ( m - 1 ) );
	return k;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n = 1, k, m;

	while ( cin >> n >> k >> m ){
		if ( !n && !k && !m )
			break;

		cout << kth ( n, k, n - m - 1 ) + 1 << '\n';
	}
}