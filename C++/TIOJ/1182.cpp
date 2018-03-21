#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int t, n, m, ans;
	bool test;
	cin >> t;
	for ( int times = 0 ; times < t ; times++ ){
		// cout << 111 << endl;
		n = 0;
		m = 0;
		cin >> n >> m;
		int data[n];
		memset ( data, 0, sizeof ( data ) );
		data[0] = m;
		// cout << "222\n";
		for ( int i = 1 ; i < n ; i++ )
			cin >> data[i];
		// cout << 333 << endl;
		sort ( data, data + n );
		ans = n / 2;
		// cout << 444 << endl;
		for ( int i = 0 ; i < n ; i++ )
			if ( m == data[i] ){
				ans = i;
				break;
			}
		/*while ( data[ans] != m ){
			( data[ans] > m ) ? ans = true : ans = false;
			if ( test )
				ans = round ( ( ans + n - 1 ) / 2 );
			else
				ans = round ( ans / 2 );
		}*/
		cout << data[ans + 1] << ' ' << data[ans - 1] << endl;
	}
}