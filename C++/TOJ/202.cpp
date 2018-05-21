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
#define maxN 105

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

#undef mp

int dis[maxN], mp[maxN][maxN];
vi ansData;
vi dp[maxN][maxN];

inline int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline vi merge ( vi a, vi b ){
	vi res;
	REPALL ( i, a ) res.pb ( i );
	REPALL ( i, b ) res.pb ( i );
	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, s, u, v, w, q, cnt, now;
	cin >> n >> m >> s;
	MEM ( mp, INF );
	while ( m-- ){
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = w;
		dp[u][v].pb ( w );
		dp[v][u].pb ( w );
		Union ( u, v );
	}
	REPP ( i, 0, n ){
		mp[i][i] = 0;
	}

	REPP ( k, 0, n ){
		REPP ( i, 0, n ){
			REPP ( j, 0, n ){
				if ( mp[i][k] + mp[k][j] < mp[i][j] ){
					mp[i][j] = mp[i][k] + mp[k][j];
					dp[i][j] = merge ( dp[i][k], dp[k][j] );
				}
			}
		}
	}

	REPP ( i, 0, n ){
		REPP ( j, 0, n ) cout << mp[i][j] << ' ';
		cout << '\n';
	}

	cin >> q;
	while ( q-- ){
		cin >> u >> v;
		if ( u == v ){
			cout << "1\n";
			continue;
		}
		if ( !same ( u, v ) ){
			cout << "Impossible\n";
			continue;
		}
		now = s, cnt = 1;

		REPALL ( i, dp[u][v] ){
			cout << i << ' '; // del
			if ( now < i ){
				now = s;
				cnt++;
			}
			if ( now < i ){
				cnt = -1;
				break;
			}
			now -= i;
		}

		cout << '\n'; // del

		if ( cnt == -1 )
			cout << "Impossible\n";
		else
			cout << cnt << '\n';
	}
}