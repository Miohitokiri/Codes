// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define maxN 100005

struct bridge{
	int u, v, w;
};

struct disjionSet{
	int dis[maxN];

	inline void Init ( void ){
		for ( int i = 0 ; i < maxN ; i++ )
			dis[i] = i;
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

vector < bridge > edges;

inline bool cmp ( bridge a, bridge b ){
	return a.w < b.w;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, k, u, v, w, ub = 0, lb = 0;
	disjionSet dis;
	cin >> n >> m >> k;
	while ( m-- ){
		cin >> u >> v >> w;
		edges.push_back ( bridge { u, v, w } );
	}

	sort ( edges.begin(), edges.end(), cmp );
	dis.Init();
	for ( auto i: edges ){
		if ( dis.same ( i.u, i.v ) )
			continue;

		dis.Union ( i.u, i.v );
		lb += i.w;
	}


	reverse ( edges.begin(), edges.end() );
	dis.Init();
	for ( auto i: edges ){
		if ( dis.same ( i.u, i.v ) )
			continue;

		dis.Union ( i.u, i.v );
		ub += i.w;
	}

	cout << ( lb <= k && k <= ub ? "TAK" : "NIE" ) << '\n';
}