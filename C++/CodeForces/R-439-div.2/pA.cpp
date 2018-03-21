#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, in, stop, count = 0;
	vector < int > data, x, y;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		data.push_back ( in );
		x.push_back ( in );
	}

	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		data.push_back ( in );
		y.push_back ( in );
	}

	sort ( data.begin(), data.end() );

	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < n ; j++ ){
			stop = x[i] ^ y[j];
			upper_bound ( data.begin(), data.end(), stop ) - lower_bound ( data.begin(), data.end(), stop ) ? count++ : count;
		}

	cout << ( count & 1 ? "Koyomi" : "Karen" ) << '\n';
}