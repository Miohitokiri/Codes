/************************************/
/* Date		: 2020-02-14 16:22:05	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

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
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

inline int calc ( vi data, int k ){
	int res = -1;
	for ( int i = 1 ; i < SZ ( data ) ; i++ )
		res = max ( res, abs ( ( data[i] == -1 ? k : data[i] ) - ( data[i - 1] == -1 ? k : data[i - 1] ) ) );
	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, m, k, l, r, lidx, ridx, cnt, mi, ma;
	vi data;
	vec < pii > lib;
	cin >> t;
	while ( t-- ){
		cin >> n;
		GETDATA ( data, n );
		CLR ( lib );
		ma = m = l = r = -1;
		cnt = 0;
		mi = INF;
		for ( int i = 0 ; i < n ; i++ ){
			if ( data[i] != -1 ){
				if ( l == -1 ){
					l = data[i];
					lidx = i;
				}
				else if ( r == -1 ){
					r = data[i];
					ridx = i;
				}
				else{
					swap ( l, r );
					swap ( lidx, ridx );
					r = data[i], ridx = i;
				}
				m = max ( m, abs ( l - r ) );
				ma = max ( ma, data[i] );
				mi = min ( mi, data[i] );
			}
			else{
				cnt++;
			}
		}

		if ( !cnt || cnt == n ){
			cout << max ( 0, m ) << " 0\n";
			continue;
		}
		if ( m == 0 ){
			cout << "0 " << l << '\n';
			continue;
		}
		data.erase ( unique ( ALL ( data ) ), END ( data ) );

		l = mi, r = ( mi + ma ) >> 1, k = r;
		m = calc ( data, k );
		while ( r - l > 1 ){
			if ( calc ( data, k ) >= m )
				r = k;
			else
				l = k;
			k = ( l + r ) >> 1;
			m = calc ( data, k );
		}
		lib.pb ( pii ( calc ( data, k ), k ) );

		// l = mi, r = ( mi + ma ) >> 1, k = r;
		// m = calc ( data, k );
		// while ( r - l > 1 ){
		// 	if ( calc ( data, k ) >= m )
		// 		r = k;
		// 	else
		// 		l = k;
		// 	k = ( l + r ) >> 1;
		// 	m = calc ( data, k );
		// }
		// lib.pb ( pii ( calc ( data, k ), k ) );

		l = ( mi + ma ) >> 1, r = ma, k = l;
		m = calc ( data, k );
		while ( r - l > 1 ){
			if ( calc ( data, k ) > m )
				l = k;
			else
				r = k;
			k = ( l + r ) >> 1;
			m = calc ( data, k );
		}
		lib.pb ( pii ( calc ( data, k ), k ) );

		// l = ( mi + ma ) >> 1, r = ma, k = l;
		// m = calc ( data, k );
		// while ( r - l > 1 ){
		// 	if ( calc ( data, k ) >= m )
		// 		l = k;
		// 	else
		// 		r = k;
		// 	k = ( l + r ) >> 1;
		// 	m = calc ( data, k );
		// }
		// lib.pb ( pii ( calc ( data, k ), k ) );

		sort ( ALL ( lib ) );

		// cout << lib[0].F << ' ' << lib[0].S << '\n';
		cout << calc ( data, ( ma + mi ) >> 1 ) << ' ' << ( ( ma + mi ) >> 1 ) << '\n';
		// for ( auto [i, j]: lib )
		// 	cout << '\t' << i << ' ' << j << '\n';
	}
}