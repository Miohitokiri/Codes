// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

int dp[105][105], ma;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string a, b, str;
	set < string > lib;
	while ( cin >> a >> b ){
		int szA = a.size(), szB = b.size();
		lib.clear();
		memset ( dp, 0, sizeof dp );
		ma = 0;
		for ( int i = 0 ; i < szA ; i++ ){
			for ( int j = 0 ; j < szB ; j++ ){
				if ( a[i] == b[j] ){
					dp[i + 1][j + 1] = dp[i][j] + 1;
					ma = max ( ma, dp[i + 1][j + 1] );
				}
			}
		}
		if ( !ma ){
			cout << "No common sequence!\n";
			continue;
		}
		for ( int i = 0 ; i < szA ; i++ ){
			for ( int j = 0 ; j < szB ; j++ ){
				if ( dp[i + 1][j + 1] == ma ){
					str = "";
					for ( int k = i - ma + 1 ; k <= i ; k++ )
						str += a[k];
					lib.insert ( str );
				}
			}
		}
		for ( auto i: lib )
			cout << i << '\n';
	}
}