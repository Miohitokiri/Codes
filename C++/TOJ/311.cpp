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
#define maxN 15005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

vi seg[maxN << 2];

inline vi merge ( vi a, vi b ){
	vi res;
	int p = 0, q = 0;
	while ( p < SZ ( a ) || q < SZ ( b ) ){
		if ( p < SZ ( a ) && ( q >= SZ ( b ) || a[p] <= b[q] ) )
			res.pb ( a[p++] );
		else
			res.pb ( b[q++] );
	}
	return res;
}

inline void build ( int l, int r, int n ){
	if ( l == r ){
		int value;
		cin >> value;
		seg[n].pb ( value );
	}
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );
		seg[n] = merge ( seg[leftSon], seg[rightSon] );
	}
}

inline vi query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	else if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	else
		return merge ( query ( l, mid, nowL, mid, leftSon ), query ( mid + 1, r, mid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, p, cnt;
	LL ans;
	vi data;
	cin >> n >> q;
	build ( 1, n, 1 );
	while ( q-- ){
		cin >> l >> r;
		if ( l == r ){
			cout << 1 << '\n';
			continue;
		}
		data = query ( l, r, 1, n, 1 );
		ans = 0, p = -1, cnt = 0;
		REPALL ( i, data ){
			if ( i != p ){
				p = i;
				cnt++;
			}
			ans += cnt;
		}

		cout << ans << '\n';
	}
}