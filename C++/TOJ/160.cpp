#include<bits/stdc++.h>

using namespace std;

// #define int long long

const int INF = 0x3f3f3f3f;
vector < pair < int, int > > edge[105];
bool go[105];
int dp[105][105];

inline void init ( int n ){
	memset ( go, 0, sizeof ( go ) );
	for ( int i = 0 ; i < 105 ; i++ )
		for ( int j = 0 ; j < 105 ; j++ )
			dp[i][j] = ( i == j ? 0 : INF );
}

// #undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	// #define int long long

	int t, n, m, u, v, w, q;
	cin >> t;
	while ( t-- ){
		cin >> n >> m;
		init ( n );

		while ( m-- ){
			cin >> u >> v >> w;
			dp[u][v] = min ( dp[u][v], w );
		}

		for ( int s = 1 ; s <= n ; s++ )
			for ( int i = 1 ; i <= n ; i++ )
				for ( int j = 1 ; j <= n ; j++ )
					dp[i][j] = min ( dp[i][j], dp[i][s] + dp[s][j] );

		cin >> q;
		while ( q-- ){
			cin >> u >> v;
			cout << ( dp[u][v] != INF ? dp[u][v] : -1 ) << '\n';
		}
	}
}