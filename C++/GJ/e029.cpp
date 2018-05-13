// by. MiohitoKiri5474
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<queue>

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
#define vec vector
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

// greph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 500005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

GRE ( int, edge );
int deg[maxN], siz[maxN];
bool visited[maxN];
inline void Init ( void ){
	REPP ( i, 0, maxN ) CLR ( edge[i] );
	MEM ( deg, 0 );
	MEM ( siz, 0 );
	MEM ( visited, 0 );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, m, u, v, ans1, ans2;
	pii stop;
	cin >> t;
	while ( t-- ){
		cin >> n >> m;
		Init();
		ans1 = ans2 = -1;

		while ( m-- ){
			cin >> u >> v;
			UNI ( u, v, edge );
			deg[min ( u, v )]++;
		}

		REPP ( i, 0, n ) ans1 = max ( ans1, deg[i] );
		priority_queue < pii, vec < pii >, greater < pii > > pq;
		REPP ( i, 0, n ) pq.push ( pii ( siz[i] = SZ ( edge[i] ), i ) );
		REPP ( i, 0, n ){
			stop = pq.top();
			pq.pop();
			while ( visited[stop.S] ){
				stop = pq.top();
				pq.pop();
			}

			visited[stop.S] = true;
			if ( ans2 < stop.F )
				ans2 = stop.F;
			REPP ( j, 0, SZ ( edge[stop.S] ) ) if ( !visited[edge[stop.S][j]] ) pq.push ( pii ( --siz[edge[stop.S][j]], edge[stop.S][j] ) );
		}

		cout << ans1 << ' ' << ans2 << '\n';
	}
}