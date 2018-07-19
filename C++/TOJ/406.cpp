// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

long long dp[5][10];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	long long n, x, y, z, w, ans = 0;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> w >> x >> y >> z;
		dp[w][x * 4 + y * 2 + z]++;
	}

	for ( int i = 0 ; i < 8 ; i++ )
		for ( int j = 0 ; j < 8 ; j++ )
			for ( int k = 0 ; k < 8 ; k++ )
				if ( ( i | j | k ) == 7 )
					ans += dp[1][i] * dp[2][j] * dp[3][k];

	cout << ans << '\n';
}