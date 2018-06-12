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

#define int LL

map < int, sl > num;
pair < vl, int > lib[maxN];

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	#define int LL
	#define vi vl
	#define si sl

	int k, n, sum, in;
	cin >> k;
	si used;
	REPP ( i, 0, k ){
		cin >> n;
		sum = 0;
		REPP ( j, 0, n ){
			cin >> in;
			lib[i].F.pb ( in );
		}
		REPALL ( j, lib[i].F ){
			sum += j;
		}
		REPP ( fk, 0, n ){
			int j = lib[i].F[fk];
			if ( FID ( used, sum - j ) ){
				int a = *BEG ( num[sum - j] ), idx;
				if ( a == i )
					goto FuckYou;
				cout << "YES\n";
				REPP ( i, 0, SZ ( lib[a].F ) ){
					if ( lib[a].S - lib[a].F[i] == sum - j ){
						idx = i;
						break;
					}
				}

				cout << i + 1 << ' ' << fk + 1 << '\n' << a + 1 << ' ' << idx + 1 << '\n';
				return 0;
			}
			FuckYou:
			num[sum - j].insert ( i );
			used.insert ( sum - j );
		}
		lib[i].S = sum;
	}

	cout << "NO\n";
}