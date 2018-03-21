#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, k;
	while ( cin >> n >> k ){
		if ( n == k || !k ){
			cout << "0 0\n";
			continue;
		}

		cout << "1 " << ( k >= ( n + 2 ) / 3 ? n - k : 2 * k ) << '\n';
	}
}