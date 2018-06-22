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
#define maxN 200005

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

LL cnt[maxN], ans;
vi lib[maxN], data;

inline void operAdd ( int n, int num, int sz ){
	cout << n << ' ' << num <<  ' ' << sz << '\n'; // del
	num -= n;
	ans += num * sz;
	REPP ( i, 0, sz ){
		data[lib[n][i]] += num;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, tmp, st, last = -1;
	vec < pii > dq;
	cin >> n >> m;
	GETDATA ( data, n );
	for ( int i = 0 ; i < n ; i++ ){
		cnt[data[i] % m]++;
		lib[data[i] % m].pb ( i );
	}

	tmp = n / m;
	REPP ( i, 0, m ){
		cnt[i] -= tmp;
		if ( cnt[i] != 0 )
			dq.pb ( pii ( cnt[i], i ) );
	}

	pii stp;
	while ( !EMP ( dq ) && SZ ( dq ) != 1 ){
		cout << SZ ( dq ) << '\n';
		if ( dq[0].F < 0 ){
			auto idx = END ( dq );
			while ( ( END ( dq ) - 1 ) -> F < 0 )
				idx = ( END ( dq ) - 1 );

			int mi = min ( abs ( dq[0].F ), abs ( idx -> F ) );
			operAdd ( dq[0].S, idx -> S, mi );
			dq[0].F += mi;
			if ( dq[0].F == 0 )
				dq.erase ( BEG ( dq ) );
			idx -> F -= mi;
			if ( idx -> F == 0 )
				dq.erase ( idx );
		}
		else{
			int idx = 0;
			for ( int i = 1 ; i < SZ ( dq ) ; i++ ){
				if ( dq[i].F < 0 ){
					idx = i;
					break;
				}
			}
			cout << "      " << idx << '\n'; // del

			int mi = min ( abs ( dq[0].F ), abs ( dq[idx].F ) );
			operAdd ( dq[0].S, dq[idx].S, mi );
			dq[0].F -= mi;
			if ( dq[0].F == 0 )
				dq.erase ( BEG ( dq ) );
			dq[idx].F += mi;
			if ( dq[idx].F == 0 )
				dq.erase ( BEG ( dq ) + idx );
		}
	}

	cout << ans << '\n';
	PIO ( data );
}