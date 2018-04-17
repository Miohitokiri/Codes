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

	int s, f;
	string ans;
	cin >> s;
	f = s / 10;
	s %= 10;
	if ( f == 0 ){
		if ( s == 1 )
			ans += "one";
		if ( s == 2 )
			ans += "two";
		if ( s == 3 )
			ans += "three";
		if ( s == 4 )
			ans += "four";
		if ( s == 5 )
			ans += "five";
		if ( s == 6 )
			ans += "six";
		if ( s == 7 )
			ans += "seven";
		if ( s == 8 )
			ans += "eight";
		if ( s == 9 )
			ans += "nine";
		if ( s == 0 )
			ans += "zero";
	}
	else{
		if ( f == 1 ){
			if ( s == 1 )
				ans = "eleven";
			if ( s == 2 )
				ans = "twelve";
			if ( s == 3 )
				ans = "thirteen";
			if ( s == 4 )
				ans = "fourteen";
			if ( s == 5 )
				ans = "fifteen";
			if ( s == 6 )
				ans = "sixteen";
			if ( s == 7 )
				ans = "seventeen";
			if ( s == 8 )
				ans = "eighteen";
			if ( s == 9 )
				ans = "nineteen";
			if ( s == 0 )
				ans = "ten";

			cout << ans << '\n';
			return 0;
		}
		if ( f == 2 )
			ans += "twenty";
		if ( f == 3 )
			ans += "thirty";
		if ( f == 4 )
			ans += "forty";
		if ( f == 5 )
			ans += "fifty";
		if ( f == 6 )
			ans += "sixty";
		if ( f == 7 )
			ans += "seventy";
		if ( f == 8 )
			ans += "eighty";
		if ( f == 9 )
			ans += "ninety";

		if ( s ){
			ans += '-';
			if ( s == 1 )
				ans += "one";
			if ( s == 2 )
				ans += "two";
			if ( s == 3 )
				ans += "three";
			if ( s == 4 )
				ans += "four";
			if ( s == 5 )
				ans += "five";
			if ( s == 6 )
				ans += "six";
			if ( s == 7 )
				ans += "seven";
			if ( s == 8 )
				ans += "eight";
			if ( s == 9 )
				ans += "nine";
		}
	}

	cout << ans << '\n';
}