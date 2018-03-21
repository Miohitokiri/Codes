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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct D1{
	int seg[maxN << 2], basic[maxN], sz;

	inline void Init ( void ){
		MEM ( seg, 0 );
		MEM ( basic, 0 );
	}

	inline void update ( int l, int r, int n, int Index, int value ){
		if ( l == r )
			basic[l] = seg[n] = value;
		else{
			int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( Index <= mid )
				update ( l, mid, leftSon, Index, value );
			else
				update ( mid + 1, r, rightSon, Index, value );

			seg[n] = min ( seg[leftSon], seg[rightSon] );
		}
	}

	inline int query ( int l, int r, int nowL, int nowR, int n ){
		if ( l <= nowL && nowR <= r )
			return seg[n];
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			return query ( l, r, nowL, mid, leftSon );
		else if ( mid < l )
			return query ( l, r, mid + 1, nowR, rightSon );
		else
			return min ( query ( l, mid, nowL, mid, leftSon ), query ( mid + 1, r, mid, nowL, rightSon ) );
	}
};

inline D1 merge ( D1 a, D1 b ){
	int n = a.sz, m = n - 1;
	REPP ( i, 0, n ) a.update ( 0, m, 1, i, b.basic[i] );
	return a;
}

struct D2{
	D1 seg[maxN << 2];

	inline void markSz ( int l, int r, int n, int value ){
		seg[n].sz = value;
		seg[n].Init();
		if ( l == r )
			return;
		int mid = ( l + r ) >> 1;
		markSz ( l, mid, n * 2, value );
		markSz ( mid + 1, r, n * 2 + 1, value );
	}

	inline void update ( int l, int r, int u, int d, int x, int y, int value, int n ){
		if ( l == r )
			seg[n].update ( u, d, 1, y, value );
		else{
			int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( x <= mid )
				update ( l, mid, u, d, x, y, value, leftSon );
			else
				update ( mid + 1, r, u, d, x, y, value, rightSon );

			seg[n] = merge ( seg[leftSon], seg[rightSon] );
		}
	}

	inline int query ( int l, int r, int nowL, int nowR, int n, int u, int d ){
		if ( l <= nowL && nowR <= r )
			return seg[n].query ( u, d, 0, seg[n].sz - 1, 1 );
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			return query ( l, r, nowL, mid, leftSon, u, d );
		else if ( mid < l )
			return query ( l, r, mid + 1, nowR, rightSon, u, d );
		else
			return min ( query ( l, mid, nowL, mid, leftSon, u, d ), query ( mid + 1, r, mid + 1, nowR, rightSon, u, d ) );
	}
} seg;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, q, value, l, r, u, d;
	cin >> n >> m;
	REPP ( i, 0, n ){
		seg.markSz ( 1, n, 1, m );
		REPP ( j, 0, m ){
			cin >> value;
			seg.update ( 1, n, 1, m, i, j, value, 1 );
		}
	}

	cin >> q;
	while ( q-- ){
		cin >> l >> r >> u >> d;
		cout << seg.query ( l, r, 1, n, 1, u, d ) << '\n';
	}
}