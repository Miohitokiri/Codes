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
#define maxN 200005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct node{
	node *l, *r;
	int ma, sz, pri, val, idx;

	node ( int _val, int _idx ){
		l = r = nullptr;
		sz = 1, pri = rand(), idx = _idx;
		val = ma = _val;
	}

	~node(){
		if ( l )
			delete l;
		if ( r )
			delete r;
	}

	inline void up ( void ){
		sz = 1;
		if ( l ){
			if ( ma < l -> ma )
				ma = l -> ma, idx = l -> idx;
			sz += l -> sz;
		}
		if ( r ){
			if ( ma < r -> ma )
				ma = r -> ma, idx = r -> idx;
			sz += r -> sz;
		}
	}
};

inline int Sz ( node *o ){
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri > b -> pri ){
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
	if ( Sz ( o -> l ) < k ){
		a = o;
		split ( o -> r, a -> r, b, k - Sz ( o -> l ) - 1 );
		a -> up();
	}
	else{
		b = o;
		split ( o -> l, a, b -> l, k );
		b -> up();
	}
}

int seg[maxN << 2];

void modify ( int l, int r, int nowL, int nowR, int value, int n ){
	if ( l <= nowL && nowR <= r ){
		seg[n] = value;
		return;
	}
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		modify ( l, r, nowL, mid, value, leftSon );
	else if ( mid < l )
		modify ( l, r, mid + 1, nowR, value, rightSon );
	else{
		modify ( l, r, nowL, mid, value, leftSon );
		modify ( l, r, mid + 1, nowR, value, rightSon );
	}
}

int query ( int l, int r, int index, int n ){
	if ( l == r )
		return seg[n];
	int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	seg[leftSon] = seg[rightSon] = seg[n];
	if ( index <= mid )
		return query ( l, mid, index, leftSon );
	if ( mid < index )
		return query ( mid + 1, r, index, rightSon );

	return 0;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, k, in, L, R, val = 1;
	node *root, *l, *r, *mid, *swp;
	vec < pii > data;
	cin >> n >> k;
	REPP ( i, 0, n ){
		cin >> in;
		root = merge ( root, new node ( in, i ) );
	}
	while ( root ){
		if ( root <= 1 + k * 2 ){
			L = 0, R = n - 1;
		}
		else{
			L = root -> idx - k, R = root -> idx - k;
		}
		data.pb ( pii ( L, R ) );
		split ( root, swp, r, R + 1 );
		split ( swp, l, mid, L - 1 );
		delete mid;
		root = merge ( l, r );
	}
	REV ( ALL ( data ) );
	n--;
	REPALL ( i, data ){
		modify ( 0, n, i.F, i.S, val + 1, 1 );
		val ^= 1;
	}

	for ( int i = 0 ; i <= n ; i++ )
		cout << query ( 0, n, i, 1 );
	cout << '\n';
}