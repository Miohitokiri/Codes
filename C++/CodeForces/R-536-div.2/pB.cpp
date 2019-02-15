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

pll dish[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	#define int LL
	#define pii pll

	int n, m, t, d, swp;
	LL sum = 0, ans = 0;
	vec < pii > data;
	cin >> n >> m;
	REPP ( i, 0, n ){
		cin >> dish[i].F;
		sum += dish[i].F;
	}
	REPP ( i, 0, n ){
		cin >> dish[i].S;
	}

	REPP ( i, 0, n ){
		data.pb ( pii ( dish[i].S, i ) );
	}

	sort ( ALL ( data ) );
	REV ( ALL ( data ) );

	while ( m-- ){
		cin >> t >> d;
		t--;
		if ( sum < d ){
			sum = 0;
			cout << "0\n";
			continue;
		}
		ans = 0;
		sum -= d;
		if ( dish[t].F >= d ){
			dish[t].F -= d;
			ans += d * dish[t].S;
		}
		else{
			ans += dish[t].F * dish[t].S;
			d -= dish[t].F;
			dish[t].F = 0;
			while ( !EMP ( data ) && d ){
				if ( dish[data.back().S].F <= 0 )
					data.pop_back();
				else{
					ans += ( swp = min ( d, dish[data.back().S].F ) ) * dish[data.back().S].S;
					dish[data.back().S].F -= swp;
					d -= swp;
				}
			}
		}

		cout << ans << '\n';
	}
}