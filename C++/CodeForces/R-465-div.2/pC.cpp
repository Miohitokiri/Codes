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

inline double disten ( double x1, double y1, double x2, double y2 ){
	return sqrt ( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

int main(){
	int r, x1, x2, y1, y2;
	scanf ( "%d%d%d%d%d", &r, &x1, &y1, &x2, &y2 );
	double d = disten ( x1, y1, x2, y2 ), x3 = x1, y3 = y1, ansX, ansY;
	if ( d >= r ){
		printf ( "%d %d %d\n", x1, y1, r );
		return 0;
	}
	if ( x1 == x2 && y1 == y2 ){
		printf ( "%d %.15f %.15f\n", x1, ( double ) y1 + ( double ) r / 2, ( double ) r / 2 );
		return 0;
	}
	x3 += ( double ) ( x1 - x2 ) * ( double ) r / d;
	y3 += ( double ) ( y1 - y2 ) * ( double ) r / d;
	ansX = ( double ) ( x2 + x3 ) / 2;
	ansY = ( double ) ( y2 + y3 ) / 2;
	d = disten ( ansX, ansY, x2, y2 );
	printf ( "%.15f %.15f %.15f\n", ansX, ansY, d );
}