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
#define SP(a,b) swap ( a, b )
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
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) n.find ( Index ) != n.end()

// greph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

int main(){
	char opt[20] = { 0 }, in[15] = { 0 };
	int T, la;
	cin >> T;
	while ( T-- ){
		cin >> ( in + 1 );
		REPP ( i, 1, 12 ) in[i] -= '0';
		la=1;
		REPP ( i, 1, 16 ){
			if ( i == 1 || i == 2 || i == 4 || i == 8 )
				continue;
			opt[i] = in[la++];
		}
		opt[1] = opt[3] ^ opt[5] ^ opt[7] ^ opt[9] ^ opt[11] ^ opt[13] ^ opt[15];
		opt[2] = opt[3] ^ opt[6] ^ opt[7] ^ opt[10] ^ opt[11] ^ opt[14] ^ opt[15];
		opt[4] = opt[5] ^ opt[6] ^ opt[7] ^ opt[12] ^ opt[13] ^ opt[14] ^ opt[15];
		opt[8] = opt[9] ^ opt[10] ^ opt[11] ^ opt[12] ^ opt[13] ^ opt[14] ^ opt[15];
		REPP ( i, 1, 16 ) opt[i] += '0';
		cout << ( opt + 1 ) << '\n';
	}
}