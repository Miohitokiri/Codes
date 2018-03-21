#include<bits/stdc++.h>
using namespace std;
bool data[200][200];
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, m, a, b;
	bool ans;
	while ( cin >> n ){
		if ( !n )
			break;
		cin >> m;
		ans = false;
		memset ( data, 0, sizeof ( data ) );
		for ( int times  = 0 ; times < m ; times++ ){
			cin >> a >> b;
			data[a][b] = true;
		}

		cout << ( ( ans ) ? "" : "NOT " ) << "BICOLORABLE.\n";
	}
}