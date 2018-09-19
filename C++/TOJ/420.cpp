// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 1000005
typedef pair < int, int > pii;
typedef long long LL;
#define pb push_back
#define F first
#define S second

struct node{
	int u, v, w;
};

inline bool cmp ( node a, node b ){
	return a.w < b.w;
}

int dis[maxN];
LL dist[maxN];
vector < node > edges;
vector < pii > mst[maxN];

inline void init ( void ){
	for ( int i = 0 ; i < maxN ; i++ )
		dis[i] = i;
}

int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline void Kruskal ( void ){
	sort ( edges.begin(), edges.end(), cmp );
	for ( auto &i: edges ){
		if ( same ( i.u, i.v ) )
			continue;
		Union ( i.u, i.v );
		mst[i.u].pb ( pii ( i.v, i.w ) );
		mst[i.v].pb ( pii ( i.u, i.w ) );
	}
}

void dfs ( int n, int p ){
	for ( auto i: mst[n] ){
		if ( i.F == p )
			continue;
		dist[i.F] = dist[n] + i.S;
		dfs ( i.F, n );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, w, t, idx, now;
	LL ma = -1;
	cin >> n >> m;
	init();
	while ( m-- ){
		cin >> u >> v >> w;
		edges.pb ( node { u, v, w } );
	}

	Kruskal();

	dfs ( 0, -1 );
	for ( int i = 0 ; i < n ; i++ )
		if ( ma < dist[i] )
			ma = dist[i], idx = i;

	dist[idx] = 0;
	dfs ( idx, -1 );
	ma = -1;
	for ( int i = 0 ; i < n ; i++ )
		ma = max ( ma, dist[i] );

	cout << ma << '\n';
}