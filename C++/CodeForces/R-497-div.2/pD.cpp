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
#define NEG_INF 0x8f8f8f8f
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int pre[maxN], dp[maxN];
vi prime;

inline int _gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;

	return min ( a, b );
}

inline int count ( int n ){
	if ( n == 1 )
		return 1;
	if ( dp[n] != 0 )
		return dp[n];
	int res = 1, cnt;

	REPALL ( i, prime ){
		if ( i > n )
			break;
		cnt = 0;
		while ( n % i == 0 ){
			cnt++;
			n /= i;
		}
		res *= ++cnt;
	}

	return dp[n] = res;
}

inline LL C ( int n, int m ){
	LL swp, res = 1;
	si data;
	if ( m > n / 2 ){
		m = n - m;
	}
	REPP ( i, 0, m ) data.insert ( n - i );
	m++;
	REPP ( j, 1, m ){
		REPALL ( i, data ){
			if ( i % j == 0 ){
				swp = i;
				break;
			}
		}
		data.erase ( swp );
		data.insert ( swp / j );
	}

	REPALL ( i, data ) res *= i;
	return res;
}

inline LL H ( int n, int m ){
	return C ( m + n - 1, n - 1 );
}

inline LL fuckyou ( int a, int b, int ab ){
	LL res = ( a - ab ) * ( b - ab ) + ab * ( a + b - 2 * ab ) + H ( ab, 2 );
	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	MEM ( pre, -1 );
	REPP ( i, 2, maxN ){
		if ( pre[i] < 0 )
			prime.pb ( i );
		for ( int j = 0 ; i * prime[j] < maxN ; j++ ){
			pre[i * prime[j]] = prime[j];
			if ( i % prime[j] == 0 )
				break;
		}
	}

	int n, swp, ans, a, b, c, ab, bc, ac, abc, ca, cb, cc, cab, cbc, cac, cabc;
	vi data ( 3 );
	cin >> n;
	while ( n-- ){
		REPALL ( i, data ) cin >> i;
		sort ( ALL ( data ) );
		if ( data[0] == data[2] ){
			cout << H ( count ( data[0] ), 3 ) << '\n';
			continue;
		}
		else if ( data[0] == data[1] ){
			cout << H ( count ( data[0] ), 2 ) * count ( data[2] ) << '\n';
			continue;
		}
		else if ( data[1] == data[2] ){
			cout << count ( data[0] ) * H ( count ( data[1] ), 2 ) << '\n';
			continue;
		}
		a = data[0], b = data[1], c = data[2];
		ab = _gcd ( a,b ), bc = _gcd ( b, c ), ac = _gcd ( a, c ), abc = _gcd ( ab, c );
		ca = count ( a ), cb = count ( b ), cc = count ( c );
		cab = count ( ab ), cbc = count ( bc ), cac = count ( ac ), cabc = count ( abc );
		if ( ab * bc * ac == 1 )
			ans = ca * cb * cc;
		else if ( ab * ac == 1 )
			ans = ca * fuckyou ( cb, cc, cbc );
		else if ( ab * bc == 1 )
			ans = cb * fuckyou ( ca, cc, cac );
		else if ( ac * bc == 1 )
			ans = cc * fuckyou ( ca, cb, cab );
		else if ( ab == 1 && bc != 1 && ac != 1 )
			ans = fuckyou ( ca, fuckyou ( cb, cc, cbc ), cac ) - ab;
		else if ( ab != 1 && bc == 1 && ac != 1 )
			ans = fuckyou ( cb, fuckyou ( ca, cc, cac ), cab ) - ab;
		else if ( ab != 1 && bc != 1 && ac == 1 )
			ans = fuckyou ( ca, fuckyou ( cb, cc, cbc ), cab ) - ab;
		else{
			ans = fuckyou ( fuckyou ( ca, cb, cab ), cc, cbc + cac - cabc );
		}

		cout << ans << '\n';
	}

	CLR ( data );
	data.pb ( 89920 );
	data.pb ( 39297 );
	data.pb ( 55380 );
	REPP ( i, 0, 3 ){
		REPP ( j, 0, i ){
			cout << data[i] << ' ' << data[j] << ' ' << _gcd ( data[i], data[j] ) << '\n';
		}
	}
}