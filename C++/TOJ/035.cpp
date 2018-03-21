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
#define maxN 5005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

typedef pair < short, int > psi;

GRE ( psi, edge );
int ma = -1, mi = INF;
short t;

inline bool dfs ( int n, int p ){
	if ( n == t )
		return true;
	REPALL ( i, edge[n] ){
		if ( i.F == p )
			continue;
		if ( dfs ( i.F, n ) ){
			ma = max ( ma, i.S );
			mi = min ( mi, i.S );
			return true;
		}
	}

	return false;
}

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int w, g;
	short u, v, n, m, s;
	cin >> n >> m >> s >> t;
	while ( m-- ){
		cin >> u >> v >> w;
		edge[u].pb ( psi ( v, w ) );
		edge[v].pb ( psi ( u, w ) );
	}

	if ( dfs ( s, -1 ) ){
		g = gcd ( ma, mi );
		ma /= g, mi /= g;
		cout << ma;
		if ( mi != 1 )
			cout << '/' << mi;
	}
	else
		cout << "IMPOSSIBLE";
	cout << '\n';
}