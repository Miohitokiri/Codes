#include<bits/stdc++.h>

using namespace std;

vector < int > dp[500005][500005];

inline void Init ( int n, int m ){
	for ( int i = 0 ; i <= n ; i++ )
		for ( int j = 0 ; j <= m ; j++ )
			if ( !dp[i][j].empty() )
				dp[i][j].clear();
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, stop, m;
	set < int > ansData;
	vector < int > boy, girl, same;
	cin >> t;
	while ( t-- ){
		cin >> n;
		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			boy.emplace_back ( stop );
		}
		cin >> m;
		for ( int i = 0 ; i < m ; i++ ){
			cin >> stop;
			girl.emplace_back ( stop );
		}

		Init ( n, m );

		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < m ; j++ )
				if ( boy[i] == girl[j] ){
					dp[i + 1][j + 1] = dp[i][j];
					dp[i + 1][j + 1].push_back ( boy[i] );
				}
				else
					dp[i + 1][j + 1] = ( dp[i][j + 1].size() > dp[i + 1][j].size() ? dp[i][j + 1] : dp[i + 1][j] );

		if ( dp[n][m].empty() ){
			boy.clear(), girl.clear();
			continue;
		}
		sort ( dp[n][m].begin(), dp[n][m].end() );
		same = dp[n][m];
		for ( int i = 0 ; i < n ; i++ ){
			if ( boy[i] > *( same.end() - 1 ) ){
				ansData.insert ( boy[i] );
				continue;
			}
			if ( same.empty() )
				break;
			auto x = lower_bound ( same.begin(), same.end(), boy[i] );
			if ( *x == boy[i] )
				same.erase ( x );
			else
				ansData.insert ( boy[i] );
		}

		same = dp[n][m];
		for ( int i = 0 ; i < m ; i++ ){
			if ( girl[i] > *( same.end() - 1 ) ){
				ansData.insert ( girl[i] );
				continue;
			}
			if ( same.empty() )
				break;
			auto x = lower_bound ( same.begin(), same.end(), girl[i] );
			if ( *x == girl[i] )
				same.erase ( x );
			else
				ansData.insert ( girl[i] );
		}

		boy.clear();
		girl.clear();
		if ( !same.empty() )
			same.clear();
	}

	cout << ansData.size() << '\n';
}