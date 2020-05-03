/************************************/
/* Date		: 2020-05-03 08:45:07	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; ++i )
#define REPM(i,f,s) for ( int i = f ; i >= s ; --i )
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
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

struct node1D{
    int seg[maxN << 2];
	void update ( int, int, int, int, int );
    int query ( int, int, int, int, int );
};

void node1D::update ( int l, int r, int index, int value, int n ){
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

int node1D::query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );

	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

struct node2D{
	node1D seg[maxN << 2];
	int n;

	void update ( int, int, int, int, int, int );
	int query ( int, int, int, int, int, int, int );
	node1D merge ( int, int, int, int, int );
};

void node2D::update ( int l, int r, int idX, int idY, int value, int n ){
	if ( l == r )
		seg[n].update ( 1, n, idY, value, 1 );
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( idX <= mid )
			update ( l, mid, idX, idY, value, leftSon );
		else
			update ( mid + 1, r, idX, idY, value, rightSon );

		merge ( )
	}
}

int node2D::query ( int l, int r, int u, int d, int nowL, int nowR, int n ){
}

node1D node2D::merge ( int a, int b, int l, int r, int n ){
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	node1D seg;
	int n, m, l, r, in, type;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> in;
		seg.update ( 1, n, i, in, 1 );
	}
	while ( m-- ){
		cin >> type >> l >> r;
		if ( type == 1 )
			seg.update ( 1, n, l, r, 1 );
		else
			cout << seg.query ( l, r, 1, n, 1 ) << '\n';
	}
}