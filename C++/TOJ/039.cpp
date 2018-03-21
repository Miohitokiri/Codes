#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	long long ans, n;
	string i;
	while ( !cin.eof() ){
		ans = 1;
		while ( cin >> i && i != "%" ){
			n = atoi ( i.c_str() );
			ans *= n;
			ans %= 479001599;

			// cout << n << ' '; // del
		}
		// cout << '\n'; // del
		cout << ans << '\n';
	}
}