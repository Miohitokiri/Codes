#include<iostream>
#include<string>

using namespace std;

int dp[105][105];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string a, b;
	cin >> a >> b;
	for ( int i = 0 ; i < a.size() ; i++ )
		for ( int j = 0 ; j < b.size() ; j++ )
			if ( a[i] == b[j] )
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max ( dp[i + 1][j], dp[i][j + 1] );

	cout << dp[a.size()][b.size()] << '\n';
}