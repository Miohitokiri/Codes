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
#define NEG_INF 0x8f8f8f8f
#define maxN 5005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

/*
 *             ,ad8888ba,    ,ad8888ba,    88888888ba,    88888888888  88888888888  ,ad8888ba,    88888888ba     ,ad8888ba,   88888888888  ad88888ba         ,ad8888ba,    ,ad8888ba,    88b           d88  
 *           d8"'    `"8b  d8"'    `"8b   88      `"8b   88           88          d8"'    `"8b   88      "8b   d8"'    `"8b  88          d8"     "8b       d8"'    `"8b  d8"'    `"8b   888b         d888  
 *         d8'           d8'        `8b  88        `8b  88           88         d8'        `8b  88      ,8P  d8'            88          Y8,              d8'           d8'        `8b  88`8b       d8'88  
 *        88            88          88  88         88  88aaaaa      88aaaaa    88          88  88aaaaaa8P'  88             88aaaaa     `Y8aaaaa,        88            88          88  88 `8b     d8' 88  
 *       88            88          88  88         88  88"""""      88"""""    88          88  88""""88'    88             88"""""       `"""""8b,      88            88          88  88  `8b   d8'  88  
 *      Y8,           Y8,        ,8P  88         8P  88           88         Y8,        ,8P  88    `8b    Y8,            88                  `8b      Y8,           Y8,        ,8P  88   `8b d8'   88  
 *      Y8a.    .a8P  Y8a.    .a8P   88      .a8P   88           88          Y8a.    .a8P   88     `8b    Y8a.    .a8P  88          Y8a     a8P  888  Y8a.    .a8P  Y8a.    .a8P   88    `888'    88  
 *      `"Y8888Y"'    `"Y8888Y"'    88888888Y"'    88888888888  88           `"Y8888Y"'    88      `8b    `"Y8888Y"'   88888888888  "Y88888P"   888   `"Y8888Y"'    `"Y8888Y"'    88     `8'     88                                                                                                                                                                                                   
 */

int cnt[maxN], ans[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, k, ma = -1, id = 1;
	vi data;
	cin >> n >> k;
	GETDATA ( data, n );
	REPALL ( i, data ){
		cnt[i]++;
		ma = max ( ma, i );
	}
	REPALL ( i, data ){
		if ( cnt[i] > k ){
			cout << "NO\n";
			return 0;
		}
	}

	REPALL ( i, data ){
		cnt[i] = 1;
	}
	cout << "YES\n";
	if ( n == k ){
		for ( int i = 1 ; i <= n ; i++ )
			cout << i << ' ';
		cout << '\n';
		return 0;
	}
	ma = -1;
	for ( int i = 0 ; i < n ; i++ ){
		ans[i] = cnt[data[i]]++;
		ma = max ( ma, ans[i] );
	}

	MEM ( cnt, 0 );
	REPP ( i, 0, n ){
		cnt[ans[i]]++;
	}
	for ( int i = 0 ; i < n && ma != k ; i++ ){
		if ( ans[i] == id && cnt[id] > 1 ){
			ans[i] = ++ma;
			cnt[id]--;
		}
		if ( cnt[id] == 1 )
			id++;
	}

	REPP ( i, 0, n ){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}