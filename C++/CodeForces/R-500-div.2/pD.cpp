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

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

// vi dataX[maxN], dataY[maxN];
// bitset < maxN > lib[maxN];
int cntX[maxN], cntY[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, q, x, y, cnt = 0;
	vi idx, idy;
	cin >> n >> m >> q;
	// si usedX, usedY;
	REPP ( i, 0, q ){
		cin >> x >> y;
		dataX[x].pb ( y );
		dataY[y].pb ( x );
		usedX.insert ( x );
		usedY.insert ( y );
		cntX[x]++, cntY[y]++;
	}
	if ( n == 1 || m == 1 ){
		cout << LL ( n * m - q )<< '\n';
		return 0;
	}
	if ( !q ){
		cout << n + m - 1 << '\n';
		return 0;
	}

	REPALL ( i, usedX ){
		sort ( ALL ( dataX[i] ) );
	}
	REPALL ( i, usedY ){
		sort ( ALL ( dataY[i] ) );
	}

	n++, m++;
	while ( cnt < 1000 ){
		// cout << cnt++ << '\n';
		cnt++;
		REPALL ( i, usedX ){
			REPALL ( j, usedY ){
				if ( *lower_bound ( ALL ( dataX[i] ), j ) != j || *lower_bound ( ALL ( dataY[j] ), i ) != i )
					continue;
				CLR ( idx );
				CLR ( idy );
			}
		}
	}

	x = y = INF;
	int id, ans;
	cnt = 0;
	REPP ( i, 1, n ){
		if ( x > m - cntX[i] - 1 ){
			x = m - cntX[i] - 1;
			id = i;
		}
		if ( cntX[i] == 0 )
			cnt++;
	}
	ans = cnt + x - ( !cntX[id] );
	cnt = 0;
	REPP ( i, 1, m ){
		if ( y > n - cntY[i] - 1 ){
			y = n - cntY[i] - 1;
			id = i;
		}
		if ( cntY[i] == 0 )
			cnt++;
	}
	cout << min ( cnt + y - ( !cntY[id] ), ans ) << '\n';
}