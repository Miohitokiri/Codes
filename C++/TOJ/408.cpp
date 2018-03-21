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

GRE ( int, edge );
int deg[maxN], sz, visited[maxN], dep;

inline void dfs ( int n ){
	if ( visited[n] == dep || deg[n] <= 0 )
		return;
	sz++;
	visited[n] = dep;
	REPALL ( i, edge[n] ){
		if ( visited[i] != dep )
			dfs ( i );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, ma = -1, mi = INF, Index;
	vi data;
	cin >> n >> m;
	n++;
	while ( m-- ){
		cin >> u >> v;
		UNI ( u, v, edge );
	}

	REPP ( i, 1, n ){
		deg[i] = SZ ( edge[i] );
		if ( deg[i] > 0 ){
			data.pb ( i );
			mi = min ( mi, deg[i] );
		}
	}
	REPP ( i, 1, n ){
		if ( deg[i] == mi ){
			dep++;
			sz = 0;
			dfs ( i );
			ma = max ( ma, sz * mi );
		}
	}

	REPP ( i, 1, n ){
		mi = INF;
		REPALL ( i, data ){
			if ( mi > deg[i] && deg[i] > 0 ){
				mi = deg[i];
				Index = i;
			}
		}

		if ( mi >= n )
			continue;
		REPALL ( i, edge[Index] ) deg[i]--;
		deg[Index] = 0;
		data.erase ( lower_bound ( ALL ( data ), Index ) );

		mi = INF;
		REPALL ( i, data ){
			if ( mi > deg[i] && deg[i] > 0 ){
				mi = deg[i];
				Index = i;
			}
		}

		if ( mi >= n )
			continue;
		dep++;
		sz = 0;
		dfs ( Index );
		ma = max ( ma, sz * mi );
	}

	cout << ma << '\n';
}