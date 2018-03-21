#include<iostream>
using namespace std;

char data[100][100];
int n, m, ans;
void dfs ( int, int );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	
	while ( cin >> n >> m ){
		if ( !n && !m )
			break;

		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < m ; j++ )
				cin >> data[i][j];


		ans = 0;
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < m ; j++ )
				if ( data[i][j] == '@' ){
					ans++;
					dfs ( i, j );
				}

		cout << ans << '\n';
	}
}

void dfs ( int x, int y ){
	data[x][y] = '*';

	int nx, ny;

	for ( int dx = -1 ; dx <= 1 ; dx++ ){
		nx = dx + x;

		if ( nx < 0 || nx >= n )
			continue;

		for ( int dy = -1 ; dy <= 1 ; dy++ ){
			ny = dy + y;

			if ( ny < 0 || ny >= m )
				continue;

			if ( data[nx][ny] != '@' )
				continue;

			dfs ( nx, ny );
		}
	}
}