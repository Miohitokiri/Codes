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
// #define SZ(n) ( int ) n.size()
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

mt19937 ran ( 0x2991dfa );

struct node{
	node *l, *r;
	bool rev = false;
	int value, pri, sz;

	node ( int _val ){
		l = r = nullptr;
		value = _val;
		sz = 1;
		rev = false;
		pri = ran();
	}

	inline void up ( void ){
		sz = 1;
		if ( l )
			sz += l -> sz;
		if ( r )
			sz += r -> sz;
	}

	inline void down ( void ){
		if ( rev ){
			swap ( l, r );
			if ( l )
				l -> rev ^= 1;
			if ( r )
				r -> rev ^= 1;
			rev ^= 1;
		}
	}
} *root = nullptr;

inline int SZ ( node *o ){
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri > b -> pri ){
		a -> down();
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
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
	o -> down();
	if ( k >= SZ ( o -> l ) + 1 ){
		a = o;
		split ( o -> r, a -> r, b, k - SZ ( o -> l ) - 1 );
	}
	else{
		b = o;
		split ( o -> l, a, b -> l, k );
	}
	o -> up();
}

vi ans;

void print ( node *o ){
	if ( !o )
		return;
	print ( o -> l );
	ans.pb ( o -> value );
	print ( o -> r );
}

void dfs ( node *&o ){
	if ( !o )
		return;
	o -> down();
	if ( o -> l )
		dfs ( o -> l );
	if ( o -> r )
		dfs ( o -> r );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, l1, r1, l2, r2;
	string type;
	node *l, *r, *mid, *swp, *a, *b;
	cin >> n >> m;
	n++;
	REPP ( i, 1, n ){
		root = merge ( root, new node ( i ) );
	}

	while ( m-- ){
		cin >> type >> l1 >> r1;
		if ( type == "REV" ){
			split ( root, swp, r, r1 );
			split ( swp, l, mid, l1 - 1 );
			mid -> rev ^= 1;
			merge ( l, merge ( mid, r ) );
		}
		else{
			cin >> l2 >> r2;
			split ( root, swp, r, r2 );
			split ( swp, a, b, l2 - 1 );
			split ( a, swp, mid, r1 );
			split ( swp, l, a, l1 - 1 );
			root = merge ( l, merge ( b, merge ( mid, merge ( a, r ) ) ) );
		}
	}

	dfs ( root );

	n--;
	print ( root );
	cout << ans[0];
	REPP ( i, 1, n ){
		cout << ' ' << ans[i];
	}
	cout << '\n';
}