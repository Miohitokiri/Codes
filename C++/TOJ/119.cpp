#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, a, b, data[200005], t;
	bool out = true;
	cin >> n;
	for ( long long i = 1 ; i <= n ; i++ )
		cin >> data[i];

	cin >> t;
	while ( t-- ){
		cin >> a >> b;
		if ( fabs ( a - b ) > 8 )
			out = false;
		else if ( out )
			swap ( data[a], data[b] );
	}
	cout << ( out ? "SORTED!" : "I QUIT!" ) << '\n' << data[1];
	for ( long long i = 2 ; i <= n ; i++ )
		cout << ' ' << data[i];
	cout << '\n';
}