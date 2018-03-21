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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
LL n, m, r, k, ans;
set < pii > used;

inline LL val ( pii a ){
	LL i = a.F, j = a.S;
	return 1LL * ( min ( n - r + 1, i ) - max ( i - r + 1, 1LL ) + 1 ) * ( min ( m - r + 1, j ) - max ( j - r + 1, 1LL ) + 1 );
}

class cmp{
public:
	bool operator() ( pii a, pii b ) const {
		return val ( a ) < val ( b );
	}
};

inline bool valid ( pii x ){
	return 1 <= x.F && x.F <= n && 1 <= x.S && x.S <= m;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	cin >> n >> m >> r >> k;
	used.insert ( pii ( ( n + 1 ) / 2, ( m + 1 ) / 2 ) );
	priority_queue < pii, vec < pii >, cmp > pq;
	pii now, tmp;
	pq.push ( pii ( ( n + 1 ) / 2, ( m + 1 ) / 2 ) );
	while ( k-- ){
		now = pq.top();
		pq.pop();
		ans += val ( now );
		REPP ( i, 0, 4 ){
			tmp = now;
			tmp.F += dx[i];
			tmp.S += dy[i];
			if ( !valid ( tmp ) || FID ( used, tmp ) )
				continue;
			used.insert ( tmp );
			pq.push ( tmp );
		}
	}

	cout << fixed << setprecision ( 15 ) << ( long double ) ans / ( ( n - r + 1 ) * ( m - r + 1 ) ) << '\n';
}