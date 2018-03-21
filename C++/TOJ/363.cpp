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
#define FID(n,Index) n.find ( Index ) != n.end()

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
#define maxN 1005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct bir{
	int u, v, w;
};

inline bool cmp ( bir a, bir b ){
	return a.w < b.w;
}

vec < bir > edges;
GRE ( pii, mst );
int dis[maxN], maGRA, U, V;

inline int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	dis[find ( a ) ] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline void erase ( int a, int b ){
	int x;
	for ( x = 0 ; x < SZ ( mst[a] ) ; x++ )
		if ( mst[a][x].F == b )
			break;
	mst[a].erase ( BEG ( mst[a] ) + x );

	for ( x = 0 ; x < SZ ( mst[b] ) ; x++ )
		if ( mst[b][x].F == a )
			break;
	mst[b].erase ( BEG ( mst[b] ) + x );
}

inline bool dfs ( int n, int p, int Index ){
	if ( n == Index )
		return true;

	REPALL ( i, mst[n] ){
		if ( i.F == p )
			continue;
		if ( dfs ( i.F, n, Index ) ){
			if ( maGRA < i.S ){
				maGRA = i.S;
				U = i.F, V = n;
			}
			return true;
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	REPP ( i, 0, maxN ) dis[i] = i;

	int n, m, basic = 0, now = 0, mi, nxt, u, v, ans = INF;
	si unUsed;
	bir stop;
	cin >> n >> m;
	REPP ( i, 0, m ){
		cin >> stop.u >> stop.v >> stop.w;
		edges.pb ( stop );
		if ( i < n )
			basic += stop.w;
	}
	cout << basic << '\n';

	REPP ( i, 0, m ) unUsed.insert ( i );

	sort ( ALL ( edges ), cmp );
	REPP ( i, 0, m ){
		if ( same ( edges[i].u, edges[i].v ) )
			continue;
		unUsed.erase ( i );
		Union ( edges[i].u, edges[i].v );
		UNIw ( edges[i].u, edges[i].v, edges[i].w, mst );
		now += edges[i].w;
	}
	cout << now << '\n'; // del

	while ( !EMP ( unUsed ) ){
		mi = INF;
		REPALL ( i, unUsed ){
			maGRA = -1;
			dfs ( edges[i].u, -1, edges[i].v );
			maGRA = edges[i].w - maGRA;
			if ( mi > maGRA ){
				mi = maGRA;
				nxt = i;
				u = U, v = V;
			}
		}

		unUsed.erase ( nxt );
		now += mi;
		cout << now << '\n'; // del
		erase ( u, v );
		UNIw ( edges[nxt].u, edges[nxt].v, edges[nxt].w, mst );
		if ( basic > now )
			ans = min ( ans, basic - now );
	}

	cout << ans << '\n';
}