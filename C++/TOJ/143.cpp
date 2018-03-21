#include<bits/stdc++.h>

using namespace std;

// #define int long long

vector < int > edge[100005];
set < int > blue, green;
bool go[100005];
// set < pair < int, int > > check;

void dfs ( int x, int size ){
	if ( go[x] )
		return;
	go[x] = true;
	if ( size & 1 )
		blue.insert ( x );
	else
		green.insert ( x );

	for ( auto i: edge[x] )
		dfs ( i, size + 1 );
}

inline void init ( int n ){
	memset ( go, 0, sizeof ( go ) );
	for ( int i = 0 ; i < n ; i++ )
		if ( !edge[i].empty() )
			edge[i].clear();
	if ( !green.empty() )
		green.clear();
	if ( !blue.empty() )
		blue.clear();
	if ( !check.empty() )
		check.clear();
}

inline bool findSame ( intw a, int b ){
	return ( blue.find ( a ) != blue.end() && blue.find ( b ) != blue.end() ) || ( green.find ( a ) != green.end() && green.find ( b ) != green.end() );
}

// #undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	// #define int long long

	int n, m, a, b;
	bool ans;
	while ( cin >> n >> m ){
		ans = true;
		init ( n );

		while ( m-- ){
			cin >> a >> b;
			edge[a].emplace_back ( b );
			edge[b].emplace_back ( a );
		}

		dfs ( 0, 1 );

		for ( int i = 0 ; i < n && ans ; i++ )
			for ( auto j: edge[i] ){
				// if ( check.find ( make_pair ( i, j ) ) != check.end() )
				// 	continue;
				// check.insert ( make_pair ( i, j ) ), check.insert ( make_pair ( j, i ) );
				if ( findSame ( i, j ) ){
					ans = false;
					break;
				}
			}

		cout << ( ans ? "YES" : "NO" ) << '\n';
	}
}