#include<bits/stdc++.h>

using namespace std;

bool mp[2147483647][2147483647], stop[2147483647][2147483647];
map < int, int > small;

inline void dfs ( int x, int y ){
	mp[x][y] = false;
	if ( mp[x][y + 1] )
		dfs ( x, y + 1 );
	if ( mp[x][y - 1] )
		dfs ( x, y - 1 );
	if ( mp[x + 1][y] )
		dfs ( x + 1, y );
	if ( mp[x - 1][y] )
		dfs ( x - 1, y );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, x, y, yes, no, maxX, maxY;
	while ( cin >> n ){
		memset ( mp, 0, sizeof mp );
		yes = no = 0;
		maxX = maxY = -1;
		for ( int i = 0 ; i < 2147483647 ; i++ )
			for ( int j = 0 ; j < 2147483647 ; j++ )
				stop[i][j] = true;

		while ( n-- ){
			cin >> x >> y;
			mp[x][y] = true;
			stop[x][y] = false;
			maxX = max ( maxX, x );
			maxY = max ( maxY, y );
		}

		for ( int i = 0 ; i <= maxX ; i++ ){
			for ( int j = 0 ; j < maxY ; j++ ){
				if ( mp[i][j] ){
					yes++;
					dfs ( i, j );
				}
				if ( stop[x][y] ){
					no++;
					dfs ( i, j );
				}
			}
		}
	}
}