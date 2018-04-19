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
#define maxN 10005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

GRE ( int, edges );
int high[maxN], dis[maxN], cnt, mi;
bool used[maxN], inQ[maxN];

inline void Init ( void ){
	REPP ( i, 0, maxN ) dis[i] = i;
	MEM ( high, 0 );
	REPALL ( i, edges ) CLR ( i );
	MEM ( used, 0 );
	MEM ( inQ, 0 );
}

inline int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline int dfs ( int n ){
	used[n] = true;
	if ( high[n] == mi )
		return high[n];
	cnt++;
	int miDFS = high[n], nxt = n;
	REPP ( i, 0, SZ ( edges[n] ) ){
		if ( used[edges[n][i]] )
			continue;
		if ( miDFS >= high[edges[n][i]] ){
			miDFS = high[edges[n][i]];
			nxt = edges[n][i];
		}
	}

	if ( nxt == n )
		return miDFS;
	return dfs ( nxt );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, t, s, u, v, ans, round = 0, now;
	vi data;
	bool check;
	queue < int > q;
	cin >> t;
	while ( t-- ){
		cout << "Case #" << ++round << ": ";
		Init();
		ans = cnt = check = 0;
		mi = INF;
		CLR ( data );

		cin >> n >> m >> s;
		REPP ( i, 0, n ){
			cin >> high[i];
			mi = min ( mi, high[i] );
		}
		while ( m-- ){
			cin >> u >> v;
			UNI ( u, v, edges );
			Union ( u, v );
		}

		REPP ( i, 0, n ) if ( high[i] == mi ) data.pb ( i );
		REPALL ( i, data ) if ( same ( i, s ) ){
			check = true;
			break;
		}

		if ( !check ){
			cout << "Call 119!\n";
			continue;
		}

		if ( dfs ( s ) == mi )
			ans = cnt;

		cnt = INF;
		MEM ( dis, INF );
		q.push ( s );
		dis[s] = 0;
		while ( !EMP ( q ) ){
			now = q.front();
			q.pop();
			inQ[now] = false;
			REPALL ( i, edges[now] ) if ( dis[i] > dis[now] + 1 ){
				dis[i] = dis[now] + 1;
				if ( !inQ[i] ){
					inQ[i] = true;
					q.push ( i );
				}
			}
		}

		REPALL ( i, data ) cnt = min ( cnt, dis[i] );

		ans = cnt * 6 - ans;
		cout << ans << '\n';
	}
}