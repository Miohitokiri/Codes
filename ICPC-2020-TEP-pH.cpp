#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back
#define F first
#define S second
typedef pair < int, int > pii;

struct node {
	int u, v, w;
};

int value[maxN], dis[maxN];
vector < pii > mst[maxN];
vector < node > edges;
bitset < maxN > used;

inline bool cmpMA ( node a, node b ) {
	return value[a.w] > value[b.w];
}

inline bool cmpMI ( node a, node b ) {
	return value[a.w] < value[b.w];
}

// dsu
inline void init ( int n ) {
	for ( int i = 0 ; i < n ; i++ )
		dis[i] = i;
}

int find ( int n ) {
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ) {
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ) {
	return find ( a ) == find ( b );
}

int dfs ( int n, int p ) {
	int res = 1;
	for ( auto [to, id]: mst[n] ) {
		if ( to == p || used[id] )
			continue;
		res += dfs ( to, n );
	}
	return res;
}

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, mi = 0x3f3f3f3f;
	vector < int > choose;
	cin >> n >> m;
	for ( int i = 0, u, v ; i < m ; i++ ) {
		cin >> u >> v >> value[i];
		edges.pb ( node { u, v, i } );
	}

	// kruskal ma
	init ( n );
	sort ( edges.begin(), edges.end(), cmpMA );
	for ( auto [u, v, w]: edges ) {
		if ( same ( u, v ) )
			continue;
		Union ( u, v );
		mi = min ( value[w], mi );
	}

	// kruskal mi
	init ( n );
	sort ( edges.begin(), edges.end(), cmpMI );
	for ( auto [u, v, w]: edges ) {
		if ( same ( u, v ) || value[w] < mi )
			continue;
		Union ( u, v );
		mst[u].pb ( pii ( u, w ) );
		mst[v].pb ( pii ( v, w ) );
		choose.pb ( w );
	}

	long long ans = 0;
	for ( auto i: choose ) {
		ans += dfs ( edges[i].u, edges[i].v ) * dfs ( edges[i].v, edges[i].u ) * value[i];
		used[i] = true;
	}
	
	cout << ans << endl;
}
