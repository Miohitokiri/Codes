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

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

struct node{
	node *l, *r;
	int value, sz;
	bool rev;

	node ( int _value ){
		l = r = nullptr;
		value = _value;
		sz = 1;
		rev = false;
	}

	// node ( node *o ): l ( o -> l ), r ( o -> r ), value ( o -> value ), rev ( o -> rev ), sz ( o -> sz ) {}

	inline void up ( void ){
		sz = 1 + ( l ? l -> sz : 0 ) + ( r ? r -> sz : 0 );
	}

	inline void down ( void ){
		if ( !rev )
			return;
		swap ( l, r );
		if ( l ){
			// l = new node ( *l );
			l -> rev ^= 1;
		}
		if ( r ){
			// r = new node ( *r );
			r -> rev ^= 1;
		}
		rev = false;
	}
} *root = nullptr;

inline int SZ ( node *o ){
	return o ? o -> sz : 0;
}

inline int ran(){
	static int x = 20180713;
	return x = ( x * 0xdefaced + 1) & INT_MAX;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( ran() % ( a -> sz + b -> sz ) < a -> sz ){
		// a = new node ( *a );
		a -> down();
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	// b = new node ( *b );
	b -> down();
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, int k ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	// o = new node ( *o );
	o -> down();
	if ( SZ ( o -> l ) < k ){
		a = o;
		split ( o -> r, a -> r, b, k - SZ ( o -> l ) - 1 );
		a -> up();
	}
	else{
		b = o;
		split ( o -> l, a, b -> l, k );
		b -> up();
	}
	o -> up();
}

void dfs ( node *o, bool rev ){
	if ( !o )
		return;
	rev ^= o -> rev;
	if ( rev ){
		dfs ( o -> r, rev );
		cout << o -> value << ' ';
		dfs ( o -> l, rev );
	}
	else{
		dfs ( o -> l, rev );
		cout << o -> value << ' ';
		dfs ( o -> r, rev );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	srand ( clock() );
	int n, m, _l, _r;
	node *l, *r, *swp, *mid;
	while ( cin >> n >> m ){
		root = nullptr;
		for ( int i = 1 ; i <= n ; i++ ){
			root = merge ( root, new node ( i ) );
		}

		while ( m-- ){
			cin >> _l >> _r;
			split ( root, swp, r, _r );
			split ( swp, l, mid, _l - 1 );
			mid -> rev ^= 1;
			root = merge ( l, merge ( mid, r ) );
		}

		dfs ( root, 0 );
		cout << '\n';
	}
}