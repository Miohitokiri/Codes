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
#define maxN 200005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int value[maxN], seg[maxN << 2], D[maxN], link[maxN], sz[maxN], ma[maxN], pos[maxN], pa[maxN], idx, rg;
GRE ( int, edges );

inline void init ( void ){
	REPALL ( i, edges ){
		CLR ( i );
	}
	MEM ( ma, -1 );
	MEM ( pos, -1 );
	MEM ( D, -1 );
	MEM ( value, NEG_INF );
	MEM ( pa, -1 );
	idx = 0;
}

void update ( int l, int r, int index, int value, int n ){
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

int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

void dfs ( int n ){
	sz[n] = 1;
	REPALL ( i, edges[n] ){
		if ( i == pa[n] )
			continue;
		pa[i] = n;
		D[i] = D[n] + 1;
		dfs ( i );
		if ( ma[n] == -1 || sz[ma[n]] < sz[i] )
			ma[n] = i;
		sz[n] += sz[i];
	}
}

void build ( int n, int p ){
	link[n] = p;
	pos[n] = idx++;
	if ( ma[n] == -1 )
		return;
	REPALL ( i, edges[n] ){
		if ( i == pa[n] )
			continue;
		build ( i, i );
	}
}

inline int LCA ( int u, int v ){
	if ( D[u] > D[v] )
		swap ( u, v );
	int ma = -1;
	while ( link[u] != link[v] ){
		if ( D[u] > D[v] ){
			ma = max ( ma, query ( pos[link[u]], pos[u], 0, rg, 1 ) );
			u = pa[link[u]];
		}
		else{
			ma = max ( ma, query ( pos[link[v]], pos[v], 0, rg, 1 ) );
			v = pa[link[v]];
		}
	}

	if ( D[u] > D[v] )
		swap ( u, v );
	return max ( ma, query ( pos[u], pos[v], 0, rg, 1 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, u, v, w, l, r;
	string tp;
	cin >> t;
	while ( t-- ){
		cin >> n;
		init();
		REPP ( i, 1, n ){
			cin >> u >> v >> w;
			value[n + i] = w;
			UNI ( u, n + i, edges );
			UNI ( n + 1, v, edges );
		}

		pa[1] = D[1] = 0;
		dfs ( 1 );
		build ( 1, 1 );

		rg = idx - 1;
		REPP ( i, 0, idx ){
			update ( 0, rg, pos[i], value[i], 1 );
		}

		while ( cin >> tp ){
			if ( tp == "DONE" )
				break;
			cin >> l >> r;
			if ( tp == "CHANGE" )
				update ( 0, rg, pos[l], r, 1 );
			else
				cout << LCA ( l, r ) << '\n';
		}
	}
}