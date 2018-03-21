#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, ma, ans, data[100005];
	while ( cin >> n ){
		REPP ( i, 0, n ) cin >> data[i];
		ans = 0, ma = -1;
		REPM ( i, n - 1, 0 )
			if ( ma < data[i] ){
				ma = data[i];
				ans++;
			}

		cout << ans << '\n';
	}
}