#include<bits/stdc++.h>
using namespace std;
long long data[100005];
int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );
	
	long long n, t, ma, ans, mi, w, a, b;
	cin >> t;
	while ( t-- ){
		cin >> n;
		n *= 2;
		ma = 0;
		mi = 0;
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];

		sort ( data, data + n );

		for ( int i = 0 ; i < n / 2 ; i++ )
			ma += data[n - i - 1] - data[i];

		for ( int i = 0 ; i < n ; i++ )
			if ( i % 2 == 0 )
				mi -= data[i];
			else
				mi += data[i];

		cout << mi << ' ' << ma << '\n';
	}
}