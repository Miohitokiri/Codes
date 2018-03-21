#include<bits/stdc++.h>

using namespace std;

vector < string > data[1000005];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, q, x1, x2, y1, y2;
	string stop;
	char type;
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ ){
			cin >> stop;
			data[i].push_back ( stop );
		}

	cin >> q;
	while ( q-- ){
		cin >> type >> x1 >> y1;
		x1--, y1--;
		if ( type == 'S' ){
			cin >> x2 >> y2;
			x2--, y2--;
			if ( x1 == x2 && y1 == y2 )
				continue;
			swap ( data[x1][y1], data[x2][y2] );
		}
		else if ( type == 'R' && x1 != y1 && x1 != y1 )
			swap ( data[x1], data[y1] );
		else if ( x1 != y1 )
			for ( int i = 0 ; i < n ; i++ )
				swap ( data[i][x1], data[i][y1] );
	}

	for ( int i = 0 ; i < n ; i++ ){
		cout << data[i][0];
		for ( int j = 1 ; j < m ; j++ )
			cout << ' ' << data[i][j];
		cout << '\n';
	}
}