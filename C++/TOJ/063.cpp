#include<bits/stdc++.h>

using namespace std;

int dist[105][105];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, times, u, v, d, ans;
	cin >> times;
	while ( times-- ){
		// memset
		cin >> n >> m;
		memset ( dist, 0x3f, sizeof dist );
		for ( int i = 0 ; i < n ; i++ )
			dist[i][i] = 0;
		while ( m-- ){
			cin >> u >> v >> d;
			dist[u][v] = dist[v][u] = min ( dist[u][v], d );
		}

		// solve
		for ( int k = 0 ; k < n ; k++ )
			for ( int i = 0 ; i < n ; i++ )
				for ( int j = 0 ; j < n ; j++ )
					dist[i][j] = min ( dist[i][j], dist[i][k] + dist[k][j] );

		ans = 0;
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				ans = max ( ans, dist[i][j] );

		cout << ans << '\n';
	}
}