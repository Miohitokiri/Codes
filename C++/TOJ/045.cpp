#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	short h, d, in;
	cin >> h;
	vector < short > data;
	while ( h-- ){
		cin >> d;
		while ( d-- ){
			cin >> in;
			data.push_back ( in );
		}

		sort ( data.begin(), data.end() );
		cout << ( data[data.size() - 1] - data[0] ) << '\n';
		data.erase ( data.begin() );
		data.erase ( ( data.end() - 1 ) );
	}
}