#include<bits/stdc++.h>

using namespace std;

set < int > undo;

inline void Init ( int n ){
	undo.clear();
	for ( int i = 2 ; i < n ; i++ )
		undo.insert ( i );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, cnt = 0;
	vector < int > data;
	while ( cin >> n ){
		if ( cnt )
			cout << '\n';
		cout << "Case " << ++cnt << ":\n";
		data.resize ( n );
		data[0] = 1;
		Init ( n );

		for ( int i = 2 ; i <= n ; i++ ){
		}
	}
}