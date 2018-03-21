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
#define SP(a,b) swap ( a, b )
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
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) n.find ( Index ) != n.end()

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

int way[4];

inline void pls ( int i ){
	way[i]++;
	if ( way[i] == 4 ){
		way[i] = 0;
		pls ( i - 1 );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, ans = 0;
	bool dmap[55][55], flag = false, used[55][55], can;
	char stop;
	pii bg, ed, now, p;
	string str, che;
	cin >> n >> m;
	MEM ( dmap, 0 );
	MEM ( used, 0 );
	REPP ( i, 1, n + 1 ){
		REPP ( j, 1, m + 1 ){
			cin >> stop;
			if ( stop == '.' )
				dmap[i][j] = 1;
			else if ( stop == 'S' ){
				dmap[i][j] = 1;
				bg = mp ( i, j );
			}
			else if ( stop == 'E' ){
				dmap[i][j] = 1;
				ed = mp ( i, j );
			}
		}
	}

	cin >> str;

	int cnt = 0;
	while ( cnt < 24 ){
		pls ( 3 );
		can = true;
		REPP ( i, 0, 4 ) REPP ( j, 0, i ) if ( way[i] == way[j] ) can = false;
		if ( !can )
			continue;
		cnt++;
		flag = false;

		p = now = bg;
		REPALL ( i, str ){
			switch ( way[( int ) i - '0'] ){
				case 0: now.S++; break;
				case 2: now.S--; break;
				case 1: now.F++; break;
				case 3: now.F--;
			}
			if ( !dmap[now.F][now.S] ){
				break;
			}
			else
				p = now;

			if ( now == ed ){
				flag = true;
				break;
			}
		}

		if ( flag )
			ans++;
	}

	cout << ans << '\n';
}