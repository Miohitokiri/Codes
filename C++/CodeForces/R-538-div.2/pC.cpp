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
#define maxN 1000010

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

vl prime;
bitset < maxN > lib;

inline LL count ( LL n, LL pp ){
	LL res = 0;
	while ( n ){
		res += n / pp;
		n /= pp;
	}

	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	#define int LL

	LL n, b, ans = 9223372036854775807, cnt, stp, m, p, cnt2;
	vl data, num, swp;
	cin >> n >> b;
	m = sqrt ( b ) + 10;
	lib[0] = lib[1] = true;
	for ( LL i = 2 ; i <= m ; i++ ){
		if ( lib[i] )
			continue;
		prime.pb ( i );
		for ( LL j = i * 2 ; j <= m ; j += i ){
			lib[j] = true;
		}
	}

	REPALL ( i, prime ){
		if ( b < i || b == 1 || !b )
			break;
		cnt = 0;
		while ( b % i == 0 ){
			b /= i;
			cnt++;
		}
		if ( cnt ){
			data.pb ( i );
			num.pb ( cnt );
		}
	}

	if ( b != 1 ){
		data.pb ( b );
		num.pb ( 1 );
	}
	REPP ( i, 0, SZ ( data ) ){
		LL tmp = count ( n, data[i] );
		ans = min ( ans, tmp / num[i] );
	}
	cout << ans << '\n';
}