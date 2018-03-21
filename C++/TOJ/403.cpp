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
// #define mp make_pair

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
#define maxN 25

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

int mp[maxN][maxN];
bool used[maxN][maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int w, h, x = 1, y = 1, a, b, ans = 0, way = 0;
	cin >> w >> h >> a >> b;
	MEM ( mp, INF );
	for ( int i = 1 ; i <= w ; i++ )
		for ( int j = 1 ; j <= h ; j++ )
			cin >> mp[i][j];
	while ( x != a || y != b ){
		cout << x << ' ' << y << '\n';
		if ( way == 0 ){
			if ( used[x + 1][y] )
				y++, way++;
			else if ( used[x][y + 1] )
				x++;
			else{
				if ( mp[x + 1][y] > mp[x][y + 1] )
					y++, way++;
				else
					x++;
			}
		}
		else if ( way == 1 ){
			if ( used[x - 1][y] )
				x--, way++;
			else if ( used[x][y + 1] )
				y++;
			else{
				if ( mp[x - 1][y] > mp[x][y + 1] )
					y++;
				else
					x--, way++;
			}
		}
		else if ( way == 2 ){
			if ( used[x - 1][y] )
				y--, way++;
			else if ( used[x][y - 1] )
				x--;
			else{
				if ( mp[x - 1][y] > mp[x][y - 1] )
					y--, way++;
				else
					x--;
			}
		}
		else if ( way == 3 ){
			if ( used[x][y - 1] )
				x++, way = 0;
			else if ( used[x + 1][y] )
				y--;
			else{
				if ( mp[x][y - 1] > mp[x + 1][y] )
					y--;
				else
					x++, way = 0;
			}
		}
		ans += mp[x][y];
		used[x][y] = true;
	}

	cout << ans << '\n';
}