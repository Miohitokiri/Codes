#include<bits/stdc++.h>
using namespace std;
int n;
bool data[800][800];
bool dfs ( int a, int b ){
	bool stop;
	for ( int i = 0 ; i < n ; i++ )
		if ( data[a][i] ){
			stop = false;
			if ( i == b )
				return true;
			else
				return dfs ( i, b );
		}
}
int main(){
	bool ans;
	int m, a, b, stop;
	while ( true ){
		scanf ( "%d%d", &n, &m );
		memset ( data, 0, sizeof ( data ) );
		for ( int i = 0 ; i < m ; i++ ){
			scanf ( "%d%d", &a, &b );
			a--;
			b--;
			data[a][b] = true;
		}
		scanf ( "%d%d", &a, &b );
		ans = dfs ( a, b );
		if ( ans )
			printf ( "Yes!!!\n" );
		else
			printf ( "No!!!\n" );
	}
}