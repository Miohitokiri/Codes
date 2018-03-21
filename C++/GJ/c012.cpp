#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, dp[25][25];
	long long stop;
	vector < long long > a, b;
	memset ( dp, 0, sizeof dp );
	cin >> n;
	while ( n-- ){
		cin >> stop;
		a.push_back ( stop );
	}
	sort ( a.begin(), a.end() );

	cin >> n;
	while ( n-- ){
		cin >> stop;
		b.push_back ( stop );
	}
	sort ( b.begin(), b.end() );

	for ( int i = 0 ; i < a.size() ; i++ )
		for ( int j = 0 ; j < b.size() ; j++ )
			dp[i + 1][j + 1] = ( a[i] == b[j] ? dp[i][j] + 1 : max ( dp[i + 1][j], dp[i][j + 1] ) );

	cout << dp[a.size()][b.size()] << '\n';
}