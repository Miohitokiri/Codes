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

LL dp[maxN][205];

struct node{
	int s, t, w, tp;

	inline bool operator < ( const node &b ) const{
		return s < b.s;
	}
};

int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );
	// cout.tie ( 0 );

	// auto tms = clock();

	int n, m, k, s, t, d, w, idx = 0;
	vec < node > data;
	multiset < pii > ms;
	// cin >> n >> m >> k;
	scanf ( "%d%d%d", &n, &m, &k );

	for ( int i = 0 ; i < n + 2 ; i++ ){
		for ( int j = 0 ; j <= m ; j++ ){
			dp[i][j] = 1e18;
		}
	}
	dp[0][0] = 0;

	while ( k-- ){
		// cin >> s >> t >> d >> w;
		scanf ( "%d%d%d%d", &s, &t, &d, &w );
		data.pb ( node { s, d, w, 1 } );
		data.pb ( node { t + 1, d, w, -1 } );
	}

	if ( m >= n ){
		puts ( "0" );
		return 0;
	}

	sort ( ALL ( data ) );

	for ( int i = 0 ; i <= n ; i++ ){
		while ( idx != SZ ( data ) && data[idx].s == i ){
			if ( data[idx].tp == -1 )
				ms.erase ( ms.find ( pii ( data[idx].w, data[idx].t ) ) );
			else
				ms.insert ( pii ( data[idx].w, data[idx].t ) );
			idx++;
		}

		pii p = pii ( 0, i );
		if ( !EMP ( ms ) )
			p = *ms.rbegin();
		for ( int j = 0 ; j <= m ; j++ ){
			if ( j )
				dp[i][j] = min ( dp[i][j], dp[i][j - 1] );
			dp[p.S + 1][j] = min ( dp[i][j] + p.F, dp[p.S + 1][j] );
			dp[i + 1][j + 1] = min ( dp[i][j], dp[i + 1][j + 1] );
		}
	}

	printf ( "%lld\n", dp[n + 1][m] );

	// printf ( "%.6lf\n", ( clock() - tms ) / CLOCKS_PER_SEC );
}