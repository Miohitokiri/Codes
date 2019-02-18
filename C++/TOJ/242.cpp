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
// #define debuger cout << "111\n"
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

struct piece{
	short value;
	int sum;
	bool L, R;
};

struct node{
	node *l, *r;
	piece val;

	node ( int _val ){
		l = r = nullptr;
		val = piece { short ( _val ), _val, bool ( _val ), bool ( _val ) };
	}

	~node ( void ){
		if ( l )
			delete l;
		if ( r )
			delete r;
	}
} *root = nullptr;

inline piece up ( piece lp, piece rp ){
	piece res;
	res.L = lp.L, res.R = rp.R, res.value = -1;
	if ( lp.sum == 1 && rp.sum == 1 && lp.value == 1 && rp.value == 1 ){
		res.value = 1;
		res.sum = 1;
	}
	else if ( !lp.sum && !rp.sum )
		res.sum = res.value = 0;
	else
		res.sum = lp.sum + rp.sum - ( lp.R && rp.L );

	return res;
}

inline piece up ( node *l, node *r ){
	if ( !l || !r ){
		piece res = piece { 0, 0, 0, 0 };
		if ( l ){
			res = l -> val;
			res.value = -1;
			res.R = false;
		}
		else if ( r ){
			res = r -> val;
			res.value = -1;
			res.L = false;
		}
		return res;
	}
	return up ( l -> val, r -> val );
}

void update ( int l, int r, int nowL, int nowR, int value, node *&o ){
	if ( !o )
		o = new node ( 0 );
	if ( o -> val.value == value )
		return;
	if ( o -> val.value != value && o -> val.value == 1 ){
		if ( o -> l )
			delete o -> l;
		o -> l = new node ( o -> val.value );
		if ( o -> r )
			delete o -> r;
		o -> r = new node ( o -> val.value );
	}
	if ( l <= nowL && nowR <= r ){
		delete o;
		o = new node ( value );
	}
	else{
		int mid = ( nowL + nowR ) >> 1;
		if ( r <= mid )
			update ( l, r, nowL, mid, value, o -> l );
		else if ( mid < l )
			update ( l, r, mid + 1, nowR, value, o -> r );
		else{
			update ( l, mid, nowL, mid, value, o -> l );
			update ( mid + 1, r, mid + 1, nowR, value, o -> r );
		}

		o -> val = up ( o -> l, o -> r );
	}
}

piece query ( int l, int r, int nowL, int nowR, int value, node *&o ){
	if ( !o ){
		if ( value == 1 )
			return piece { 1, 1, 1, 1 };
		else
			return piece { 0, 0, 0, 0 };
	}
	value = o -> val.value;
	if ( l <= nowL && nowR <= r )
		return o -> val;
	int mid = ( nowL + nowR ) >> 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, value, o -> l );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, value, o -> r );

	return up ( query ( l, mid, nowL, mid, value, o -> l ), query ( mid + 1, r, mid + 1, nowR, value, o -> r ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, tp;
	cin >> n >> q;
	root = new node ( 0 );
	update ( 0, 0, 0, n, 1, root );
	while ( q-- ){
		cin >> tp >> l >> r;
		if ( tp == 3 )
			cout << query ( l, r, 0, n, -1, root ).sum << '\n';
		else
			update ( l, r, 0, n, ( tp == 1 ), root );
	}
}