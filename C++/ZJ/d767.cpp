/************************************/
/* Date		: 2019-10-28 19:29:04	*/
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
#define REPP(i,f,s) for ( int i = f ; i < s ; ++i )
#define REPM(i,f,s) for ( int i = f ; i >= s ; --i )
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
#define maxN 30005
#define maxLog 15

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int dp[maxN][maxLog], D[maxN];
bool inDeg[maxN];
GRE ( int, edges );

void dfs ( int n, int dep ){
	D[n] = dep++;
	for ( auto i: edges[n] ){
		dp[i][0] = n;
		dfs ( i, dep );
	}
}

inline void build ( int n, int s ){
	memset ( dp, -1, sizeof dp );
	dfs ( s, 0 );
	for ( int k = 1 ; k < maxLog ; k++ )
		for ( int i = 1 ; i <= n ; i++ )
			if ( dp[i][k - 1] != -1 )
				dp[i][k] = dp[dp[i][k - 1]][k - 1];
}

inline int LCA ( int x, int y ){
	if ( D[x] < D[y] )
		swap ( x, y );

	REPM ( i, maxLog - 1, 0 )
		if ( dp[x][i] != -1 && D[dp[x][i]] >= D[y] )
			x = dp[x][i];

	if ( x == y )
		return x;

	REPM ( i, maxLog - 1, 0 )
		if ( dp[x][i] != dp[y][i] )
			x = dp[x][i], y = dp[y][i];

	return dp[x][0];
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, u, v, root;
	cin >> n >> q;
	for ( int i = 1 ; i <= n ; ++i ){
		while ( cin >> v ){
			if ( v == 0 )
				break;
			edges[i].pb ( v );
			inDeg[v] = true;
		}
	}

	for ( int i = 1 ; i <= n ; ++i )
		if ( !inDeg[i] ){
			root = i;
			break;
		}

	build ( n, root );

	while ( q-- ){
		cin >> u >> v;
		root = LCA ( u, v );
		cout << root << ' ' << D[u] + D[v] - 2 * D[root] << '\n';
	}
}