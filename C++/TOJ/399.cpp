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

inline LL change ( char i ){
	int res = 0;
	string www;
	if ( i == 'A' )
		res += 10;
	else if ( i == 'B' )
		res += 11;
	else if ( i == 'C' )
		res += 12;
	else if ( i == 'D' )
		res += 13;
	else if ( i == 'E' )
		res += 14;
	else if ( i == 'F' )
		res += 15;
	else
		res += ( int ) i - '0';

	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string a, b, data = "0123456789ABCDEF";
	vi x, y, ans;
	int z = -1;
	cin >> a >> b;
	if ( a == b ){
		cout << 0 << '\n';
		return 0;
	}
	if ( SZ ( a ) > SZ ( b ) )
		swap ( a, b );
	REPALL ( i, a ) x.pb ( change ( i ) );
	REPALL ( i, b ) y.pb ( change ( i ) );
	REV ( ALL ( x ) );
	REV ( ALL ( y ) );
	REPP ( i, 0, SZ ( x ) ){
		ans.pb ( x[i] ^ y[i] );
	}
	REPP ( i, SZ ( x ), SZ ( y ) ) ans.pb ( y[i] );
	REV ( ALL ( ans ) );
	REPP ( i, 0, SZ ( ans ) ){
		if ( ans[i] != 0 ){
			z = i;
			break;
		}
	}
	REPP ( i, z, SZ ( ans ) ){
		cout << data[ans[i]];
	}
	cout << '\n';
}