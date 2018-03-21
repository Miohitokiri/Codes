#include<bits/stdc++.h>

using namespace std;

string str;

inline bool solve ( int l, int r, bool t ){
	if ( l == r )
		return true;
	if ( str[l] == str[r] )
		return solve ( l + 1, r - 1, t );
	else{
		if ( !t )
			return false;
		else
			return !solve ( l, r - 1, true ) || !solve ( l + 1, r, true );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	string stop;
	cin >> n;
	while ( n-- ){
		stop = "";
		cin >> str;
		for ( int i = str.size() - 1 ; i >= 0 ; i-- )
			stop += str[i];
		cout << ( solve ( 0, str.size() - 1, 0 ) || stop == str ? "YES" : "NO" ) << '\n';
	}
}