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
#define maxN 300005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int segL[maxN << 2], segR[maxN << 2];

void updateL ( int l, int r, int index, int value, int n ){
	if ( l == r )
		segL[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			updateL ( l, mid, index, value, leftSon );
		else
			updateL ( mid + 1, r, index, value, rightSon );

		segL[n] = max ( segL[leftSon], segL[rightSon] );
	}
}

int queryL ( int l, int r, int nowL, int nowR, int n ){
	if ( r < l )
		return NEG_INF;
	if ( l <= nowL && nowR <= r )
		return segL[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return queryL ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return queryL ( l, r, mid + 1, nowR, rightSon );
	return max ( queryL ( l, r, nowL, mid, leftSon ), queryL ( l, r, mid + 1, nowR, rightSon ) );
}

void updateR ( int l, int r, int index, int value, int n ){
	if ( l == r )
		segR[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			updateR ( l, mid, index, value, leftSon );
		else
			updateR ( mid + 1, r, index, value, rightSon );

		segR[n] = min ( segR[leftSon], segR[rightSon] );
	}
}

int queryR ( int l, int r, int nowL, int nowR, int n ){
	if ( r < l )
		return INF;
	if ( l <= nowL && nowR <= r )
		return segR[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return queryR ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return queryR ( l, r, mid + 1, nowR, rightSon );
	return min ( queryR ( l, r, nowL, mid, leftSon ), queryR ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, ans = 0;
	cin >> n;
	vec < pii > data ( n );
	REPALL ( i, data ){
		cin >> i.F >> i.S;
	}
	sort ( ALL ( data ) );
	REPP ( i, 0, n ){
		updateL ( 0, n - 1, i, data[i].F, 1 );
		updateR ( 0, n - 1, i, data[i].S, 1 );
	}

	cout << '\n';
	REPP ( i, 0, n ) ans = max ( ans, min ( queryR ( 0, i - 1, 0, n - 1, 1 ), queryR ( i + 1, n - 1, 0, n - 1, 1 ) ) - max ( queryL ( 0, i - 1, 0, n - 1, 1 ), queryL ( i + 1, n - 1, 0, n - 1, 1 ) ) );

	cout << ans << '\n';
}