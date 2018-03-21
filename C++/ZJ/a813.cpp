#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[1000005], data[1000005];

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, ans = 0, ma = -1;
	while ( cin >> n ){
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];

		for ( int i = 0 ; i < n ; i++ ){
			// l
			ma = -1;
			for ( int j = 0 ; j < i ; j++ ){
				if ( ma <= data[j] )
					ans++, ma = data[j];
			}

			// r
			ma = -1;
			for ( int j = i + 1 ; j < n ; j++ ){
				if ( ma <= data[j] )
					ans++, ma = data[j];
			}
		}

		cout << ans << '\n';
	}
}