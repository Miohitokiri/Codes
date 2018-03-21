#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, m, cnt;
	char board[55][55], stop;
	set < char > data;
	cin >> t;
	while ( t-- ){
		cin >> n;
		data.clear();
		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			data.insert ( stop );
		}
		cnt = 0;

		cin >> n >> m;
		memset ( board, 0, sizeof board );
		for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j < m ; j++ ) cin >> board[i][j];

		for ( int i = 0 ; i < n - 2 && !cnt ; i++ ) for ( int j = 0 ; j < m && !cnt ; j++ ) if ( board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && data.find ( board[i][j] ) != data.end() ) cnt++;

		for ( int i = 0 ; i < n && !cnt ; i++ ) for ( int j = 0 ; j < m - 2 && !cnt ; j++ ) if ( board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && data.find ( board[i][j] ) != data.end() ) cnt++;

		cout << ( cnt ? "Attack!" : "Loser!" ) << '\n';
	}
}