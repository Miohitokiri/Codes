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
#define maxN 1005

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

struct D1{
	int seg[maxN << 2];

	void update ( int l, int r, int index, int value, int n ){
		if ( l == r )
			seg[n] = value;
		else{
			int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( index <= mid )
				update ( l, mid, index, value, leftSon );
			else
				update ( mid + 1, r, index, value, rightSon );

			seg[n] = max ( seg[leftSon], seg[rightSon] );
		}
	}

	int query ( int l, int r, int nowL, int nowR, int n ){
		if ( l <= nowL && nowR <= r )
			return seg[n];
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			return query ( l, r, nowL, mid, leftSon );
		if ( mid < l )
			return query ( l, r, mid + 1, nowR, rightSon );
		return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
	}

	void merge ( D1 &a, D1 &b, int l, int r, int n ){
		seg[n] = max ( a.seg[n], b.seg[n] );
		if ( l == r )
			return;
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		merge ( a, b, l, mid, leftSon );
		merge ( a, b, mid + 1, r, rightSon );
	}
};

struct D2{
	D1 seg[maxN << 2];
	int sz;

	void update ( int l, int r, int x, int y, int value, int n ){
		// cout << l << ' ' << r << ' ' << n << '\n';
		if ( l == r )
			seg[n].update ( 0, sz, y, value, 1 );
		else{
			int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( x <= mid )
				update ( l, mid, x, y, value, leftSon );
			else
				update ( mid + 1, r, x, y, value, rightSon );

			seg[n].merge ( seg[leftSon], seg[rightSon], 1, sz, 1 );
		}
	}

	int query ( int l, int r, int u, int d, int nowL, int nowR, int n ){
		if ( l <= nowL && nowR <= r )
			return seg[n].query ( u, d, 0, sz, 1 );
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			return query ( l, r, u, d, nowL, mid, leftSon );
		if ( mid < l )
			return query ( l, r, u, d, mid + 1, nowR, rightSon );
		return max ( query ( l, r, u, d, nowL, mid, leftSon ), query ( l, r, u, d, mid + 1, nowR, rightSon ) );
	}
} seg;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, in, k, x1, x2, y1, y2, type;
	cin >> n >> m;
	seg.sz = m;
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 1 ; j <= m ; j++ ){
			cin >> in;
			seg.update ( 1, n, i, j, in, 1 );
		}
	}

	cin >> k;
	while ( k-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> x1 >> y1 >> in;
			seg.update ( 1, n, x1, y1, in, 1 );
		}
		else{
			cin >> x1 >> y1 >> x2 >> y2;
			cout << seg.query ( x1, x2, y1, y2, 1, n, 1 ) << '\n';
		}
	}

	// del
	/*
	for ( int i = 1 ; i <= n << 2 ; i++ ){
		for ( int j = 1 ; j <= m << 2 ; j++ )
			cout << seg.seg[i].seg[j] << ' ';
		cout << '\n';
	}
	*/
}