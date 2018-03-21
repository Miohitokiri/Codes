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
#define FID(n,Index) n.find ( Index ) != n.end()

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
	int data, pri, s;
	node *leftSon, *rightSon;
	node ( int _data ): data ( _data ), pri ( rand() ), s ( 1 ){
		leftSon = rightSon = nullptr;
	}

	inline void up ( void ){
		s = 1;
		if ( leftSon )
			s += leftSon -> s;
		if ( rightSon )
			s += rightSon -> s;
	}
} *root;

inline int size ( node *&o ){
	return !o ? 0 : o -> s;
}

inline void split ( node *o, node *&a, node *&b, int k ){
	if ( !o )
		a = b = nullptr;
	else if ( k <= size ( o -> leftSon ) ){
		b = o;
		split ( o -> leftSon, a, b -> leftSon, k );
		b -> up();
	}
	else{
		a = o;
		split ( o -> rightSon, a -> rightSon, b, k - size ( o -> leftSon ) - 1 );
		a -> up();
	}
}

inline node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		a -> rightSon = merge ( a -> rightSon, b );
		a -> up();
		return a;
	}

	b -> leftSon = merge ( a, b -> leftSon );
	b -> up();
	return b;
}

inline int Rank ( node *o, int k ){
	if ( !o )
		return 0;
	return k < o -> data ? Rank ( o -> leftSon, k ) : Rank ( o -> rightSon, k ) + size ( o -> leftSon ) + 1;
}

inline int kth ( int k ){
	node *a, *b, *a2, *b2;
	split ( root, a, b, k - 1 );
	split ( b, a2, b2, 1 );
	int res = a2 -> data;
	root = merge ( a, merge ( a2, b2 ) );
	return res;
}

inline void insert ( int _data ){
	int k = Rank ( root, _data );
	node *a, *b;
	split ( root, a, b, k );
	root = merge ( merge ( a, new node ( _data ) ), b );
}

int main(){
	srand ( time ( NULL ) );
	root = nullptr;
	int n, x;
	scanf ( "%d", &n );
	n++;
	REPP ( i, 1, n ){
		scanf ( "%d", &x );
		insert ( x );
		if ( i & 1 )
			printf ( "%.6f\n", ( double ) kth ( i / 2 + 1 ) );
		else
			printf ( "%.6f\n", ( double ) kth ( i / 2 ) / 2.0 + ( double ) kth ( i / 2 + 1 ) / 2.0 );
	}
}