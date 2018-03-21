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

// greph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T >;
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

	int n, m;
	bool flag, re;
	string str, stop, num, stp;
	map < string, set < string > > lib;
	set < string > rm;
	cin >> n;
	while ( n-- ){
		cin >> str >> m;
		while ( m-- ){
			cin >> stop;

			num = stop;
			CLR ( rm );
			REPALL ( i, lib[str] ){
				string gg = i;
				reverse ( ALL ( gg ) );
				stp = "";
				REPM ( j, SZ ( num ) - 1, 0 ){
					stp += num[j];
					if ( stp == gg ){
						rm.insert ( i );
						break;
					}
				}
			}

			REPALL ( i, rm )
				lib[str].erase ( lib[str].find ( i ) );

			flag = true;
			reverse ( ALL ( stop ) );
			REPALL ( i, lib[str] ){
				stp = "";
				REPM ( j, SZ ( i ) - 1, 0 ){
					stp += i[j];
					if ( stp == stop )
						flag = false;
				}
			}

			if ( flag )
				lib[str].insert ( num );
		}
	}

	cout << SZ ( lib ) << '\n';
	for ( auto i = BEG ( lib ) ; i != END ( lib ) ; i++ ){
		cout << i -> F << ' ' << SZ ( i -> S );
		REPALL ( j, i -> S ) cout << ' ' << j;
		cout << '\n';
	}
}