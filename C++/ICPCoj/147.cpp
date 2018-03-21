#include<bits/stdc++.h>

using namespace std;

map < int, int > lib;
set < int > day;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, x, d, s, ans = 0;
	cin >> n >> x;
	while ( n-- ){
		cin >> d >> s;
		d += s;
		if ( day.find ( d ) == day.end() ){
			lib[d] = 0;
			day.insert ( d );
		}
		lib[d]++;
	}

	for ( auto i = lib.begin() ; i != lib.end() ; i++ )
		if ( i -> second == x )
			ans++;

	cout << ans << '\n';
}