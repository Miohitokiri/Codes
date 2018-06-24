#include<bits/stdc++.h>

using namespace std;

int dis[100005];

inline int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ){
	dis[find ( dis[b] )] = find ( dis[a] );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, t, a, b;
	cin >> t;
	while ( t-- ){
		cin >> n >> m;

		for ( int i = 1 ; i <= n ; i++ )
			dis[i] = i;

		while ( m-- ){
			cin >> a >> b;
			Union ( a, b );
		}

		for ( int i = 1 ; i <= n ; i++ )
			cout << find ( i ) << '\n';
	}
}