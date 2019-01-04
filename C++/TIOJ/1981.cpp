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
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 1000005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

GRE ( int, edges );
GRE ( int, dag );
int scc[maxN], sccSz[maxN], D[maxN], L[maxN], dp[maxN], tms = 1;
bool inSt[maxN];
stack < int, vi > st;

void dfs ( int n ){
	D[n] = L[n] = tms++;
	inSt[n] = true;
	st.push ( n );
	REPALL ( i, edges[n] ){
		if ( !D[i] )
			dfs ( i );
		if ( inSt[i] )
			L[n] = min ( L[n], L[i] );
	}

	if ( L[n] == D[n] ){
		int swp = -1;
		while ( swp != n ){
			inSt[swp = st.top()] = false;
			st.pop();
			scc[swp] = n;
		}
	}
}

int solve ( int n ){
	if ( dp[n] )
		return dp[n];
	int res = 0;
	REPALL ( i, dag[n] ) res = max ( res, solve ( i ) );
	return dp[n] = res + sccSz[n];
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, swp, stp, ans = -1;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v;
		edges[u].pb ( v );
	}

	REPP ( i, 0, n ){
		if ( !D[i] )
			dfs ( i );
	}

	REPP ( i, 0, n ){
		sccSz[swp = scc[i]]++;
		REPALL ( j, edges[i] ){
			if ( swp != scc[j] )
				dag[swp].pb ( scc[j] );
		}
	}

	REPP ( i, 0, n ){
		ans = max ( ans, solve ( scc[i] ) );
	}

	cout << ans << '\n';
}