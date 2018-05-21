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
#define maxN 200005

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

struct node{
	int tag, sz;
	// bool tf;

	inline int extra ( void ){
		// return tf ? tag : 0;
		return tag * sz;
	}
} seg[maxN << 2];

GRE ( int, edges );
int value[maxN], where[maxN], maxSon[maxN], pa[maxN], D[maxN], siz[maxN], link[maxN];
int cnt;

inline void update ( int l, int r, int index, int value, int n, int idx ){
	if ( l == r )
		seg[n] = node { 0, idx/*, bool ( idx )*/ };
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon, idx );
		else
			update ( mid + 1, r, index, value, rightSon, idx );

		seg[n].sz = seg[leftSon].sz + seg[rightSon].sz;
	}
}

inline void push ( int n, int l, int r ){
	if ( l == r )
		return;
	int leftSon = n << 1, rightSon = leftSon | 1, mid = ( l + r ) >> 1;
	// if ( seg[leftSon].sz ){
		seg[leftSon].tag += seg[n].tag;
		push ( leftSon, l, mid );
	// }
	// if ( seg[rightSon].sz ){
		seg[rightSon].tag += seg[n].tag;
		push ( rightSon, mid + 1, r );
	// }
	seg[n].tag = 0;
}

inline int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n].extra();
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1, res = seg[n].tag * ( r - l );
	if ( r <= mid )
		res += query ( l, r, nowL, mid, leftSon );
	else if ( mid < l )
		res += query ( l, r, mid + 1, nowR, rightSon );
	else
		res += query ( mid + 1, r, mid + 1, nowR, rightSon ) + query ( l, mid, nowL, mid, leftSon );

	return res;
}

inline void modify ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		seg[n].tag++;
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( r <= mid )
			modify ( l, r, nowL, mid, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, rightSon );
		else{
			modify ( l, r, nowL, mid, leftSon );
			modify ( l, r, mid + 1, nowR, rightSon );
		}
	}
}

inline void findMaxSon ( int u, int dep ){
	siz[u] = 1;
	maxSon[u] = -1;
	D[u] = dep++;
	REPALL ( i, edges[u] ){
		if ( i == pa[u] )
			continue;
		pa[i] = u;
		findMaxSon ( i, dep );
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
		if ( i == pa[n] || i == maxSon[n] )
			continue;
		dfs ( i, i );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, N, uPa, vPa, ans;
	char type;
	cin >> n >> m;
	N = n << 1;
	REPP ( i, 1, n ){
		cin >> u >> v;
		UNI ( u, n + i, edges );
		UNI ( n + i, v, edges );
	}

	pa[1] = 1;
	findMaxSon ( 1, 1 );
	dfs ( 1, 1 );
	REPP ( i, 1, n + 1 ) update ( 1, N, where[i], 0, 1, 0 );
	REPP ( i, n + 1, N ) update ( 1, N, where[i], 0, 1, 1 );

	N--;

	while ( m-- ){
		cin >> type >> u >> v;
		uPa = u, vPa = v;
		if ( type == 'P' ){
			if ( D[uPa] < D[vPa] )
				swap ( uPa, vPa );
			// uPa = pa[uPa];
			while ( link[uPa] != link[vPa] ){
				if ( D[link[uPa]] > D[link[vPa]] ){
					modify ( where[link[uPa]], where[uPa], 1, N, 1 );
					uPa = pa[link[uPa]];
				}
				else{
					modify ( where[link[vPa]], where[vPa], 1, N, 1 );
					vPa = pa[link[vPa]];
				}
			}
			if ( D[uPa] > D[vPa] )
				swap ( uPa, vPa );
			modify ( where[uPa], where[vPa], 1, N, 1 );
		}
		else{
			ans = 0;
			// push ( 1, 1, N );
			if ( D[uPa] < D[vPa] )
				swap ( uPa, vPa );
			// uPa = pa[uPa];
			while ( link[uPa] != link[vPa] ){
				if ( D[link[uPa]] > D[link[vPa]] ){
					ans += query ( where[link[uPa]], where[uPa], 1, N, 1 );
					uPa = pa[link[uPa]];
				}
				else{
					ans += query ( where[link[vPa]], where[vPa], 1, N, 1 );
					vPa = pa[link[vPa]];
				}
			}

			if ( D[uPa] > D[vPa] )
				swap ( uPa, vPa );
			ans += query ( where[uPa], where[vPa], 1, N, 1 );
			cout << ans << '\n';
		}
	}
}