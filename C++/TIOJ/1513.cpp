#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, stop, ans;
	while ( cin >> n ){
		ans = 0;
		while ( n-- ){
			cin >> stop;
			ans ^= stop;
		}

		cout << ans << '\n';
	}
}