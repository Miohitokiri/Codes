#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, data[10][10], n, ma, x, y;
	cin >> t;
	while ( t-- ){
		n = 8;
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; < n ; j++ )
				cin >> data[i][j];

		while ( n-- ){
			ma = 0;
			for ( int i = 0 ; i < 8 ; i++ )
				for ( int j = 0 ; j < 8 ; j++ )
					if ( ma < data[i][j] )
						x = i, y = j, ma = data[i][j];

			ans += ma;
			data[x][y] = 0;
			for ( int i = 0 ; i < 8 ; i++ )
				data[i][y] = data[x][i] = 0;
		}
	}
}