// /************************************/
// /* Date		: 2019-09-04 08:01:38	*/
// /* Author	: MiohitoKiri5474		*/
// /* Email	: lltzpp@gmail.com		*/
// /************************************/

// // by. MiohitoKiri5474
// #include<bits/stdc++.h>

// #pragma GCC optimize ( "O3" )
// #pragma loop_opt ( on )

// using namespace std;

// typedef long long LL;

// // define tools
// #define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
// #define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
// #define REPALL(i,n) for ( auto &i: n )
// #define debuger cout << "111\n"
// #define MEM(n,i) memset ( n, i, sizeof n )

// // define pair
// typedef pair < LL, LL > pll;
// typedef pair < int, int > pii;
// #define F first
// #define S second
// #define mp make_pair

// // define vector && some stl's api
// template < class T > using vec = vector < T >;
// typedef vec < int > vi;
// typedef vec < LL > vl;
// #define pb push_back
// #define eb emplace_back
// #define REV reverse
// #define SZ(n) ( int ) n.size()
// #define CLR(n) n.clear()
// #define BEG(n) n.begin()
// #define END(n) n.end()
// #define EMP(n) n.empty()
// #define RSZ(n,s) n.resize ( s )
// #define ALL(n) BEG ( n ), END ( n )
// #define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
// #define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// // define set
// typedef set < int > si;
// typedef set < LL > sl;
// #define FID(n,Index) ( n.find ( Index ) != n.end() )

// // graph
// #define GRE(T,edge) vec < T > edge[maxN]
// #define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
// #define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// // IO
// #define GL(n) getline ( cin, n )

// // define stack, queue, pri-queue
// template < class T > using stack = stack < T, vec < T > >;
// template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
// template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// // define stringstream
// #define sstr stringstream

// // number~ remember change maxN
// #define INF 0x3f3f3f3f
// #define NEG_INF 0x8f8f8f8f
// #define maxN 100005

// // あの日見渡した渚を　今も思い出すんだ
// // 砂の上に刻んだ言葉　君の後ろ姿
// // 寄り返す波が　足元をよぎり何かを攫う
// // 夕凪の中　日暮れだけが通り過ぎて行く

// // ready~ go!
// // let's go coding and have fun!
// // I can solve this problem!

// struct node{
// 	node *l, *r;
// 	int value, pri, sz, ma, mi;

// 	node ( int _val ){
// 		l = r = nullptr;
// 		mi = ma = value = _val, pri = rand(), sz = 1;
// 	}

// 	inline void up ( void ){
// 		sz = 1;
// 		mi = ma = value;
// 		if ( l ){
// 			ma = max ( ma, l -> ma );
// 			mi = min ( mi, l -> mi );
// 		}
// 		if ( r ){
// 			ma = max ( ma, r -> ma );
// 			mi = min ( mi, r -> mi );
// 		}
// 	}
// } *root;

// inline int Sz ( node *o ){
// 	return o ? o -> sz : 0;
// }

// node *merge ( node *a, node *b ){
// 	if ( !a || !b )
// 		return a ? a : b;
// 	if ( a -> pri > b -> pri ){
// 		a -> r = merge ( a -> r, b );
// 		a -> up();
// 		return a;
// 	}
// 	b -> l = merge ( a, b -> l );
// 	b -> up();
// 	return b;
// }

// void split ( node *o, node *&a, node *&b, int k ){
// 	if ( !o ){
// 		a = b = nullptr;
// 		return;
// 	}
// 	if ( Sz ( o -> l ) < k ){
// 		a = o;
// 		a -> r = split ( o -> l, a -> l, b, k - SZ ( o -> l ) - 1 );
// 		a -> up();
// 	}
// 	else{
// 		b = o;
// 		b -> l = split ( o -> r, a, b -> r, k );
// 		b -> up();
// 	}
// 	o -> up();
// }

// int main(){
// 	ios::sync_with_stdio ( false );
// 	cin.tie ( 0 );
// 	cout.tie ( 0 );

// 	int n, m, in, L, R;
// 	node *l, *r, *swp, *mid;
// 	cin >> n >> m;
// 	REPP ( i, 0, n ){
// 		cin >> in;
// 		root = merge ( root, new node ( in ) );
// 	}

// 	while ( m-- ){
// 		cin >> L >> r;
// 		split ( root, swp, r, R + 1 );
// 		split ( swp, l, mid, l );
// 		cout << mid -> ma - mid -> mi << '\n';

// 		root = merge ( l, merge ( mid, r ) );
// 	}
// }

////////////

#include<stdio.h>
#include<math.h>
#define maxN 100005

int seg[maxN << 2];

void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = fmax ( seg[leftSon], seg[rightSon] );
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

	return fmax ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
	int n, m, in, l, r;
	scanf ( "%d %d", &n, &m );
	n--;
	for ( int i = 0 ; i <= n ; i++ ){
		scanf ( "%d", &in );
		update ( 0, n, i, in, 1 );
	}

	while ( m-- ){
		scanf ( "%d %d", &l, &r );
		printf ( "%d\n", query ( l, r, 0, n, 1 ) );
	}
	for ( int i = 0 ; i <= n << 2 ; i++ ){
		printf ( "%d ", seg[i] );
	}
	puts ( "" );
}
