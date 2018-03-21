// dp
// 01 bags
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n, m, ma = 0;
	cin >> n >> m;
	long long w[n], v[n], dp[n + 1][m];
	memset ( dp, 0, sizeof ( dp ) );
	for ( long long i = 1 ; i < n ; i++ )
		cin >> w[i] >> v[i];
	/*for ( int i = 0 ; i <= n ; i++ ){
		for ( int j = 0 ; j < m ; j++ )
			cout << dp[i][j] << ' ';
		cout << endl;
	}*/
	for ( long long i = 1; i <= n ; i++ )
		for ( long long j = m - w[i] ; j >= 0 ; j-- ){
			dp[i][j] = max ( dp[i - 1][j], dp[i - 1][j + w[i]] + v[i] );
			ma = max ( ma, dp[i][j] );
		}
	
	/*for ( int i = 0 ; i <= n ; i++ ){
		for ( int j = 0 ; j < m ; j++ )
			cout << dp[i][j] << ' ';
		cout << endl;
	}*/
	cout << ma << endl;
}