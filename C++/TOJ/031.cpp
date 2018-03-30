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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct node{
	node *l, *r;
	int value, sum, lSum, rSum, ma, pri, sz;
	bool rev, change;

	node ( int _value ){
		value = sum = lSum = rSum = ma = _value;
		pri = rand();
		rev = change = false;
	}

	inline void modify ( int v ){
		change = true;
		value = v;
		sum = v * sz;
		ma = lSum = rSum = max ( v, sum );
	}

	inline void down ( void ){
		if ( rev ){
			swap ( l, r );
			swap ( lSum, rSum );
			if ( l )
				l -> rev = true;
			if ( r )
				r -> rev = true;
			rev = false;
		}
		if ( change ){
			l -> modify ( value );
			r -> modify ( value );
			change = false;
			l -> change = r -> change = true;
		}
	}
} *root;

inline int SZ ( node *o ){
	return o ? o -> sz : 0;
}

inline void pull ( node *p, node *l, node *r ){
	if ( !l || !r )
		return;
	p -> ma = max ( max ( l -> ma, r -> ma ), l -> rSum + r -> lSum );
	p -> sum = l -> sum + r -> sum;
	p -> lSum = max ( l -> lSum, l -> sum + r -> lSum );
	p -> rSum = max ( r -> rSum, r -> sum + l -> rSum );
}

inline void up ( node *o ){
	o -> sz = SZ ( o -> l ) + SZ ( o -> r ) + 1;
	o -> sum = o -> ma = o -> lSum = o -> rSum = o -> value;

	pull ( o, o -> l, o );
	pull ( o, o -> r, o );
}

inline node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		a -> down();
		a -> r = merge ( a -> r, b );
		up ( a );
		return a;
	}
	b -> down();
	b -> l = merge ( a, b -> l );
	up ( b );
	return b;
}

inline void split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	o -> down();
	if ( SZ ( o -> l ) > k ){
		a = o;
		split ( o -> r, a -> r, b, k - SZ ( o -> l ) - 1 );
		up ( a );
	}
	else{
		b = root;
		split ( root -> l, a, b -> l, k );
		up ( b );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	srand ( clock() );
	int n, q, in, p, k;
	string type;
	cin >> n >> q;
	root = nullptr;
	while ( n-- ){
		cout << n << '\n';
		cin >> in;
		root = merge ( root, new node ( in ) );
	}

	while ( q-- ){
		cin >> type;
	}
}