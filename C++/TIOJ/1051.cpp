// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
// #pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC optimize ( "O3" )
// #pragma GCC optimize ( "Ofast, unroll-loops, no-stack-protector" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define SP(a,b) swap ( a, b )
#define MEM(n,i) memset ( n, i, sizeof n )

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
typedef vector < int > vi;
typedef vector < LL > vl;
#define pb push_back
#define ep emplace_back
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear();
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) n.begin(), n.end()
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) n.find ( Index ) != n.end()

// greph
#define GRE(T,edge) vector < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vector < T > >;
template < class T > using MaxHeap = priority_queue < T >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 600

// create some usefull function
inline int changeStrToInt ( string str ){
	int res = 0;
	REPALL ( i, str ) res *= 10, res += ( int ) i - '0';
	return res;
}

inline string changeIntToStr ( int n ){
	string tmp, res;
	while ( n )
		tmp += ( char ) n % 10 + '0', n /= 10;

	REPM ( i, tmp.size() - 1, 0 ) res += tmp[i];

	return res;
}

#define LCM(a,b) abs ( a * b ) / __gcd ( a, b )

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

vi dp[maxN][maxN];

inline bool cmp ( int a, int b ){
	return a > b;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n;
	vi a, b, basic, tmp;
	cin >> t;
	while ( t-- ){
		cin >> n;
		RSZ ( basic, n );

		// a
		REPP ( i, 0, n ) cin >> basic[i];
		REPP ( i, 0, n ) REPP ( j, 0, n ) dp[i][j].pb ( 0 );
		tmp = basic;
		sort ( ALL ( tmp ), cmp );
		REPP ( i, 0, SZ ( basic ) + 1 ){
			REPP ( j, 0, SZ ( tmp ) + 1 ){
				if ( basic[i] == tmp[j] ){
					dp[i + 1][j + 1] = dp[i][j];
					dp[i + 1][j + 1].pb ( basic[i] );
				}
				else{
					if ( SZ ( dp[i][j + 1] ) == SZ ( dp[i + 1][j] ) ){
						if ( *( END ( dp[i][j + 1] ) - 1 ) > *( END ( dp[i + 1][j] ) - 1 ) )
							dp[i + 1][j + 1] = dp[i][j + 1];
						else
							dp[i + 1][j + 1] = dp[i + 1][j];
					}
					else if ( SZ ( dp[i][j + 1] ) < SZ ( dp[i + 1][j] ) )
						dp[i + 1][j + 1] = dp[i + 1][j];
					else
						dp[i + 1][j + 1] = dp[i][j + 1];
				}
			}
		}
		a = dp[SZ ( basic )][SZ ( tmp )];

		// b
		REPP ( i, 0, n ) cin >> basic[i];
		REPP ( i, 0, n ) REPP ( j, 0, n ) dp[i][j].pb ( 0 );
		tmp = basic;
		sort ( ALL ( tmp ), cmp );
		REPP ( i, 0, SZ ( basic ) ){
			REPP ( j, 0, SZ ( tmp ) ){
				if ( basic[i] == tmp[j] ){
					dp[i + 1][j + 1] = dp[i][j];
					dp[i + 1][j + 1].pb ( basic[i] );
				}
				else{
					if ( SZ ( dp[i][j + 1] ) == SZ ( dp[i + 1][j] ) ){
						if ( *( END ( dp[i][j + 1] ) - 1 ) > *( END ( dp[i + 1][j] ) - 1 ) )
							dp[i + 1][j + 1] = dp[i][j + 1];
						else
							dp[i + 1][j + 1] = dp[i + 1][j];
					}
					else if ( SZ ( dp[i][j + 1] ) < SZ ( dp[i + 1][j] ) )
						dp[i + 1][j + 1] = dp[i + 1][j];
					else
						dp[i + 1][j + 1] = dp[i][j + 1];
				}
			}
		}
		b = dp[SZ ( basic )][SZ ( tmp )];
		REPP ( i, 0, n ) REPP ( j, 0, n ) CLR ( dp[i][j] );

		// solve
		REPP ( i, 0, SZ ( a ) ){
			REPP ( j, 0, SZ ( b ) ){
				if ( a[i] == b[j] ){
					dp[i + 1][j + 1] = dp[i][j];
					dp[i + 1][j + 1].pb ( a[i] );
				}
				else{
					if ( SZ ( dp[i][j + 1] ) < SZ ( dp[i + 1][j] ) )
						dp[i + 1][j + 1] = dp[i + 1][j];
					else
						dp[i + 1][j + 1] = dp[i][j + 1];
				}
			}
		}

		cout << dp[SZ ( a )][SZ ( b )][1];
		REPP ( i, 2, dp[SZ ( a )][SZ ( b )].size() ) cout << ' ' << dp[SZ ( a )][SZ ( b )][i];
		cout << '\n';
	}
}