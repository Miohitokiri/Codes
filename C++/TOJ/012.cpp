#include<bits/stdc++.h>
#define maxN 3005

using namespace std;

int bit[maxN][maxN], basic[maxN][maxN], n, m, value;

inline void add ( int i, int y ){
	while ( i <= n ){
		for ( int j = y ; j <= m ; j += j & -j )
			bit[i][j] += value;
		i += i & -i;
	}
}

inline int query ( int i, int y ){
	int re = 0;
	while ( i ){
		for ( int j = y ; j ; j -= j & -j )
			re += bit[i][j];
		i -= i & -i;
	}
	return re;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		for ( int j = 1 ; j <= m ; j++ ){
			cin >> value;
			add ( i, j );
			basic[i][j] = value;
		}

	int q, x1, x2, y1, y2;
	char type;
	cin >> q;
	while ( q-- ){
		cin >> type;
		if ( type == 'C' ){
			cin >> x1 >> y1 >> value;
			value -= basic[x1][y1];
			add ( x1, y1 );
			basic[x1][y1] += value;
		}
		else{
			cin >> x1 >> y1 >> x2 >> y2;
			if ( x1 > x2 )
				swap ( x1, x2 );
			if ( y1 > y2 )
				swap ( y1, y2 );
			x1--, y1--;

			cout << query ( x2, y2 ) - query ( x1, y2 ) - query ( x2, y1 ) + query ( x1, y1 ) << '\n';
		}
	}
}