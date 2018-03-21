#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int ans = 0, n, p = -1, stop;
	cin >> n;
	while ( n-- ){
		cin >> stop;
		if ( stop == p )
			continue;
		ans++;
		p = stop;
	}
	cout << ans << '\n';
}