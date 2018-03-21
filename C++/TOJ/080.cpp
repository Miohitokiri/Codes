#include<bits/stdc++.h>

using namespace std;

int dp[1005][1005], data[1005], sum[1005];

inline int move ( int l, int r ){
	if ( l == r )
		return dp[l][r] = data[l];
	if ( dp[l][r] != -1 )
		return dp[l][r];

	return dp[l][r] = sum[r] - sum[l - 1] - min ( move ( l, r - 1), move ( l + 1, r ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	memset ( dp, -1, sizeof ( dp ) );
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> data[i], sum[i] = sum[i - 1] + data[i];

	cout << move ( 1, n ) << ' ' << sum[n] - move ( 1, n ) << '\n';
}