#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, mi;
	vector < int > data;
	while ( cin >> n ){
		data.resize ( n );
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];
		sort ( data.begin(), data.end() );
		mi = 0x3f;
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < i ; j++ )
				for ( int k = 0 ; k < j ; k++ )
					if ( data[j] + data[k] > data[i] ){
						mi = min ( data[i] + data[j] + data[k], mi );
						break;
					}

		cout << mi << '\n';
	}
}