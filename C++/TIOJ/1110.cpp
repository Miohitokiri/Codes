#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, k, ma;
	string str;
	cin >> t;
	while ( t-- ){
		cin >> k >> str;
		ma = 0;
		map < char, int > lib;

		for ( auto i: str )
			lib[i]++;

		for ( auto i = lib.begin() ; i != lib.end() ; i++ )
			ma = max ( ma, i -> second );
		for ( auto i = lib.begin() ; i != lib.end() ; i++ )
			if ( ma == i -> second )
				cout << i -> first;

		cout << '\n';
	}
}