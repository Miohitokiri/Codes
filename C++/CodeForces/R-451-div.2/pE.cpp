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

	LL n, stop, zero, res;
	double d;
	cin >> n;
	vi data1, data2;
	REPP ( i, 0, n ){
		cin >> stop;
		d = sqrt ( stop );
		d == ( int ) d ? data1.pb ( stop ) : data2.pb ( stop );
	}

	n /= 2;
	if ( SZ ( data1 ) == SZ ( data2 ) )
		stop = 0;
	else if ( SZ ( data1 ) > n ){
		stop = SZ ( data1 ) - n;
		zero = 0;
		REPALL ( i, data1 ) if ( !i ) zero++;
		if ( zero > n ){
			zero -= n;
			stop += zero;
		}
	}
	else{
		CLR ( data1 );
		REPALL ( i, data2 ){
			res = sqrt ( i );
			stop = res + 1;
			data1.pb ( min ( i - res * res, stop * stop - i ) );
		}

		stop = 0;
		sort ( ALL ( data1 ) );
		REPP ( i, 0, SZ ( data2 ) - n ) stop += data1[i];
	}

	cout << stop << '\n';
}