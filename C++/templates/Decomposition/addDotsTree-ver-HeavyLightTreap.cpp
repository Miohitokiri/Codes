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

mt19937 ran ( 0xabcdf123 );

struct node{
	node *l, *r;
	int pri, sz, val, ma;

	node ( int _val ){
		pri = ran();
		ma = val = _val;
		sz = 1;
		l = r = nullptr;
	}

	inline void up ( void ){
		ma = val;
		sz = 1;
		if ( l ){
			ma = max ( ma, l -> val );
			sz += l -> sz;
		}
		if ( r ){
			ma = max ( ma, r -> val );
			sz += r -> sz;
		}
	}
} *root = nullptr;

inline int SZ ( node *o ){
	return o ? o -> sz : 0;
}

inline node *merge ( node *a, node *b, node *c ){
	if ( ran() & 1 )
		return merge ( merge ( a, b ), c );
	return merge ( a, merge ( b, c ) );
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

inline void split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	else{
		if ( k >= SZ ( o -> l ) + 1 ){
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
}

GRE ( int, edges );
vi D, sz, maSon, where, value, link, pa;
int cnt;

inline void init ( int n ){
	RSZ ( D, n );
	MEM ( D, 0 );
	RSZ ( pa, n );
	MEM ( pa, -1 );
	RSZ ( value, n );
	MEM ( value, NEG_INF );
	RSZ ( maSon, n );
	MEM ( maSon, -1 );
	RSZ ( link, n );
	RSZ ( where, n );
	cnt = 0;
	root = nullptr;
}

void findPa ( int n ){
	sz[n] = 1;
	REPALL ( i, edges[n] ){
		if ( i == pa[n] )
			continue;
		pa[i] = n;
		D[i] = D[n] + 1;
		findPa ( i );
		if ( maSon[n] == -1 || sz[i] > sz[maSon[i]] )
			maSon[n] = i;
		sz[n] += sz[i];
	}
}

void dfs ( int n, int p ){
	link[n] = p;
	where[n] = cnt++;
	root = merge ( root, new node ( value[n] ) );
	if ( maSon[n] == -1 )
		return;
	dfs ( maSon[n], p );
	REPALL ( i, edges[n] ){
		if ( i == maSon[n] || i == pa[n] )
			continue;
		dfs ( i, i );
	}
}

inline void modify ( int idx, int value ){
	// idx -> node's id
	node *L, *R, *mid, *swp;
	idx = where[idx];
	split ( root, swp, R, idx );
	split ( swp, L, mid, idx - 1 );
	mid -> val = value;
	root = merge ( L, mid, R );
}

inline void add ( int idx, int v, int value ){
	D.pb ( D[idx] + 1 );
	// value.pb ( value );
	pa.pb ( idx );
	where.pb ( cnt++ );
	if ( edges[idx].size() == 1 ){
		// 如果沒有子結點，就把它接上去
		link.pb ( link[idx] );
	}
	else{
		// 如有的話，當作是另外一條新的link
		link.pb ( v );
	}
	merge ( root, new node ( value ) );
	UNI ( idx, v, edges );
}

inline int query ( int u, int v ){
	int ans = -1;
	node *L, *R, *mid, *swp;
	while ( link[u] != link[v] ){
		if ( D[u] > D[v] ){
			split ( root, swp, R, where[u] );
			split ( swp, L, mid, where[link[u]] );
			ans = max ( ans, mid -> ma );
			u = pa[link[u]];
		}
		else{
			split ( root, swp, R, where[v] );
			split ( swp, L, mid, where[link[v]] );
			ans = max ( ans, mid -> ma );
			v = pa[link[v]];
		}
		root = merge ( L, mid, R );
	}

	if ( D[u] > D[v] )
		swap ( u, v );

	split ( root, swp, R, where[v] );
	split ( swp, L, mid, where[u] );
	ans = max ( ans, mid -> ma );
	root = merge ( L, mid, R );

	return ans;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
}