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

// greph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct node{
	int data, size;
	node *l, *r;
	bool rev;
	node ( int d ): data ( d ), l ( nullptr ), r ( nullptr ), size ( 1 ), rev ( false ){}

	inline void down ( void ){
		if ( rev ){
			swap ( l, r );
			if ( l )
				l -> rev ^= 1;
			if ( r )
				r -> rev ^= 1;
			rev = false;
		}
	}
} *root;

inline int sz ( node *o ){
	return o ? o -> size : 0;
}

inline int val ( node *o ){
	return o ? o -> data : 0;
}

inline void up ( node *&o ){
	o -> data = val ( o -> l ) + val ( o -> r );
	o -> size = sz ( o -> l ) + sz ( o -> r );
}

inline node *build ( int l, int r ){
	node *o = new node ( 0 );
	if ( l == r )
		return o;
	int mid = ( l + r ) >> 1;
	o -> l = build ( l, mid );
	o -> r = build ( mid + 1, r );
	up ( o );
	return o;
}

inline void insert ( int l, int r, int Index, int value, node *&o ){
	if ( l == r )
		o = new node ( value );
	else{
		o -> down();
		int mid = l + sz ( o -> l );
		if ( Index <= mid )
			insert ( l, mid, Index, value, o -> l );
		else
			insert ( mid + 1, r, Index, value, o -> r );

		up ( o );
	}
}

inline int query ( int l, int r, int nowL, int nowR, node *o ){
	if ( !o )
		return 0;
	o -> down();
	if ( l <= nowL && nowR <= r )
		return o -> data;
	int nowMid = nowL + sz ( o -> l );
	if ( nowMid < l )
		return query ( l, r, nowMid + 1, nowR, o -> r );
	else if ( r <= nowMid )
		return query ( l, r, nowL, nowMid, o -> l );
	else
		return query ( l, r, nowL, nowMid, o -> l )+ query ( l, r, nowMid + 1, nowR, o -> r );
}

inline void dfs ( node *o ){ // del
	cout << o -> size << ' ';
	if ( o -> l )
		dfs ( o -> l );
	if ( o -> r )
		dfs ( o -> r );
}

inline void reverse ( int l, int r, int nowL, int nowR, node *&o ){
	if ( !o )
		return;
	if ( l <= nowL && nowR <= r )
		o -> rev ^= 1;
	else{
		int mid = ( l + r ) >> 1;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, type, value;
	cin >> n >> q;
	n--;
	root = build ( 0, n );
	// del
	dfs ( root );
	cout << '\n';
	// del
	REPP ( i, 0, n + 1 ){
		cin >> value;
		insert ( 0, n, i, value, root );
	}

	while ( q-- ){
		cin >> type >> l >> r;
		if ( type == 1 )
			insert ( 0, n, l, r, root );
		else if ( type == 2 )
			cout << query ( l, r, 0, n, root ) << '\n';
		else
			reverse ( l, r, 0, n, root );
	}

	dfs ( root );
	cout << '\n';
}