// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define REV reverse
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 1000005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct node{
	int u, v, w;
};

inline bool cmp ( node a, node b ){
	return a.w < b.w;
}

int dis[maxN];
LL dist[maxN];
vec < node > edges;
GRE ( pii, mst );

inline void init ( void ){
	REPP ( i, 0, maxN ) dis[i] = i;
}

inline int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline void Kruskal ( void ){
	sort ( ALL ( edges ), cmp );
	REPALL ( i, edges ){
		if ( same ( i.u, i.v ) )
			continue;
		Union ( i.u, i.v );
		UNIw ( i.u, i.v, i.w, mst );
	}
}

void dfs ( int n, int p ){
	REPALL ( i, mst[n] ){
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
	// debuger;

	Kruskal();

	dfs ( 0, -1 );
	REPP ( i, 0, n )
		if ( ma < dist[i] )
			ma = dist[i], idx = i;

	dist[idx] = 0;
	dfs ( idx, -1 );
	ma = -1;
	REPP ( i, 0, n )
		ma = max ( ma, dist[i] );

	cout << ma << '\n';
}