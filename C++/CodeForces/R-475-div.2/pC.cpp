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

const LL mod = 1000000009;

inline LL Pow ( LL a, LL b ){
	LL res = 1, base = a;
	while ( b ){
		if ( b & 1 ){
			res *= base;
			res %= mod;
		}

		base *= base;
		base %= mod;
		b >>= 1;
	}

	return res;
}

inline LL add ( int a, int b ){
	return a + b >= mod ? a + b - mod : a + b;
}

inline LL mul ( int a, int b ){
	return ( a * b ) % mod;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	// auto tms = clock(); // del
	LL n, a, b, k, ans = 0, now, w = 1, ww = 1, xd, A, aInv, base = 0, aInvPow, bPow;
	string data;
	cin >> n >> a >> b >> k >> data;
	xd = n + 1;
	A = Pow ( a, n );
	aInv = Pow ( a, mod - 2 );

	if ( k == 1 ){
		REPP ( i, 0, xd ){
			ans += ( ( data[0] == '+' ? 1 : -1 ) * A * ww ) % mod;
			ans %= mod;
			A *= aInv;
			A %= mod;
			ww *= b;
			ww %= mod;
		}

		if ( ans < 0 )
			ans += mod;

		cout << ans << '\n';
		return 0;
	}

	ww = 1;
	REPALL ( i, data ){
		now = ( i == '+' ? 1 : -1 );
		now *= A;
		now %= mod;
		A *= aInv;
		A %= mod;
		now *= ww;
		now %= mod;
		ww *= b;
		ww %= mod;

		base += now;
		base %= mod;
	}

	if ( n <= k ){
		if ( base < 0 )
			base += mod;
		cout << base << '\n';
		return 0;
	}

	ww = 1;
	aInvPow = Pow ( aInv, k );
	bPow = Pow ( b, k );
	A = Pow ( a, n - k + 1 );
	REPP ( i, 0, n / k ){
		ans += ( A * ww ) % mod;
		ans %= mod;

		A *= aInvPow;
		A %= mod;

		ww *= bPow;
		ww %= mod;
	}
	ans *= base;
	ans %= mod;

	A = Pow ( a, n - int ( n / k ) * k );
	ww = Pow ( b, int ( n / k ) * k );
	for ( int i = int ( n / k ) * k + 1 ; i <= n ; i++ ){
		ans += ( ( data[i % k] == '+' ? 1 : -1 ) * A * ww ) % mod;
		ans %= mod;

		A *= aInv;
		A %= mod;

		ww *= b;
		ww %= mod;
	}

	if ( ans < 0 )
		ans += mod;

	cout << ans << '\n';
}