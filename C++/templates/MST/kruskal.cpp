// Kruskal
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 10005
#define pb push_back
typedef pair < int, int > pii;

int dis[maxN];

inline void init ( void ){
	for ( int i = 0 ; i < maxN ; i++ )
		dis[i] = i;
}

inline int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

struct node{
	int u, v, w;
};

inline bool cmp ( node a, node b ){
	return a.w < b.w;
}

vector < node > edges;
vector < pii > mst[maxN];

inline void Kruskal ( void ){
	sort ( edges.begin(), edges.end(), cmp );
	for ( auto i: edges ){ // C++ 11寫法，不懂再來問
		if ( same ( i.u, i.v ) )
			continue;
		Union ( i.u, i.v );
		mst[i.u].pb ( pii ( i.v, i.w ) );
		mst[i.v].pb ( pii ( i.u, i.w ) );
	}
}