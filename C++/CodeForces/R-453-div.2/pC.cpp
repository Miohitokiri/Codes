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

GRE ( int, edge );
int father[maxN];

inline void dfs ( int n, int p ){
	father[n] = p;
	REPALL ( i, edge[n] ) if ( i != p ) dfs ( i, n );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, deg[maxN], cnt = 2, p = 1, swp;
	bool allOne = true;
	cin >> n;
	REPP ( i, 0, n + 1 ){
		cin >> deg[i];
		if ( deg[i] != 1 )
			allOne = false;
	}

	cout << ( allOne ? "perfect" : "ambiguous" ) << '\n';

	if ( !allOne ){
		REPP ( i, 1, n ){
			REPP ( j, 0, deg[i] ) UNI ( cnt++, p, edge );
			p = cnt;
		}

		dfs ( 1, 0 );
		REPP ( i, 1, cnt + 1 ) cout << father[i] << ' ';
		cout << '\n';

		MEM ( father, 0 );
		p = 1, cnt = 2;
		REPP ( i, 1, n ){
			UNI ( cnt++, p, edge );
			swp = cnt;
			REPP ( j, 1, deg[i] ) UNI ( cnt++, p, edge );
			p = swp;
		}

		dfs ( 1, 0 );
		REPP ( i, 1, cnt + 1 ) cout << father[i] << ' ';
		cout << '\n';
	}
}