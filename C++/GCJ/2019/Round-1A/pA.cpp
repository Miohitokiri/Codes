/************************************/
/* Date		: 2019-04-13 08:48:50	*/
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
#define maxN 30

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int vis[maxN][maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, r, c, x, y, cnt, n, sr, sc, px, py;
	vec < pii > ans;
	si used;
	cin >> t;
	for ( int tms = 1 ; tms <= t ; tms++ ){
		cin >> r >> c;
		if ( r == c && c == 2 ){
			cout << "Case #" << tms << ": IMPOSSIBLE\n";
			continue;
		}
		sr = r / 2, sc = c / 2;
		x = y = 0;
		if ( r & 1 )
			sr++;
		if ( r == c )
			sc = c - sr - 1;
		else if ( c & 1 )
			sc++;
		n = r * c;
		CLR ( ans );
		MEM ( vis, 0 );
		REPP ( i, 0, n ){
			if ( vis[x][y] ){
				if ( !vis[x + 1][y] )
					x++;
				else if ( !vis[x][y + 1] )
					y++;
				else if ( !vis[x + 1][y + 1] )
					x++, y++;
				else
					break;
				x %= r, y %= c;
			}
			ans.pb ( pii ( x + 1, y + 1 ) );
			vis[x][y] = i + 1;
			px = x, py = y;
			x = ( x + 1 ) % r, y = ( y + 2 ) % c;
			CLR ( used );
			while ( abs ( py - y ) <= 1 ){
				used.insert ( y );
				y = ( y + 1 ) % c;
				if ( SZ ( used ) == c )
					break;
			}
			if ( SZ ( used ) == c )
				break;
			// cout << x << ' ' << y << '\n';
		}

		cout << "Case #" << tms << ": ";
		if ( SZ ( ans ) == n ){
			cout << "POSSIBLE\n";
			REPALL ( i, ans ){
				cout << i.F << ' ' << i.S << '\n';
			}
		}
		else
			cout << "IMPOSSIBLE\n";
		// REPP ( i, 0, r ){
		// 	REPP ( j, 0, c ){
		// 		if ( vis[i][j] < 10 )
		// 			cout << ' ';
		// 		cout << vis[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
	}
}