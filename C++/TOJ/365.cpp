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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct piece{
	int f, s, sz;
};

inline bool same ( piece a, piece b ){
	return a.f == b.f && a.s == b.s;
}

struct node{
	piece fro, bck, ma;
} seg[maxN << 2];

int basic[maxN];

inline node up ( node L, node R ){
	node res;
	res.fro = L.fro, res.bck = R.bck, res.ma = ( L.ma.sz > R.ma.sz ? L.ma : R.ma );

	if ( basic[L.bck.s] + 1 == basic[R.fro.f] ){
		piece stop = piece { L.bck.f, R.fro.s, R.fro.s - L.bck.f + 1 };

		if ( same ( L.fro, L.bck ) )
			res.fro = stop;
		if ( same ( R.fro, R.bck ) )
			res.bck = stop;

		res.ma = ( stop.sz > res.ma.sz ? stop : res.ma );
	}

	return res;
}

inline void build ( int l, int r, int n ){
	if ( l == r )
		seg[n].fro = seg[n].bck = seg[n].ma = piece { l, r, 1 };
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );

		seg[n] = up ( seg[leftSon], seg[rightSon] );
	}
}

inline void update ( int l, int r, int Index, int n ){
	if ( l == r )
		return;
	int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( Index <= mid )
		update ( l, mid, Index, leftSon );
	else
		update ( mid + 1, r, Index, rightSon );

	seg[n] = up ( seg[leftSon], seg[rightSon] );
}

inline node query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return up ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, type;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> basic[i];
	build ( 1, n, 1 );

	cin >> q;
	while ( q-- ){
		cin >> type >> l >> r;
		if ( type == 1 ){
			basic[l] = r;
			update ( 1, n, l, 1 );
		}
		else
			cout << query ( l, r, 1, n, 1 ).ma.sz << '\n';
	}
}