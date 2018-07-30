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
#define maxN 100005
#define maxLog 20

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
	return a.w > b.w;
}

vec < node > edges;
GRE ( pii, mst );
int mi, dis[maxN], D[maxN], n;
pii dp[maxN][maxLog];

inline void init ( void ){
	REPP ( i, 0, maxN ) dis[i] = i;
}

// disjoin set
int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

// Kruskal
inline void Kruskal ( void ){
	sort ( ALL ( edges ), cmp );
	init();
	REPALL ( i, edges ){
		if ( same ( i.u, i.v ) )
			continue;
		UNIw ( i.u, i.v, i.w, mst );
		Union ( i.u, i.v );
	}
}

inline void dfs ( int d, int p, int dep ){
	D[d] = dep++;
	dp[d][0].F = p;
	REPALL ( i, mst[d] ){
		if ( i.F == p )
			continue;
		dp[i.F][0] = pii ( d, i.S );
		dfs ( i.F, d, dep );
	}
}

inline void buildLCA ( void ){
	REPP ( i, 0, n ){
		REPP ( j, 0, maxLog ){
			dp[i][j] = pii ( -1, INF );
		}
	}
	MEM ( D, 0 );
	dfs ( 0, -1, 0 );
	REPP ( k, 1, maxLog ){
		REPP ( i, 0, n ){
			if ( dp[i][k - 1].F == -1 )
				continue;
			dp[i][k].F = dp[dp[i][k - 1].F][k - 1].F;
			dp[i][k].S = min ( dp[i][k - 1].S, dp[dp[i][k - 1].F][k - 1].S );
		}
	}
}

inline void findLCA ( int x, int y ){
	mi = INF;
	if ( D[x] < D[y] )
		swap ( x, y );

	REPM ( i, maxLog - 1, 0 ){
		if ( dp[x][i].F != -1 && D[dp[x][i].F] >= D[y] ){
			mi = min ( mi, dp[x][i].S );
			x = dp[x][i].F;
		}
	}

	if ( x == y )
		return;

	REPM ( i, maxLog - 1, 0 ){
		if ( dp[x][i].F != dp[y][i].F ){
			mi = min ( mi, min ( dp[x][i].S, dp[y][i].S ) );
			x = dp[x][i].F, y = dp[y][i].F;
		}
	}

	mi = min ( mi, min ( dp[x][0].S, dp[y][0].S ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int m, u, v, w, q;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v >> w;
		edges.pb ( node { u, v, w } );
	}

	Kruskal();
	buildLCA();

	cin >> q;
	while ( q-- ){
		cin >> u >> v;
		findLCA ( u, v );
		cout << mi << '\n';
	}
}