#include<bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	short n, q, fid;
	cin >> n >> q;
	set < short > problly, stop;

	problly.insert ( 0 );
	for ( short i = 0 ; i < n ; i++ ){
		cin >> fid;

		for ( auto j = problly.begin() ; j != problly.end() ; j++ ){
			stop.insert ( *j + fid );
			stop.insert ( *j - fid );
		}

		problly.clear();
		swap ( problly, stop );
	}

	while ( q-- ){
		cin >> fid;
		cout << *lower_bound ( problly.begin(), problly.end(), fid ) << '\n';
	}
}