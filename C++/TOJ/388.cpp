// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto i: n )
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
#define PIO(n) REPALL ( w, n ) cout << w << ' '; cout << '\n'
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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

vec < bool > bin;

inline int change ( char i ){
	if ( '0' <= i && i <= '9' )
		return ( int ) i - '0';
	return ( int ) i - 'a' + 10;
}

inline void www ( string str ){
	REV ( ALL ( str ) );
	int n;
	REPALL ( i, str ){
		n = change ( i );
		REPP ( tms, 0, 4 ){
			bin.pb ( n % 2 );
			n >>= 1;
		}
	}
}

inline bool check ( int k ){
	int sum = 0;
	for ( int i = 0 ; i < SZ ( bin ) ; i += k ){
		if ( sum >= 3 )
			return true;
		if ( !bin[i] ){
			sum = 0;
			continue;
		}

		bool www = true;
		for ( int j = i + 1 ; j < i + k && j < SZ ( bin ) ; j++ )
			if ( bin[j] ){
				www = false;
				break;
			}

		if ( www )
			sum++;
		else
			sum = 0;
	}

	return sum >= 3;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str;
	cin >> str;
	www ( str );

	for ( int i = 1 ; i < SZ ( bin ) / 3 + 1 ; i++ )
		if ( check ( i ) )
			cout << i << '\n';
}