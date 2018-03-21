// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPALL(i,n) for ( auto &i: n )

#define mp make_pair

template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define SZ(n) ( int ) n.size()
#define ALL(n) BEG ( n ), END ( n )

#define GRE(T,edge) vec < T > edge[maxN]

#define maxN 100005

// disjion Set
struct disjoinSet{
	int dis[maxN];

	inline void Init ( void ){
		REPP ( i, 0, maxN ) dis[i] = i;
	}

	inline int find ( int n ){
		return dis[n] == n ? n : dis[n] = find ( dis[n] );
	}

	inline bool same ( int a, int b ){
		return find ( a ) == find ( b );
	}

	inline void Union ( int a, int b ){
		dis[find ( a )] = find ( b );
	}
};

// edge's data
struct bridge{
	int u, v, w;
};

vec < bridge > edge;
GRE ( pii, mst );

inline bool cmp ( bridge a, bridge b ){
	return a.w < b.w;
}

inline void Kruskal ( void ){
	disjionSet dis;
	dis.Init();
	sort ( ALL ( edge ) ); // sort by weigh
	REPALL ( i, edge ){
		if ( dis.same ( i.u, i.v ) ) // check if it on the same tree
			continue;
		dis.Union ( i.u, i.v );
		mst[i.u].pb ( pii ( i.v, i.w ) );
		mst[i.v].pb ( pii ( i.u, i.w ) );
	}
}