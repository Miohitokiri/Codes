#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, ma = 0xffffffff;
	bool ans = true;
	vector < int > data;
	cin >> n;
	data.resize ( n );
	for ( int i = 0 ; i < n ; i++ ){
		cin >> data[i];
		mi = min ( mi, data[i] );
	}

	for ( auto i: data )
		if ( data % mi )
			ans = false;

	if ( ans )
		cout << 0 << '\n';
	else{
		cout << data.size() * 2 << '\n';
		for ( auto i: data )
			cout << i << ' ' << mi << ' ';
		cout << '\n';
	}
}