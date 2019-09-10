/************************************/
/* Date		: 2019-09-05 15:45:56	*/
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
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

vi data[15];
int sum[15];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	// 1
	REPP ( i, 1, 10 ){
		data[1].pb ( i );
		sum[1] += i;
	}
	data[1].pb ( 0 );

	// debuger; // del

	// 2
	for ( int i = 2 ; i <= 10 ; i += 2 ){
		if ( i >= 10 )
			i %= 10;
		data[2].pb ( i );
		sum[2] += i;
		if ( !i )
			break;
	}

	// cout << "222\n"; // del

	// 3
	for ( int i = 3 ; i ; i += 3 ){
		if ( i >= 10 )
			i %= 10;
		data[3].pb ( i );
		sum[3] += i;
		if ( !i )
			break;
	}

	// cout << "333\n"; // del

	//4
	for ( int i = 4 ; i ; i += 4 ){
		if ( i >= 10 )
			i %= 10;
		data[4].pb ( i );
		sum[4] += i;
		if ( !i )
			break;
	}

	// cout << "444\n"; // del

	// 5
	for ( int i = 5 ; i < 10 ; i += 5 ){
		data[5].pb ( i );
		sum[5] += i;
	}
	data[5].pb ( 0 );

	// cout << "555\n"; // del

	// 6
	int cnt = 0;
	for ( int i = 6 ; i ; i += 6 ){
		if ( i >= 10 )
			i %= 10;
		data[6].pb ( i );
		sum[6] += i;
		if ( !i )
			break;
	}

	// cout << "666\n"; // del

	// 7
	for ( int i = 7 ; i ; i += 7 ){
		if ( i >= 10 )
			i %= 10;
		data[7].pb ( i );
		sum[7] += i;
		if ( !i )
			break;
	}

	// cout << "777\n"; // del

	// 8
	for ( int i = 8 ; i ; i += 8 ){
		if ( i >= 10 )
			i %= 10;
		data[8].pb ( i );
		sum[8] += i;
		if ( !i )
			break;
	}

	// cout << "888\n"; // del

	// 9
	REPM ( i, 9, 0 ){
		data[9].pb ( i );
		sum[9] += i;
	}

	// cout << "999\n"; // del

	LL t, n, m, ans, div;
	cin >> t;
	while ( t-- ){
		cin >> n >> m;
		ans = 0;
		if ( n < m ){
			cout << "0\n";
			continue;
		}
		div = n / m;
		m %= 10;

		if ( !m ){
			cout << "0\n";
			continue;
		}

		ans = sum[m] * ( div / SZ ( data[m] ) );
		div %= SZ ( data[m] );
		REPP ( i, 0, div ){
			ans += data[m][i];
		}

		cout << ans << '\n';
	}
}

/*
0
45
153
294
3359835
0
427262129093995

1
45
153
294
3359835
0
427262129093995
*/