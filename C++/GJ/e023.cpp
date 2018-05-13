// by. MiohitoKiri5474
#include<iostream>
#include<vector>

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
#define vec vector
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

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

#define INF 0x3f3f3f3f
#define maxN 20005
#define maxLog 20


// greph
struct bri{
	int u, v, w;
};

inline bool cmp ( bri a, bri b ){
	return a.w < b.w;
}

vec < bri > edges;
GRE ( pii, mst );
int ma, dis[maxN], n, D[maxN];
pii dp[maxN][maxLog];
vi LOG;

inline void Init ( void ){
	REPP ( i, 0, maxN ) dis[i] = i;
}

inline int find ( int d ){
	return dis[d] == d ? d : dis[d] = find ( dis[d] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline void dfs ( int d, int p, int dep ){
	D[d] = dep++;
	dp[d][0].F = p;
	for ( int i = 0 ; i < SZ ( mst[d] ) ; i++ ){
		if ( mst[d][i].F == p )
			continue;
		dp[mst[d][i].F][0] = pii ( d, mst[d][i].S );
		dfs ( mst[d][i].F, d, dep );
	}
}

inline void buildLCA ( void ){
	MEM ( dp, -1 );
	MEM ( D, 0 );
	dfs ( 0, -1, 0 );
	REPP ( k, 1, maxLog ){
		REPP ( i, 0, n ){
			if ( dp[i][k - 1].F == -1 )
				continue;
			dp[i][k].F = dp[dp[i][k - 1].F][k - 1].F;
			dp[i][k].S = max ( dp[i][k - 1].S, dp[dp[i][k - 1].F][k - 1].S );
		}
	}
}

inline void findLCA ( int x, int y ){
	if ( D[x] < D[y] )
		swap ( x, y );

	REPM ( i, maxLog - 1, 0 ){
		if ( dp[x][i].F != -1 && D[dp[x][i].F] >= D[y] ){
			ma = max ( ma, dp[x][i].S );
			x = dp[x][i].F;
		}
	}

	if ( x == y )
		return;

	REPM ( i, maxLog - 1, 0 ){
		if ( dp[x][i].F != dp[y][i].F ){
			ma = max ( ma, max ( dp[x][i].S, dp[y][i].S ) );
			x = dp[x][i].F, y = dp[y][i].F;
		}
	}

	ma = max ( ma, max ( dp[x][0].S, dp[y][0].S ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int m, t = 1, ans;
	bri stop;
	vi unUsed;
	REPP ( i, 0, maxLog ){
		LOG.pb ( t );
		t <<= 1;
	}
	cin >> t;
	while ( t-- && cin >> n >> m ){
		Init();
		CLR ( edges );
		CLR ( unUsed );
		REPP ( i, 0, n ) CLR ( mst[i] );
		ans = INF;
		ma = -1;

		REPP ( i, 0, m ){
			cin >> stop.u >> stop.v >> stop.w;
			edges.pb ( stop );
		}

		sort ( ALL ( edges ), cmp );
		REPP ( i, 0, m ){
			if ( same ( edges[i].u, edges[i].v ) ){
				unUsed.pb ( i );
				continue;
			}
			Union ( edges[i].u, edges[i].v );
			UNIw ( edges[i].u, edges[i].v, edges[i].w, mst );
		}

		buildLCA();
		for ( int i = 0 ; i < SZ ( unUsed ) ; i++ ){
			ma = -1;
			findLCA ( edges[unUsed[i]].u, edges[unUsed[i]].v );
			ans = min ( ans, edges[unUsed[i]].w - ma );
		}

		cout << ans << '\n';
	}
}