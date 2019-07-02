// Prim
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
typedef pait < int, int > pii;
typedef pair < int, pii > pipii;
const int maxN = 100005;

vector < pii > edges[maxN], mst[maxN];
int dis[maxN];
bool pushed[maxN];

inline void init ( void ){
	for ( int i = 0 ; i < maxN ; i++ )
		dis[i] = i;
}

int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}


inline void Union ( int a, int b ){
	a = find ( a ), b = find ( b );
	dis[a] = b;
	sz[b] += sz[a];
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline void Pirm ( int n ){
	priority_queue < pipii, vector < pipii >, greater < pipii > > pq;
	for ( auto i: edges[0] )
		pq.push ( pipii ( i.S, pii ( 0, i.F ) ) );
	pushed[0] = true;
	while ( sz[find ( 0 )] != n ){
		pipii top = pq.top();
		pq.pop();
		while ( same ( top.S.F, top.S.F ) ){
			top = pq.top();
			pq.pop();
		}
		int u = top.S.F, v = top.S.S;

		mst[u].pb ( pii ( v, top.F ) );
		mst[v].pb ( pii ( u, top.F ) );
		Union ( u, v );

		if ( !pushed[u] ){
			for ( auto i: edges[u] )
				pq.push ( pipii ( i.S, pii ( i.F, u ) ) );
			pushed[u] = true;
		}
		if ( !pushed[v] ){
			for ( auto i: edges[v] )
				pq.push ( pipii ( i.S, pii ( i.F, v ) ) );
			pushed[v] = true;
		}
	}
}