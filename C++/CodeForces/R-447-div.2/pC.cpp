#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, i, mi = 0x3f3f3f;
	cin >> n;
	vector < int > data ( n );
	for ( i = 0 ; i < n ; i++ ){
		cin >> data[i];
		mi = min ( mi, data[i] );
	}

	for ( i = 0 ; i < n ; i++ )
		if ( data[i] % mi )
			break;

	if ( i < n )
		cout << -1 << '\n';
	else{
		cout << 2 * n - 1 << '\n' << data[1];
		for ( i = 2 ; i < n ; i++ )
			cout << ' ' << mi << ' ' << data[i];
		cout << '\n';
	}
}