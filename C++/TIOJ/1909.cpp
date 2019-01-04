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

#define int LL
#define pii pll
#define vi vl

GRE ( int, edges );
int cnt[maxN], dp[maxN], N;

void dfs ( int n,  int p ){
	int a = -1, b = -1;
	REPALL ( i, edges[n] ){
		if ( i == p )
			continue;
		if ( a == -1 )
			a = i;
		else
			b = i;
		dfs ( i, n );
		dp[n] += dp[i];
	}
	cnt[n] += ( N - dp[n] ) * dp[n];
	if ( SZ ( edges[n] ) == 3 )
		cnt[n] += dp[a] * dp[b];
	dp[n]++;
	cnt[n] += N;
	cnt[n] <<= 1;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	#define int LL

	int n, ma = -1, idx = -1;
	vi data;
	cin >> n;
	GETDATA ( data, n );


	stack < pii, vec < pii > > st;
	pii swp;
	st.push ( pii ( data[0], 0 ) );
	REPP ( i, 1, n ){
		while ( !EMP ( st ) && data[i] > st.top().F ){
			swp = st.top();
			st.pop();
			if ( EMP ( st ) )
				UNI ( swp.S, i, edges );
			else
				UNI ( ( st.top().F < data[i] ? st.top().S : i ), swp.S, edges );
		}
		st.push ( pii ( data[i], i ) );
	}
	swp = st.top();
	st.pop();
	while ( !EMP ( st ) ){
		UNI ( swp.S, st.top().S, edges );
		swp = st.top();
		st.pop();
	}

	N = n - 1;
	dfs ( 0, -1 );

	REPP ( i, 0, n ){
		if ( cnt[i] > ma )
			ma = cnt[i], idx = i;
	}

	cout << ma << ' ' << idx + 1 << '\n';
}