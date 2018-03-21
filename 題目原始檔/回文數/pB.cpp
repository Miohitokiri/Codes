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
#define SP(a,b) swap ( a, b )
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
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) n.find ( Index ) != n.end()

// greph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 50005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

inline LL change ( string str ){
	LL res = 0;
	for ( auto i: str ){
		res *= 10;
		res += ( int ) i - '0';
	}

	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	vector < LL > data;
	set < string > sstr, tmp;
	LL n, res = 0, k;
	for ( string str = "1" ; str[0] <= '9' ; str[0]++ )
		sstr.insert ( str );
	sstr.insert ( "" );
	while ( SZ ( sstr ) <= 60005 ){
		REPALL ( i, sstr ){
			if ( SZ ( sstr ) >= 60005 )
				break;
			for ( char j = '0' ; j <= '9' && SZ ( sstr ) <= 60005 ; j++ )
				tmp.insert ( j + i + j );
		}

		REPALL ( i, tmp )
			sstr.insert ( i );
		CLR ( tmp );
	}

	REPALL ( i, sstr )
		if ( i[0] != '0' )
			data.pb ( change ( i ) );
	sort ( ALL ( data ) );

	// cout << SZ ( data ) << '\n';

	cin >> n >> k;
	REPP ( i, 1, n + 1 ){
		res += data[i];
		res %= k;
	}
	cout << res << '\n';
}