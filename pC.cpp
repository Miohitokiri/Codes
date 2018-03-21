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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct node{
	node *leftSon, *rightSon;
	int key, pri;

	node ( int v ): key ( v ), leftSon ( nullptr ), rightSon ( nullptr ), pri ( rand() ) {}
} *root;

inline node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		a -> rightSon = merge ( a -> rightSon, b );
		return a;
	}
	b -> leftSon = merge ( a, b -> leftSon );
	return b;
}

inline void split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	else{
		if ( o -> key < k ){
			a = o;
			split ( o -> rightSon, a -> rightSon, b, k );
		}
		else{
			b = o;
			split ( o -> leftSon, a, b -> leftSon, k );
		}
	}
}

inline void insert ( node *&root, int k ){
	node *a, * b;
	split ( root, a, b, k );
	root = merge ( a, merge ( new node ( k ), b ) );
}

inline void erase ( node *&o, int k ){
	if ( !o )
		return;
	if ( o -> key == k ){
		node *t = o;
		o = merge ( o -> leftSon, o -> rightSon );
		delete t;
	}
	else{
		node *&t = k < o -> key ? o -> leftSon : o -> rightSon;
		erase ( t, k );
	}
}

inline int dfs ( node *o, int k ){
	if ( !o )
		return -1;
	return max ( ( o -> key ^ k ), max ( dfs ( o -> leftSon, k ), dfs ( o -> rightSon, k ) ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	srand ( clock() );
	int t, type, x;
	root = new node ( 0 );
	cin >> t;
	while ( t-- ){
		cin >> type >> x;
		if ( type == 0 )
			insert ( root, x );
		else if ( type == 1 )
			erase ( root, x );
		else
			cout << dfs ( root, x ) << '\n';
	}
}