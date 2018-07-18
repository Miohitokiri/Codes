#include<bits/stdc++.h>

using namespace std;

string s;

bool solve ( int l, int r, bool t ){
	while ( l <= r ){
		if ( s[l] != s[r] )
			return t ? max ( solve ( l + 1, r, false ), solve ( l, r - 1, false ) ) : false;
		l++, r--;
	}
	return true;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t;
	cin >> t;
	while ( t-- ){
		cin >> s;
		cout << ( solve ( 0, s.size() - 1, true ) ? "YES" : "NO" ) << '\n';
	}
}