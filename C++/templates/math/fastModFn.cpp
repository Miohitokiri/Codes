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
#define mod 1000000007

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

#define int LL

struct node{
	LL m[2][2];
} ans, base;

inline node multi ( node a, node b ){
	node res;
	MEM ( res.m, 0 );
	REPP ( i, 0, 2 ){
		REPP ( j, 0, 2 ){
			REPP ( k, 0, 2 ){
				res.m[i][j] += a.m[i][k] * b.m[k][j] % mod;
				res.m[i][j] %= mod;
			}
		}
	}

	return res;
}

inline void fashPow ( int n, int a, int b, int x1, int x2 ){
	base.m[0][0] = b, base.m[0][1] = 1, base.m[1][0] = a, base.m[1][1] = 0;

	ans.m[0][0] = ans.m[1][1] = 1, ans.m[0][1] = ans.m[1][0] = 0;

	while ( n ){
		if ( n & 1 )
			ans = multi ( ans, base );
		base = multi ( base, base );
		n >>= 1;
	}
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	LL x1, x2, a, b, n, w = 0;
	cin >> x1 >> x2 >> a >> b >> n;
	n--;
	fashPow ( n, a, b, x1, x2 );
	w = x2 * ( ans.m[0][1] ) % mod;
	w += x1 * ( ans.m[1][1] ) % mod;
	w %= mod;
	cout << w << '\n';
}
