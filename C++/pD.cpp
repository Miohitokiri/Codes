/************************************/
/* Date		: 2019-09-28 18:13:22	*/
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

inline short gcd ( short a, short b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;

	return min ( a, b );
}

typedef unsigned long long ull;

short c, d;

node tree{
	tree *l, *r;
	pii value;
	ull id;
	tree ( pii _val, ull _id ): l ( nullptr ), r ( nullptr ), value ( _val ), id ( _id ){}
} *root = nullptr;

ull ans;

void build ( node *&o ){
	if ( o -> value.F == c && o -> value.S == S ){
		ans = o -> id;
		return;
	}
	if ( o -> value.F > 64 || o -> value.S > 64 )
		return;
	o -> l = new tree ( pii ( o -> value.F, o -> value.F + o -> value.S ), ( o -> id ) << 1 );
	o -> r = new tree ( pii ( o -> value.F + o -> value.S, o -> value.S ), ( o -> id ) << 1 | 1 );
	build ( o -> l );
	build ( o -> r );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, a, b;
	cin >> t;
	while ( t-- ){
		cin >> a >> b >> c >> d;
		if ( gcd ( c, d ) == 1 ){
			cout << "-1\n";
			continue;
		}
		if ( a > c || b > d ){
			cout << "-1\n";
			continue;
		}

		ans = -1;
		root = new tree ( pii ( a, b ), 1 );
		cout << ans << '\n';
	}
}