#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, mi, data[30];
	string last;
	char ans;
	cin >> n;
	while ( n-- ){
		memset ( data, 0, sizeof data );
		cin >> mi;
		getline ( cin, last );
		for ( auto i: last )
			if ( i != ' ' )
				data[i - 97]++;

		mi = 10000;
		for ( int i = 25 ; i >= 0 ; i-- )
			if ( data[i] < mi && data[i] )
				ans = i + 97, mi = data[i];

		cout << ans << ' ' << mi << '\n';
	}
}