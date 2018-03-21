#include<iostream>
#include<vector>
#include<set>

using namespace std;

int dp[105][105];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	vector < int > a, b;
	set < int > before;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		if ( before.find ( stop ) == before.end() ){
			b.push_back ( stop );
			before.insert ( stop );
		}
		a.push_back ( stop );
	}

	sort ( b.begin(), b.end() );

	for ( int i = 0 ; i < a.size() ; i++ ){
		for ( int j = 0 ; j < b.size() ; j++ )
			if ( a[i] == b[j] )
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max ( dp[i + 1][j], dp[i][j + 1] );
	}

	cout << dp[a.size()][b.size()] << '\n';
}