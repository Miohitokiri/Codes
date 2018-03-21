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
	int data;
	node *l, *r;
	node ( int d ): data ( d ), l ( nullptr ), r ( nullptr ){}
	inline void up ( void ){
		if ( !l )
			data = r -> data;
		else if ( !r )
			data = l -> data;
		else
			data = max ( l -> data, r -> data );
	}
} *root;

int value, Index;

inline node *build ( int l, int r ){
	node *o = new node ( 0 );
	if ( l == r )
		return o;
	int mid = ( l + r ) >> 1;
	o -> l = build ( l, mid );
	o -> r = build ( mid + 1, r );
	return o;
}

inline void insert ( int l, int r, node *o ){
	if ( l == r )
		o -> data = value;
	else{
		int mid = ( l + r ) >> 1;
		if ( Index <= mid )
			insert ( l, mid, o -> l );
		else
			insert ( mid + 1, r, o -> r );

		o -> up();
	}
}

inline int query ( int l, int r, int nowL, int nowR, node *o ){
	if ( !o )
		return 0;
	if ( l <= nowL && nowR <= r )
		return o -> data;
	int nowMid = ( nowL + nowR ) >> 1;
	if ( nowMid < l )
		return query ( l, r, nowMid + 1, nowR, o -> r );
	else if ( r <= nowMid )
		return query ( l, r, nowL, nowMid, o -> l );
	else
		return max ( query ( l, nowMid, nowL, nowMid, o -> l ), query ( nowMid + 1, r, nowMid + 1, nowR, o -> r ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, type;
	cin >> n;
	n--;
	root = build ( 0, n );
	REPP ( i, 0, n + 1 ){
		cin >> value;
		insert ( 0, n, root );
		Index++;
	}

	cin >> q;
	while ( q-- ){
		cin >> type >> Index >> value;
		if ( type == 1 )
			insert ( 0, n, root );
		else
			cout << query ( l, r, 0, n, root ) << '\n';
	}
}