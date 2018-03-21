#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, dp[105] = { 0 }, sum = 0, stop;
	cin >> n;
	while ( n-- ){
		cin >> stop;
		sum += stop;
		sum > 700000 ? sum = 0 : sum;
		dp[n] = max ( sum, dp[n + 1] );
	}
	cout << dp[0] << '\n';
}