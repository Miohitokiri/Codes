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
	int value, sz, ma;

	node ( int _val ){
		ma = value = _val;
		sz = 1;
		l = r = nullptr;
	}

	inline void up ( void ){
		sz = 1;
		ma = value;
		if ( l ){
			sz += l -> sz;
			ma = max ( ma, l -> ma );
		}
		if ( r ){
			sz += r -> sz;
			ma = max ( ma, r -> ma );
		}
	}
} *root;

inline int sz ( node *o ){
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( rand() % ( sz ( a ) + sz ( b ) ) < sz ( a ) ){
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, int k ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	if ( !k ){
		a = nullptr;
		b = o;
		return;
	}

	if ( sz ( o -> l ) < k ){
		a = o;
		split ( o -> r, a -> r, b, k - 1 - sz ( o -> l ) );
		a -> up();
	}
	else{
		b = o;
		split ( o -> l, a, b -> l, k );
		b -> up();
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, in, type, x, y;
	node *l, *r, *swp, *mid;
	while ( cin >> n >> q ){
		root = nullptr;
		REPP ( i, 0, n ){
			cin >> in;
			root = merge ( root, new node ( in ) );
		}
		while ( q-- ){
			cin >> type;
			if ( type == 1 ){
				cin >> x >> y;
				split ( root, l, swp, x - 1 );
				split ( swp, mid, r, 1 );
				mid -> value = mid -> ma = y;
				root = merge ( l, merge ( mid, r ) );
			}
			else if ( type == 2 ){
				cin >> x >> y;
				split ( root, l, swp, x - 1 );
				split ( swp, mid, r, y - x + 1 );
				mid -> up();
				cout << mid -> ma << '\n';
				root = merge ( merge ( l, mid ), r );
			}
			else if ( type == 3 ){
				cin >> x >> y;
				split ( root, l, r, x - 1 );
				root = merge ( l, merge ( new node ( y ), r ) );
			}
			else{
				cin >> x;
				split ( root, l, swp, x - 1 );
				split ( swp, mid, r, 1 );
				delete mid;
				root = merge ( l, r );
			}
		}
	}
}