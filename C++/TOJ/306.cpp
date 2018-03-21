#include<bits/stdc++.h>
#define int 

using namespace std;

typedef pair < int, int > pii;

struct disjionSet{
	int dis[maxN];

	inline void Init ( void ){
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
} dis;

struct bridge{
	int u, v, value;
};

vector < bridge > edge;
vector < pii > mst[maxN];

inline bool cmp ( bridge a, bridge b ){
	return a.value < b.value;
}

inline void dijkstra ( void ){
	for ( auto i: edge ){
		if ( same ( i.u, i.v ) )
			continue;

		mst[i.u].push_back ( make_pair ( i.v, i.value ) );
		mst[i.v].push_back ( make_pair ( i.u, i.value ) );
		dis.Union ( i.u, i.v );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, a, b;
	bridge stop;
	cin >> n >> m >> a >> b;
	dis.Init();

	while ( m-- ){
		cin >> stop.u >> stop.v >> stop.value;
		edge.push_back ( stop );
	}

	sort ( edge.begin(), edge.end(), cmp );

	dijkstra();
}