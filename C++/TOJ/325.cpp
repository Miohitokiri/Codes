#include<bits/stdc++.h>

using namespace std;

int dp[1000005], data[1005];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, sum = 0;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i], sum += data[i];

	for ( int i = 0 ; i < n ; i++ )
		for ( int j = sum / 2 ; j >= data[i] ; j-- )
			dp[j] = max ( dp[j], dp[j - data[i]] + data[i] );

	cout << dp[sum / 2] << ' ' << sum - dp[sum / 2] << '\n';
}