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
#define maxN 50005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

int bit[100010], in[maxN], out[maxN], size, cost[maxN];
GRE ( int, edges );

inline void dfs ( int x ){
	in[x] = ++size;
	REPALL ( i, edges[x] )
		if ( !in[i] )
			dfs ( i );
	out[x] = ++size;
}

inline void add ( int x, int value ){
	for ( int i = x ; i <= size ; i += i & -i )
		bit[i] += value;
}

inline int sum ( int n ){
	int res = 0;
	for ( int i = n ; i ; i -= i & -i )
		res += bit[i];
	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, ans = 0;
	char type;
	cin >> n >> m;
	REPP ( i, 1, n ){
		cin >> u >> v;
		UNI ( u, v, edges );
	}

	dfs ( 1 );

	for ( int i = 1 ; i <= n ; i++ ){
		cin >> cost[i];
		add ( in[i], cost[i] );
		add ( out[i], -cost[i] );
	}

	while ( m-- ){
		cin >> type;
		if ( type == 'C' ){
			cin >> u >> v;
			add ( in[u], v - cost[u] );
			add ( out[u], cost[u] - v );
			cost[u] = v;
		}
		else{
			cin >> u;
			ans += sum ( in[u] );
		}
	}

	cout << ans << '\n';
}