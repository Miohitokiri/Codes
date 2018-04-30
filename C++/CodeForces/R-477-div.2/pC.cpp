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

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

si L, E;

inline int elev ( int x1, int y1, int x2, int y2, int v ){
	assert ( y1 <= y2 );
	int res = INF, up = ( abs ( x2 - x1 ) + v - 1 ) / v; 
	auto it = E.lower_bound ( y1 );
	if ( it != END ( E ) ){
		int p = *it;
		if ( y1 <= p && p <= y2 )
			res = min ( res, y2 - y1 + up );
		else
			res = min ( res, y2 - y1 + up + 2 * ( p - y2 ) );
	}
	if ( it != BEG ( E ) ){
		int p = *prev ( it );
		res = min ( res, y2 - y1 + up + 2 * ( y1 - p ) );
	}

	return res;
}

inline int stai ( int x1, int y1, int x2, int y2 ){
	assert ( y1 <= y2 );
	int res = INF, up = abs ( x1 - x2 );
	auto it = L.lower_bound ( y1 );
	if ( it != END ( L ) ){
		int p = *it;
		if ( y1 <= p && p <= y2 )
			res = min ( res, y2 - y1 + up );
		else
			res = min ( res, y2 - y1 + up + 2 * ( p - y2 ) );
	}
	if ( it != BEG ( L ) ){
		int p = *prev ( it );
		res = min ( res, y2 - y1 + up + 2 * ( y1 - p ) );
	}

	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, l, e, v, q, x1, x2, y1, y2, in;
	cin >> n >> m >> l >> e >> v;
	REPP ( i, 0, l ){
		cin >> in;
		L.insert ( in );
	}
	REPP ( i, 0, e ){
		cin >> in;
		E.insert ( in );
	}

	int cnt = 0;
	cin >> q;
	while ( q-- ){
		cin >> x1 >> y1 >> x2 >> y2;
		if ( y1 > y2 )
			swap ( y1, y2 ), swap ( x1, x2 );
		if ( x1 == x2 )
			cout << abs ( y1 - y2 ) << '\n';
		else
			cout << min ( elev ( x1, y1, x2, y2, v ), stai ( x1, y1, x2, y2 ) ) << '\n';
	}
}