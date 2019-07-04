// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

const int maxN = 100005;

vector < int > edges[maxN];
int parent[maxN], D[maxN];

void dfs ( int n, int p ){
	parent[n] = p;
	D[n] = D[p] + 1;
	for ( auto i: edges[n] ){
		if ( i == p )
			continue;
		dfs ( i, n );
	}
}

inline void build ( void ){
	dfs ( 1, 1 );
}

inline int LCA ( int u, int v ){
	if ( D[u] > D[v] )
		swap ( u, v );
	while ( D[u] != D[v] )
		v = parent[v];
	while ( u != v )
		u = parent[u], v = parent[v];
	return u;
}