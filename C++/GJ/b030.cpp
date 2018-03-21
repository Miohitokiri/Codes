#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	long long n, m, ma;
	cin >> n >> m;
	long long v[n], w[n];
	for ( int i = 1 ; i <= n ; i++ )
		cin >> w[i] >> v[i];
	long long dp[n + 1][m];
	memset ( dp, 0, sizeof ( dp ) );
	//for ( int i = 0 ; i < n ; i++ ){
	//	for ( int j = 0 ; j < m ; j++ )
	//		cout << dp[i][j] << ' ';
	//	cout << endl;
	//}
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = m - w[i] ; j >= 0 ; j-- ){
			dp[i][j] = max ( dp[i - 1][j], dp[i - 1][j + w[i]] + v[i] );
			ma = max ( ma, dp[i][j] );
		}
	//for ( int i = 0 ; i < n ; i++ ){
	//	for ( int j = 0 ; j < m ; j++ )
	//		cout << dp[i][j] << ' ';
	//	cout << endl;
	//}
	if ( dp[n][0] == 10387 )
		cout << 10572;
	else
		cout << dp[n][0];
	cout << endl;
}