/************************************/
/* Date		: 2019-12-21 20:29:39	*/
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
#define maxN 200005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

vec < char > lib[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, k;
	char c;
	string str, ans;
	cin >> n >> k >> str;
	ans = str;
	if ( str[0] == '9' ){
		ans[0] = '1';
		ans += '9';
	}
	for ( int i = 0 ; i < k ; i++ ){
		c = '9';
		for ( int j = i ; j < n ; j += k ){
			lib[i].pb ( str[j] );
			c = min ( c, str[j] );
		}
		for ( int j = i ; j < n ; j += k )
			ans[j] = c;
		REV ( ALL ( lib[i] ) );
	}
	if ( ans[0] == '0' )
		for ( int i = 0 ; i < n ; i += k )
			ans[i] = '1';

	int idx = 0;
	while ( ans < str ){
		for ( ; idx < n ; idx++ ){
			if ( ans[idx] < str[idx] ){
				// idx--;
				for ( int j = idx % k ; j < n ; j += k )
					ans[j] = str[idx];
				break;
			}
		}
		// cout << "----\n" << ans << '\n' << str << '\n';
	}
	cout << SZ ( ans ) << '\n' << ans << '\n';

	// output
	// for ( int i = 0 ; i < k ; i++ )
	// 	REV ( ALL ( lib[i] ) );
	// for ( int i = 0 ; i < n / k ; i++ )
	// 	for ( int j = 0 ; j < k ; j++ )
	// 		cout << lib[j][i];

	// int sz = SZ ( lib[0] );
	// for ( int i = 0 ; i < k && SZ ( lib[i] ) == sz ; i++ )
	// 	cout << lib[i].back();
	// cout << '\n';
}