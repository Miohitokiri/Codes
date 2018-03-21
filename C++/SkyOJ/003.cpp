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
#define debuger cout << "111\n";
#define SP(a,b) swap ( a, b )
#define mem(n,i) memset ( n, i, sizeof n )

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
#define ALL(n) ( BEG ( n ), END ( n ) )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n';

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
#define maxN 100005

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

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string str;
	LL res;
	while ( GL ( str ) ){
		res = 0;
		sstr ss ( str );
		while ( ss >> str )
			if ( '0' <= str[0] && str[0] <= '9' )
				res += changeStrToInt ( str );
		cout << res << '\n';
	}
}