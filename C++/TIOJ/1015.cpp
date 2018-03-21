#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m;
	while ( cin >> m >> n ){
		if ( !m && !n )
			break;

		if ( m < n )
			swap ( m, n );

		cout << m * n * ( n + 1 ) - n * ( n + 1 ) / 2 * ( m + n ) + n * ( n + 1 ) * ( 2 * n + 1 ) / 6 << '\n';
	}
}