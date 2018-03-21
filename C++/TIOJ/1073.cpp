#include<bits/stdc++.h>
using namespace std;

int data[9][9];
bool tf[9][9];
inline void dfs ( int x, int y ){
	tf[x][y] = true;
	for ( int i = -1 ; i < 2 ; i++ ){
		for ( int j = -1 ; j < 2 ; j++ ){
		}
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, m;
	char stop;
	cin >> t;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> n >> m;
		memset ( data, 0, sizeof ( data ) );
		memset ( tf, 0, sizeof ( tf ) );
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < m ; j++ ){
				stop = getchar();
				if ( stop = '_' )
					continue;
				data[i][j] = atoi ( stop );
				tf[i][j] = true;
			}
	}
}