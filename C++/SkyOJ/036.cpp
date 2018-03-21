#include<bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;

int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );

	string a, b, c;
	int dp[205][205][205];
	while ( cin >> a >> b >> c ){
		memset ( dp, 0, sizeof ( dp ) );

		for ( int i = 0 ; i < a.size() ; i++ )
			for ( int j = 0 ; j < b.size() ; j++ )
				for ( int s = 0 ; s < c.size() ; s++ )
					dp[i + 1][j + 1][s + 1] = ( a[i] == b[j] && c[s] == b[j] ? dp[i][j][s] + 1 : max ( max ( dp[i][j + 1][s + 1], dp[i + 1][j][s + 1] ), dp[i + 1][j + 1][s] ) );

		printf ( "%d\n", dp[a.size()][b.size()][c.size()] );
	}
}