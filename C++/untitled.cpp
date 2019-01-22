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

mt19937 ran ( 0x123bace6 );

struct node{
	node *l, *r;
	int value, size, ma, lma, rma, pri;
	bool rev;

	node ( int _val ){
		l = r = nullptr;
		size = 1;
		value = ma = lma = rma = _val;
		pri = ran();
		rev = false;
	}
};

inline int sz ( node *o ){
	return o ? o -> size : 0;
}

inline void up ( node *&o ){
	o -> size = 1;
	if ( o -> l )
		o -> size += o -> l -> size;
	if ( o -> r )
		o -> size += o -> r -> size;
}

inline void down ( node *&o ){
	if ( o -> rev ){
		swap ( o -> l, o -> r );
		swap ( o -> lma, o -> rma );
		o -> rev = false;
		if ( o -> l )
			o -> l -> rev ^= 1;
		if ( o -> r )
			o -> r -> rev ^= 1;
	}
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri > b -> pri ){
		down ( a );
		a -> r = merge ( a -> r, b );
		up ( a );
	}
	down ( b );
	b -> l = merge ( a, b -> l );
	up ( b );
}

inline split ( node *o, node *&a, node *&b, int n ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	down ( o );
	if ( Sz ( o ) < k ){
		a = o;
		split ( a -> r, a -> r, b, k - Sz ( o ) - 1 );
		up ( a );
	}
	else{
		b = o;
		split ( b -> l, a, b -> l, k );
		up ( b );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q;
	cin >> n >> q;
}