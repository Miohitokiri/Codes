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
#define maxN 200010

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

GRE ( int, edges );
int where[maxN], value[maxN], link[maxN], pa[maxN], D[maxN], cnt, seg[maxN << 2], siz[maxN], maxSon[maxN];

inline void init ( void ){
	REPALL ( i, edges ) CLR ( i );
	MEM ( where, -1 );
	MEM ( value, NEG_INF );
	MEM ( D, 0 );
	MEM ( maxSon, -1 );
	cnt = 0;
}

inline void findMaxSon ( int u ){
	siz[u] = 1;
	maxSon[u] = -1;
	REPALL ( i, edges[u] ){
		if ( i == pa[u] )
			continue;
		pa[i] = u;
		D[i] = D[u] + 1;
		findMaxSon ( i );
		if ( maxSon[u] == -1 || siz[i] > siz[maxSon[u]] )
			maxSon[u] = i;
		siz[u] += siz[i];
	}
}

inline void dfs ( int n, int p ){
	link[n] = p;
	where[n] = ++cnt;
	if ( maxSon[n] == -1 )
		return;
	dfs ( maxSon[n], p );
	REPALL ( i, edges[n] ){
		if ( i == maxSon[n] || i == pa[n] )
			continue;
		dfs ( i, i );
	}
}

inline void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

inline int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return max ( query ( l, r, mid + 1, nowR, rightSon ), query ( l, r, nowL, mid, leftSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, u, v, uPa, vPa, ma, N;
	string type;
	cin >> t;
	while ( t-- ){
		cin >> n;
		N = n << 1;
		N--;
		init();
		REPP ( i, 1, n ){
			cin >> u >> v >> value[n + i];
			UNI ( u, n + i, edges );
			UNI ( n + i, v, edges );
		}

		pa[1] = 1;
		findMaxSon ( 1 );
		dfs ( 1, 1 );
		// return 0;
		REPP ( i, 1, ( n << 1 ) ){
			update ( 1, N, where[i], value[i], 1 );
		}
		while ( cin >> type ){
			if ( type == "DONE" )
				break;
			cin >> u >> v;
			if ( type == "QUERY" ){
				uPa = u, vPa = v;
				ma = -1;
				int ccc = 0;

				while ( link[vPa] != link[uPa] ){
					if ( D[link[vPa]] > D[link[uPa]] ){
						// cout << query ( where[pa[link[vPa]]], where[vPa], 1, N, 1 ) << '\n';
						ma = max ( ma, query ( where[link[vPa]], where[vPa], 1, N, 1 ) );
						vPa = pa[link[vPa]];
					}
					else{
						// cout << query ( where[pa[link[uPa]]], where[uPa], 1, N, 1 ) << '\n';
						ma = max ( ma, query ( where[link[uPa]], where[uPa], 1, N, 1 ) );
						uPa = pa[link[uPa]];
					}
				}

				if ( D[uPa] > D[vPa] )
					swap ( uPa, vPa );
				cout << max ( ma, query ( where[uPa], where[vPa], 1, N, 1 ) ) << '\n';
			}
			else
				update ( 1, N, where[n + u], v, 1 );
		}
	}
}