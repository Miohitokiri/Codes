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
#define SP(a,b) swap ( a, b )
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
#define maxN 505

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

struct bridge{
	int u, v, w;
};
vec < bridge > edges;

int dis[maxN];

inline void Init ( void ){
	REPP ( i, 0, maxN ) dis[i] = i;
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

inline bool cmp ( bridge a, bridge b ){
	return a.w < b.w;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, ansCnt = 0, ansSum = 0, sum, cnt = 0, basicSum = 0;
	bridge in;
	vec < int > id;
	cin >> n >> m;
	REPP ( i, 0, m ){
		cin >> in.u >> in.v >> in.w;
		edges.pb ( in );
	}

	n--;
	Init();
	sort ( ALL ( edges ), cmp );
	REPP ( i, 0, m ){
		if ( cnt == n )
			break;
		if ( same ( edges[i].u, edges[i].v ) )
			continue;
		Union ( edges[i].u, edges[i].v );
		id.pb ( i );
		basicSum += edges[i].w, cnt++;
	}

	if ( cnt == n ){
		REPALL ( idx, id ){
			Init();
			cnt = sum = 0;
			REPP ( i, 0, m ){
				if ( cnt == n )
					break;
				if ( same ( edges[i].u, edges[i].v ) || i == idx )
					continue;

				Union ( edges[i].u, edges[i].v );
				sum += edges[i].w, cnt++;
			}

			if ( cnt != n || sum > basicSum )
				ansCnt++, ansSum += edges[idx].w;
		}
	}

	cout << ansCnt << ' ' << ansSum << '\n';
}