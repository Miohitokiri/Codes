#include<bits/stdc++.h>

using namespace std;

vector < string > data;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	string stop;
	while ( cin >> n && n ){
		if ( !data.empty() )
			data.clear();

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			data.push_back ( stop );
		}
	}
}