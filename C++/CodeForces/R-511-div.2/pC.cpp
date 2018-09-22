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
#define maxN 1500005
#define maxM 1005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

inline LL gcd ( LL a, LL b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;

	return min ( a, b );
}

int prime[10005] = { 2, 3, 5, 7, 11, 13 }, len = 6, data[300005];

void build(){
	for ( int i = 14 ; i < 4005 ; i++ ){
		for ( int j = 0 ; j < len ; j++ ){
			if ( prime[j] * prime[j] > i ){
				prime[len++] = i;
				break;
			}
			else if ( i % prime[j] == 0 ){
				break;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, g, g2 = 0, ans, mi, cnt = 0;
	bool check = true;
	cin >> n >> g;
	data[0] = g;
	REPP ( i, 1, n ){
		cin >> data[i];
		g = gcd ( data[i], g );
		if ( data[i] != data[i - 1] )
			check = false;
	}

	if ( check ){
		cout << "-1\n";
		return 0;
	}

	build();
	sort ( data, data + n );

	for ( int i = 0 ; i < n ; i++ ){
		data[i] /= g;
	}

	ans = n - 1;
	REPP ( i, 0, len ){
		if ( prime[i] * prime[i] > data[n - 1] )
			break;
		cnt = 0;
		for ( int j = 0 ; j < n ; j++ ){
			if ( data[j] % prime[i] )
				cnt++;
		}
		ans = min ( cnt, ans );
		if ( ans == 1 ){
			cout << "1\n";
			return 0;
		}
	}

	cout << ans << '\n';
}