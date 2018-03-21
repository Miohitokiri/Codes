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

GRE ( int, edge ), AP;
vec < pii > bridge;
int L[maxN], parent[maxN], D[maxN];
bool go[maxN];

inline void Init ( void ){
	CLR ( AP );
	CLR ( bridge );
	REPP ( i, 0, maxN ) CLR ( edge[i] );
	MEM ( L, 0 );
	MEM ( parent, 0 );
	MEM ( D, 0 );
	MEM ( go, 0 );
}

inline void dfs ( int n, int d ){
	go[n] = true;
	D[n] = L[n] = d++;
	int child = 0;
	bool isAP = false;

	REPALL ( i, edge[n] )
		if ( !go[i] ){
			parent[i] = n;
			dfs ( i, d );
			child++;
			if ( D[n] <= L[i] )
				isAP = true;
			if ( D[n] < L[i] )
				bridge.pb ( pii ( min ( n, i ), max ( n, i ) ) );

			L[n] = min ( L[n], L[i] );
		}
		else if ( i != parent[n] )
			L[n] = min ( L[n], D[i] );

	if ( ( parent[n] && isAP ) || ( !parent[n] && child >= 2 ) )
		AP.pb ( n );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, cnt = 0;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v;
		edge[u].pb ( v );
		edge[v].pb ( u );
	}

	REPP ( i, 1, n )
		if ( !go[i] )
			dfs ( i, cnt++ );

	sort ( ALL ( bridge ) );
	cout << "Bridge num: " << SZ ( bridge ) << '\n';
	REPALL ( i, bridge )
		cout << i.F << ' ' << i.S << '\n';

	cout << '\n';
	sort ( ALL ( AP ) );
	cout << "AP num: " << SZ ( AP ) << '\n';
	PIO ( AP );
	reverse ( AP );
}