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

mt19937 ran ( 0x1234ab12 );

struct node{
	node *l, *r;
	int val, pri, sz;

	node ( int _val ){
		l = r = nullptr;
		val = _val;
		pri = ran();
		sz = 1;
	}

	~node ( void ){
		if ( l )
			delete l;
		if ( r )
			delete r;
	}

	void up ( void ){
		sz = 1;
		if ( l )
			sz += l -> sz;
		if ( r )
			sz += r -> sz;
	}
};

inline int Siz ( node *o ){
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	else{
		if ( o -> val <= k ){
			a = o;
			split ( o -> r, a -> r, b, k );
		}
		else{
			b = o;
			split ( o -> l, a, b -> l, k );
		}
		o -> up();
	}
}

inline void splitK ( node *o, node *&a, node *&b, int k ){
	if ( !o ){
		a = b = nullptr;
		return;
	}
	if ( Siz ( o -> l ) < k ){
		a = o;
		splitK ( a -> r, a -> r, b, k - Siz ( o -> l ) - 1 );
		a -> up();
	}
	else{
		b = o;
		splitK ( b -> l, a, b -> l, k );
		b -> up();
	}
	o -> up();
}

void print ( node *o ){
	if ( !o )
		return;
	print ( o -> l );
	cout << o -> val << ' ';
	print ( o -> r );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str;
	int n, k = 1;
	node *root, *l, *swp, *r;
	while ( cin >> str ){
		if ( str == "END" )
			break;
		else if ( str == "PUSH" ){
			cin >> n;
			l = r = nullptr;
			split ( root, l, r, n );
			root = merge ( l, merge ( new node ( n ), r ) );
		}
		else if ( str == "GET" ){
			if ( Siz ( root ) < k )
				continue;
			l = r = swp = nullptr;
			cout << "DE: " << k << '\n'; // del
			splitK ( root, l, swp, k - 1 );
			splitK ( swp, swp, r, 1 );
			if ( swp ){
				cout << swp -> val << '\n';
				k++;
			}
			root = merge ( l, merge ( swp, r ) );
		}
		else if ( str == "EXIT" ){
			delete root;
			root = nullptr;
			k = 1;
		}
	}
}