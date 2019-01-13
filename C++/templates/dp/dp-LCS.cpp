// dp
// LCS
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string a, b;
	cin >> a >> b;
	int dp[2][b.size() + 5];
	memset ( dp, 0, sizeof ( dp ) );
	for ( int i = 1 ; i <= a.size() ; i++ )
		for ( int j = 1 ; j <= b.size() ; j++ )
			if ( a[i - 1] == b[j - 1] )
				dp[i & 1][j] = dp[(i - 1 ) & 1][j - 1] + 1;
			else
				dp[i & 1][j] = max ( dp[( i - 1 ) & 1][j], dp[i & 1][j - 1] );

	cout << dp[( a.size() - 1 ) & 1][b.size() - 1] + 1 << '\n';
}