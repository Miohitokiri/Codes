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

#define int LL

struct node{
	node *l, *r;
	vi data;
	node ( void ): l ( nullptr ), r ( nullptr ){
		CLR ( data );
	}

	inline void up ( int L, int R ){
		RSZ ( data, R - L + 1 );
		merge ( l -> data.begin(), l -> data.end(), r -> data.begin(), r -> data.end(), data.begin() );
	}
} *root;

int Index, value;
vi stop;

inline node *build ( int l, int r ){
	cout << l << ' ' << r << '\n';
	node *o = new node();
	if ( l == r )
		return o;
	int mid = ( l + r ) >> 1;
	o -> l = build ( l, mid );
	o -> r = build ( mid + 1, r );
	return o;
}

inline void insert ( int l, int r, node *o ){
	if ( l == r ){
		o -> CLR ( data );
		o -> data.pb ( value );
	}
	else{
		cout << l << ' ' << r << '\n';
		int mid = ( l + r ) >> 1;
		if ( Index <= mid )
			insert ( l, mid, o -> l );
		else
			insert ( mid + 1, r, o -> r );

		o -> up ( l, r );
	}
}

inline void query ( int l, int r, int nowL, int nowR, node *o ){
	if ( !o )
		return;
	if ( l <= nowL && nowR <= r ){
		for ( auto i: o -> data )
			stop.pb ( i );
		return;
	}
	int nowMid = ( nowL + nowR ) >> 1;
	if ( nowMid < l )
		query ( l, r, nowMid + 1, nowR, o -> r );
	else if ( r <= nowMid )
		query ( l, r, nowL, nowMid, o -> l );
	else{
		query ( l, nowMid, nowL, nowMid, o -> l );
		query ( nowMid + 1, r, nowMid + 1, nowR, o -> r );
	}
}

inline bool cmp ( int a, int b ){
	return a > b;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int LL

	int n, q, l, r, k, type, v;
	vec < node* > version;
	node *now = new node();
	cin >> n >> q;
	n--;
	root = build ( 0, n );
	REPP ( i, 0, n + 1 ){
		cout << i << '\n';
		cin >> value;
		insert ( 0, n, root );
		Index++;
	}

	version.pb ( root );

	while ( q-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> Index >> value;
			root = *( END ( version ) - 1 );
			now = new node();
			now -> l = root -> l;
			now -> r = root -> r;
			now -> data = root -> data;
			insert ( 0, n, now );
			version.pb ( now );
		}
		else if ( type == 2 ){
			cin >> l >> r >> k >> v;
			now = version[v];
			CLR ( stop );
			query ( l, r, 0, n, now );
			sort ( ALL ( stop ), cmp );
			cout << stop[k - 1] << '\n';
		}
	}
}