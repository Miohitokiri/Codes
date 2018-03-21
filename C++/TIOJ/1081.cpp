#include<bits/stdc++.h>

using namespace std;

bool data[1005][1005];

void chang ( string s, int j ){
	for ( int i = 0 ; i < s.size() ; i++ )
		data[i + 1][j] = ( s[i] == '1' );
}

void dfs ( int x, int y ){
	data[x][y] = false;

	for ( int i = -1 ; i < 2 ; i++ )
		for ( int j = -1 ; j < 2 ; j++ )
			if ( data[x + i][y + j] )
				dfs ( x + i, y + j );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, ans;
	string s;
	while ( cin >> n >> m ){
		if ( !n && !m )
			break;

		// cout << n << ' ' << m << '\n';
		ans = 0;
		memset ( data, 0, sizeof ( data ) );

		for ( int i = 1 ; i <= n ; i++ ){
			cin >> s;
			// cout << s << '\n';
			chang ( s, i );
		}

		for ( int i = 0 ; i <= n ; i++ )
			for ( int j = 0 ; j <= m ; j++ )
				if ( data[j][i] )
					dfs ( j, i ), ans++;

		cout << ans << '\n';
	}
}