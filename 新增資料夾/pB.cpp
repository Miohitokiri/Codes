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
#define maxN 20005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

map < pii, int > dist;
map < pii, LL > g;
LL bit[maxN];
int sz;

inline void add ( int x, LL value ){
	while ( x <= sz ){
		bit[x] += value;
		x += x & -x;
	}
}

inline LL query ( int x ){
	int res = 0;
	while ( x ){
		res += bit[x];
		x -= x & -x;
	}
	
	return res;
}

void dfs ( int x, int y, int dep ){
	if ( dist[pii ( x, y )] != -1 ) return;
	if ( g[pii ( x, y )] == -1 ) return;
	dist[pii ( x, y )] = dep++;
	dfs ( x + 1, y, dep );
	dfs ( x, y + 1, dep );
	dfs ( x - 1, y, dep );
	dfs ( x, y - 1, dep );
	sz = max ( dep, sz );
}

int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

	int n, m, q, u, v, x, y, w, in;
	cin >> n >> m >> q >> x >> y;
	for ( int i = 0 ; i <= n + 1 ; i++ ){
		for ( int j = 0 ; j <= m + 1 ; j++ ){
			dist[pii ( i, j )] = -1;
			g[pii ( i, j )] = -1;
		}
	}
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 1 ; j <= m ; j++ ){
			cin >> in;
			g[pii ( i, j )] = in;
		}
	}
	dfs ( x, y, 1 );
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 1 ; j <= m ; j++ ){
			if ( dist[pii ( i, j )] == -1 ) continue;
			add ( dist[pii ( i, j )], g[pii ( i, j )] );
		}
	}

	sz += 2;
	
	while ( q-- ){
		int type;
		cin >> type;
		if ( type == 1 ){
			cin >> u >> v >> w;
			if ( dist[pii ( u, v )] > 0 && !( u == x && v == y ) ){
				add ( dist[pii ( u, v )], w - g[pii ( u, v )] );
				g[pii ( u, v )] = w;
			}
		}
		else{
			cin >> u;
			int l, r, mid;
			l = 1, r = sz + 1, mid = ( l + r ) >> 1;
			while ( r - l > 1 ){
				mid = ( l + r ) >> 1;
				if ( query ( mid ) <= u ) l = mid;
				else r = mid;
			}
			mid = ( l + r ) >> 1;
			while ( query ( mid ) > u )
				mid--;
		
			cout << mid - 1 << '\n';
		}
	}
}