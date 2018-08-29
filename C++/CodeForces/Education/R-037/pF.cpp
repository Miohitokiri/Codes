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
#define maxN 300005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

LL sum[maxN << 2], dp[1000005];
bool used[maxN << 2];
vi prime;
bitset < 1005 > lib;

inline int D ( int n ){
	if ( dp[n] != -1 )
		return dp[n];
	double www = sqrt ( n );
	int ma = www, res = 0, maa = ma + 1;
	REPP ( i, 1, maa ) n % i ? res : res++;

	return dp[n] = res * 2 - ( www == ma ? 1 : 0 );
}

inline void build ( int l, int r, int n ){
	if ( l == r ){
		cin >> sum[n];
		used[n] = ( sum[n] > 2 );
	}
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );

		sum[n] = sum[leftSon] + sum[rightSon];
		used[n] = ( used[leftSon] || used[rightSon] );
	}
}

inline LL query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return sum[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return query ( l, r, nowL, mid, leftSon ) + query ( l, r, mid + 1, nowR, rightSon );
}

inline void modify ( int l, int r, int nowL, int nowR, int n ){
	if ( !used[n] )
		return;
	if ( nowL == nowR ){
		sum[n] = D ( sum[n] );
		used[n] = ( sum[n] > 2 );
	}
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

		sum[n] = sum[leftSon] + sum[rightSon];
		used[n] = ( used[leftSon] || used[rightSon] );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	lib[0] = lib[1] = true;
	REPP ( i, 2, 1005 ){
		if ( !lib[i] ){
			prime.pb ( i );
			for ( int j = i << 1 ; j < 1005 ; j += i )
				lib[j] = true;
		}
	}

	MEM ( dp, -1 );
	int n, m, type, l, r, stop;
	cin >> n >> m;
	build ( 1, n, 1 );

	while ( m-- ){
		cin >> type >> l >> r;
		if ( type == 1 )
			modify ( l, r, 1, n, 1 );
		else
			cout << query ( l, r, 1, n, 1 ) << '\n';
	}
}