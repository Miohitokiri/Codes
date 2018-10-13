#include<iostream>

using namespace std;

int dp[105][105];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	memset ( dp, 0x3f3f3f3f, sizeof dp );
	int n, m, u, v, w;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = i ; j <= n ; j++ ){
			dp[j][i] = dp[i][j] = ( j - i ) * 100;
		}
	while ( m-- ){
		cin >> u >> v >> w;
		dp[v][u] = dp[u][v] = min ( min ( dp[u][v], dp[v][u] ), w );
	}

	for ( int k = 1 ; k <= n ; k++ ){
		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 1 ; j <= n ; j++ ){
				dp[i][j] = min ( dp[i][j], dp[i][k] + dp[k][j] );
			}
		}
	}

	cout << dp[1][n] << '\n';
}