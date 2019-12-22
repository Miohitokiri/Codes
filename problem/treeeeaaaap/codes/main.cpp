/************************************/
/* Date		: 2019-12-21 13:13:47	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

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
#define eb emplace_back
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

mt19937 ran ( 0x5a0b9e8 );

struct node{
	node *l, *r;
	int value, sz;
	bool rev;

	node ( int _value ): l ( nullptr ), r ( nullptr ), value ( _value ), sz ( 1 ), rev ( false ) {}
	node ( node *o ): l ( o -> l ), r ( o -> r ), value ( o -> _value ), sz ( 1 ), rev ( false ) {}

	inline void up ( void ){
		sz = 1 + ( l ? l -> sz : 0 ) + ( r ? r -> sz : 0 );
	}

	inline void down ( void ){
		if ( rev ){
			rev  = false;
			swap ( l, r );
			if ( l ){
				l = new node ( l );
				l -> rev ^= 1;
			}
			if ( r ){
				r = new node ( r );
				r -> rev ^= 1;
			}
		}
	}
};

inline int SZ ( node *o ){
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( ran() % ( a -> sz + b -> sz ) < a -> sz ){
		a = new node ( a );
		a -> down();
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b = new node ( b );
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
	if ( SZ ( o -> l ) < k ){
		a = new node ( o );
		split ( o -> r, a -> r, b, k - SZ ( o -> l ) - 1 );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, in, type, L, R;
	node *root = nullptr, mid, swp, l, r;
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		root = merge ( root, new node ( in ) );
	}
	while ( m-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> L >> R;
			split ( root, swp, r, R );
			split ( swp, l, mid, L - 1 );
			root = merge ( l, r );
			delete mid;
		}
		else if ( type == 2 ){
		}
		else if ( type == 3 ){
		}
		else if ( type == 4 ){
		}
		else if ( type == 5 ){
		}
	}
}