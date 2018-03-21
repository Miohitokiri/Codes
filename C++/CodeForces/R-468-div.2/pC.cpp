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
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, in, m = 0, z = 0, p = 0, one, two, tmp, ma, mi;
	vi basic;
	cin >> n >> in;
	ma = mi = in;
	basic.pb ( in );
	REPP ( i, 1, n ){
		cin >> in;
		ma = max ( ma, in );
		mi = min ( mi, in );
		basic.pb ( in );
	}
	if ( ma - mi != 2 ){
		cout << n << '\n';
		PIO ( basic );
		return 0;
	}
	REPALL ( i, basic ){
		if ( i == mi )
			m++;
		else if ( i == ma )
			p++;
		else
			z++;
	}
	one = z % 2 + m + p, two = abs ( m - p ) + z;
	if ( one < two ){
		p += z / 2;
		m += z / 2;
		z %= 2;
		cout << one << '\n';
	}
	else{
		tmp = min ( m, p );
		z += tmp * 2;
		p -= tmp;
		m -= tmp;
		cout << two << '\n';
	}

	while ( m-- )
		cout << mi << ' ';
	mi++;
	while ( z-- )
		cout << mi << ' ';
	while ( p-- )
		cout << ma << ' ';
	cout << '\n';
}