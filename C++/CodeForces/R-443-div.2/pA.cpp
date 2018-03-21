#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int s, d, ans = 0, n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> s >> d;
		while ( !( s > ans ) )
			s += d;

		ans = s;
	}

	cout << ans << '\n';
}