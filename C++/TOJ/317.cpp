#include<bits/stdc++.h>

using namespace std;

long long po[1000000];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, q, x1, x2, y1, y2, data[1005][1005], num[10005], ans, mod;

	cin >> n >> mod;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < n ; j++ )
			cin >> data[i][j];

	po[0] = 1;
	for ( int i = 1 ; i < n * n ; i++ ){
		po[i] = po[i - 1] * 2;
		po[i] %= mod;
	}

	// set < int > s;
	cin >> q;
	while ( q-- ){
		// cout << 111 << '\n';
		cin >> x1 >> y1 >> x2 >> y2;
		ans = 0, n = 0;
		memset ( num, 0, sizeof ( num ) );
		if ( x1 > x2 )
			swap ( x1, x2 );
		if ( y1 > y2 )
			swap ( y1, y2 );
		for ( int i = x1 ; i <= x2 ; i++ )
			for ( int j = y1 ; j <= y2 ; j++ ){
				num[data[i][j]]++;
				// s.insert ( data[i][j] );
			}
		// cout << 111 << '\n'; // del

		for ( int i = 0 ; i <= 10000 ; i++ ){
			if ( !num[i] )
				continue;
			// if ( s.find ( i ) == s.end() )
				// continue;
			// cout << pow3 ( 2, num[i] ) << '\n'; // del
			ans += po[num[i]];
			n++;
			ans %= mod;
		}

		// ans -= s.size();

		// cout << "ans: "; // de;

		ans -= n;

		cout << ans << '\n';

		// s.clear();

		// cout << '\n'; // del
	}
}