#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	vector < string > data;
	set < string > lib;
	string str, stp;
	for ( int i = 0 ; i < 3 ; i++ ){
		cin >> str;
		stp = "";
		for ( auto i: str ){
			if ( 'A' <= i && i <= 'Z' )
				stp += i + 'a' - 'A';
			else if ( 'a' <= i && i <= 'z' )
				stp += i;
		}

		data.push_back ( stp );
	}

	for ( int i = 0 ; i < 3 ; i++ )
		for ( int j = 0 ; j < 3 ; j++ ){
			if ( j == i )
				continue;
			for ( int k = 0 ; k < 3 ; k++ ){
				if ( k == i || k == j )
					continue;
				lib.insert ( data[i] + data[j] + data[k] );
			}
		}

	int n;
	cin >> n;
	while ( n-- ){
		cin >> str;
		stp = "";
		for ( auto i: str ){
			if ( 'A' <= i && i <= 'Z' )
				stp += i + 'a' - 'A';
			else if ( 'a' <= i && i <= 'z' )
				stp += i;
		}

		cout << ( lib.find ( stp ) != lib.end() ? "ACC" : "WA" ) << '\n';
	}
}