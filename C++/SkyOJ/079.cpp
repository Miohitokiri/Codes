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
#define SP(a,b) swap ( a, b )
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
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'

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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct D1{
	int seg[maxN << 2], Index, value;

	inline void update ( int n, int l, int r ){
		if ( l == r )
			seg[n] = value;
		else{
			int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( Index <= mid )
				update ( leftSon, l, mid );
			else
				update ( rightSon, mid + 1, r );

			seg[n] = seg[leftSon] + seg[rightSon];
		}
	}

	inline int query ( int n, int l, int r, int nowL, int nowR ){
		if ( l <= nowL && nowR <= r )
			return seg[n];
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			return query ( leftSon, l, r, nowL, mid );
		else if ( mid < l )
			return query ( rightSon, l, r, mid + 1, nowR );
		else
			return query ( leftSon, l, mid, nowL, mid ) + query ( rightSon, mid + 1, r, mid + 1, nowR );
	}
} seg[maxN << 2];

int n, m;

inline D1 up ( D1 l, D1 r ){
	D1 res;
	REPP ( i, 0, ( n << 2 ) + 1 ) res.seg[i] = l.seg[i] + r.seg[i];
	return res;
}

inline void update ( int n, int l, int r, int x, int y, int value ){
	cout << l << ' ' << r << '\n';
	if ( l == r ){
		seg[n].Index = x, seg[n].value = value;
		seg[n].update ( 1, 1, m );
	}
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( y <= mid )
			update ( leftSon, l, mid, x, y, value );
		else
			update ( rightSon, mid + 1, r, x, y, value );

		seg[n] = up ( seg[leftSon], seg[rightSon] );
	}
}

inline int query ( int n, int u, int d, int l, int r, int nowL, int nowR ){
	if ( l <= nowL && nowR <= r )
		return seg[n].query ( 1, u, d, 1, m );
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( leftSon, u, d, l, r, nowL, mid );
	else if ( mid < l )
		return query ( rightSon, u, d, l, r, mid + 1, nowR );
	else
		return query ( leftSon, u, d, l, mid, nowL, mid ) + query ( rightSon, u, d, mid + 1, r, mid + 1, nowR );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int stop;
	cin >> n >> m;
	REPP ( i, 1, n + 1 ){
		REPP ( j, 1, m + 1 ){
			cin >> stop;
			update ( 1, 1, m, i, j, stop );
		}
	}

	cout << seg[1].seg[1] << '\n';
}