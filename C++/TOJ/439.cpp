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
#define maxN 10005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

struct node{
	int u, v, w;
};

inline bool cmp ( node a, node b ){
	return a.w < b.w;
}

vec < node > edges;
GRE ( pii, mst );
int t, dis[maxN], sum;

inline void init ( int n ){
	REPP ( i, 0, n ) dis[i] = i;
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

void dfs ( int n, int p, int ma ){
	if ( n == t ){
		sum = ma;
		return;
	}
	REPALL ( i, mst[n] ){
		if ( i.F == p )
			continue;
		dfs ( i.F, n, max ( ma, i.S ) );
	}
}

inline void Kruskal ( int n, int s ){
	sort ( ALL ( edges ), cmp );
	init ( n );
	vec < node > unused;
	REPALL ( i, edges ){
		if ( same ( i.u, i.v ) ){
			unused.pb ( i );
			continue;
		}
		UNIw ( i.u, i.v, i.w, mst );
		Union ( i.u, i.v );
	}
	dfs ( s, -1, -1 );
	UNIw ( unused[0].u, unused[0].v, unused[0].w, mst );
	cout << sum << ' ' << sum << '\n';
	sum = 0;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, s, u, v, w;
	cin >> n >> m >> s >> t;
	REPP ( i, 0, m ){
		cin >> u >> v >> w;
		edges.pb ( node { u, v, w } );
	}

	bool tf = true;
	REPP ( i, 0, m ){
		if ( edges[i].w != edges[i - 1].w )
			tf = false;
	}

	if ( tf ){
		cout << edges[0].w << ' ' << edges[0].w << '\n';
		return 0;
	}
	Kruskal ( n, s );
}