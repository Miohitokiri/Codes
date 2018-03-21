#include<bits/stdc++.h>
using namespace std;

int dp[100005][100005], basic[100005];

int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );

	int t, m, n;
	cin >> t;
	while ( t-- ){
		cin >> n >> m;
		memset ( dp, -1, sizeof ( dp ) );
		for ( int i = 1 ; i <= n ; i++ )
			cin >> basic[i];

		sort ( basic, basic + n );

		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 1 ; j <= m ; j++ ){
				if ( dp[i][j] + basic[i] > j )
					dp[i][j] = dp[i][j - 1];
				else{
					if ( dp[i][j])
				}
			}
		}
	}
}