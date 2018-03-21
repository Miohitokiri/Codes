#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	string a, b, dba, dbb;
	int x, y;
	while ( cin >> a >> b ){
		dba = dbb = "";
		for ( int i = 0 ; i < a.size() ; i++ ){
			if ( a[i] == '.' )
				break;
			dba += a[i], x++;
		}
		for ( int i = 0 ; i < b.size() ; i++ ){
			if ( a[i] == '.' )
				break;
			dbb += b[i], y++;

		}

		// cout << dba << ' ' << dbb << '\n'; // del 
		// cout << x << ' ' << y << '\n'; // del

		if ( x != y )
			cout << ( x > y ? a : b );
		else{
			if ( dba != dbb )
				cout << ( dba > dbb ? a : b );
			else if ( a.size() != b.size() )
				cout << ( a.size() > b.size() ? a : b );
			else
				cout << ( a > b ? a : b );
		}

		cout << '\n';
	}
}