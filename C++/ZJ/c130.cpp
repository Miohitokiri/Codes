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
#define REV(n) reverse ( ALL ( n ) )
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

inline string chang ( int a ){
	string res;
	while ( a ){
		res += ( char ) a % 10 + '0';
		a /= 10;
	}
	REV ( res );
	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, stp, res;
	map < int, set < si > > lib;
	vi basic, vt;
	si stop, tmp, data;
	set < vi > already;
	while ( cin >> t >> n ){
		if ( !n )
			break;

		RSZ ( basic, n );
		CLR ( already );
		CLR ( stop );
		CLR ( tmp );
		CLR ( data );
		CLR ( lib );

		REPP ( i, 0, n ) cin >> basic[i];

		stop.insert ( 0 );
		lib[0].insert ( data );
		REPP ( i, 0, n ){
			REPALL ( j, stop ){
				stp = j + basic[i];
				if ( stp > t )
					continue;
				tmp.insert ( stp );
				REPALL ( vect, lib[j] ){
					data = vect;
					data.insert ( i );
					res = 0;
					REPALL ( k, data ) res += basic[k];
					if ( res == stp )
						lib[stp].insert ( data );
				}
			}

			REPALL ( j, tmp ) stop.insert ( j );
			tmp.clear();
		}

		cout << "Sums of " << t << ":\n";

		if ( !( FID ( stop, t ) ) )
			cout << "NONE\n";
		else{
			for ( auto i = lib[t].rbegin() ; i != lib[t].rend() ; i++ ){
				data = *i;
				CLR ( vt );
				REPALL ( j, data )
					vt.pb ( basic[j] );
				already.insert ( vt );
			}

			for ( auto i = already.rbegin() ; i != already.rend() ; i++ ){
				vt = *i;
				cout << vt[0];
				REPP ( j, 1, SZ ( vt ) )
					cout << '+' << vt[j];
				cout << '\n';
			}
		}
	}
}