// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

vector < int > edges[maxN];
int parent[maxN], D[maxN];

void dfs ( int n, int p, int dep ){
	D[n] = dep++;
	parent[n] = p;
	for ( auto i: edges[n] )
		if ( i != p )
			dfs ( i );
}

inline void build ( void ){
	dfs ( 1 );
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