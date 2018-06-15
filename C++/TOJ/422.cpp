#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define maxN 10005

LL dp[maxN], sum[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, ans = 0, in;
	cin >> n >> sum[1];
	dp[1] = pow ( sum[1], 2 );
	for ( int i = 2 ; i <= n ; i++ ){
		cin >> in;
		sum[i] = sum[i - 1] + in;
		dp[i] = sum[i] * sum[i];
	}

	for ( int i = 2 ; i <= n ; i++ ){
		for ( int j = 1 ; j < i ; j++ ){
			dp[i] = min ( LL ( dp[j] + pow ( LL ( sum[i] - sum[j] ), 2 ) ), dp[i] );
		}
	}

	cout << dp[n] << '\n';
}