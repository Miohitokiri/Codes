#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int t, n, prime, modlue, ans, q;
	cin >> t;
	while ( t-- ){
		cin >> n;
		ans = 0, q = 1;
		while ( n-- ){
			cin >> prime >> modlue;
			if ( ans > 955049953 )
				continue;
			while ( ans % prime != modlue )
				ans += q;
			q *= prime;
		}

		cout << ( ans > 955049953 ? -1 : ans ) << '\n';
	}
}