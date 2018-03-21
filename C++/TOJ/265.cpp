#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

#define int long long

int dis[45005], size[45005], ans[2000005];
vector < pair < int, pair < int, int > > > edge;

inline int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ){
	a = find ( a ), b = find ( b );
	dis[a] = b;
	size[b] += size[a];
}

inline void Init ( int n ){
	for ( int i = 1 ; i <= n ; i++ )
		dis[i] = i, size[i] = 1;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m, q, u, v, w, now = 0;
	cin >> n >> m >> q;

	Init ( n );

	for ( int i = 0 ; i < m ; i++ ){
		cin >> u >> v >> w;
		edge.push_back ( make_pair ( w, make_pair ( u, v ) ) );
	}

	sort ( edge.begin(), edge.end() );

	for ( auto i: edge ){
		u = i.y.x, v = i.y.y, w = i.x;
		if ( find ( u ) == find ( v ) )
			continue;
		ans[w] += ( long long ) size[find ( u )] * size[find ( v )] * 2;
		Union ( u, v );
	}

	for ( int i = 1 ; i <= 1000000 ; i++ )
		ans[i] += ans[i - 1];

	while ( q-- ){
		cin >> w;
		cout << ans[w] << '\n';
	}
}