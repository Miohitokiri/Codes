#include<bits/stdc++.h>

using namespace std;

#define int long long

#undef int

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int l, r, x, y, k, stop = 0;
	cin >> l >> r >> x >> y >> k;

	for ( int i = x ; i <= y ; i++ ){
		stop = k * i;
		if ( l <= stop && stop <= r ){
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}