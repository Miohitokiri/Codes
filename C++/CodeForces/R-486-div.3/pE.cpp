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

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int two = -1, five = -1, zero = -1, seven = -1, mi, ans = INF, zeroSec = -1;
	LL n;
	string str;
	cin >> str;
	REPALL ( i, str ){
		n *= 10;
		n += ( int ) i - '0';
	}
	if ( n % 25 == 0 ){
		cout << "0\n";
		return 0;
	}
	if ( SZ ( str ) == 2 ){
		swap ( str[0], str[1] );
		REPALL ( i, str ){
			n *= 10;
			n += ( int ) i - '0';
		}
		if ( n % 25 == 0 ){
			cout << "1\n";
			return 0;
		}
	}
	REV ( ALL ( str ) );
	REPP ( i, 0, SZ ( str ) ){
		if ( str[i] == '2' && two == -1 )
			two = i;
		if ( str[i] == '5' && five == -1 )
			five = i;
		if ( str[i] == '0' && zero == -1 )
			zero = i;
		else if ( str[i] == '0' && zeroSec == -1 )
			zeroSec = i;
		if ( str[i] == '7' && seven == -1 )
			seven = i;
	}
	if ( five == -1 && zeroSec == -1 ){
		cout << "-1\n";
		return 0;
	}

	if ( zero == two && two == seven && seven == -1 ){
		cout << -1 << '\n';
		return 0;
	}

	if ( five == -1 ){
		cout << zero + zeroSec - 1 << '\n';
		return 0;
	}

	if ( zero < 0 )
		zero = INF;
	if ( seven < 0 )
		seven = INF;
	if ( two < 0 )
		two = INF;
	if ( zeroSec < 0 )
		zeroSec = INF;
	else
		ans = min ( ans, zero + zeroSec - 1 );

	if ( zero < five )
		ans = min ( ans, zero + five - 1 );
	else
		ans = min ( five + zero, ans );
	if ( five < seven )
		ans = min ( ans, five + seven - 1 );
	else
		ans = min ( ans, seven + five );
	if ( five < two )
		ans = min ( ans, five + two - 1 );
	else
		ans = min ( ans, two + five );

	cout << max ( 0, ans ) << '\n';
}