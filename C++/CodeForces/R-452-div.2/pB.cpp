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

	int n, fir = -1, now = 2, c = 0;
	set < int > big, small, mid;
	bool flg = true;
	big.insert ( 1 );
	big.insert ( 3 );
	big.insert ( 5 );
	big.insert ( 7 );
	big.insert ( 8 );
	big.insert ( 10 );
	big.insert ( 12 );
	small.insert ( 4 );
	small.insert ( 6 );
	small.insert ( 9 );
	small.insert ( 11 );
	mid.insert ( 2 );
	cin >> n;
	vi data ( n + 1 ), month ( n + 1 );
	REPP ( i, 1, n + 1 ){
		cin >> data[i];
		if ( data[i] == 28 || data[i] == 29 ){
			month[i] = 2;
			if ( fir == -1 )
				fir = i;
		}
	}
	if ( n == 1 ){
		cout << "YES\n";
		return 0;
	}

	if ( fir - 1 >= 0 ){
		REPM ( i, fir, 1 ){
			month[i] = now--;
			if ( now == 0 )
				now = 12;
		}
		now = 3;
		REPP ( i, fir + 1, n + 1 ){
			month[i] = now++;
			if ( now == 13 )
				now = 1;
		}

		REPP ( i, 1, n + 1 ){
			flg = true;
			if ( data[i] == 31 ){
				if ( big.find ( month[i] ) == big.end() ){
					flg = false;
				}
			}
			else if ( data[i] == 30 ){
				if ( small.find ( month[i] ) == small.end() ){
					flg = false;
				}
			}
			else{
				if ( month[i] != 2 )
					flg = false;
				else if ( data[i] == 29 )
					c++;
			}
			if ( !flg ){
				cout << "NO\n";
				return 0;
			}
		}

		if ( c <= 1 )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else{
		REPP ( i, 1, n ){
			if ( data[i] == data[i + 1] && data[i] == 31 ){
				month[i] = 7;
				fir = i;
				break;
			}
		}
		now = 7;
		REPM ( i, fir, 1 ){
			month[i] = now--;
			if ( now == 0 )
				now = 12;
		}
		now = 8;
		REPP ( i, fir + 1, n + 1 ){
			month[i] = now++;
			if ( now == 13 )
				now = 1;
		}

		REPP ( i, 1, n + 1 ){
			flg = true;
			if ( data[i] == 31 ){
				if ( big.find ( month[i] ) == big.end() ){
					flg = false;
				}
			}
			else if ( data[i] == 30 ){
				if ( small.find ( month[i] ) == small.end() ){
					flg = false;
				}
			}
			else{
				if ( month[i] != 2 )
					flg = false;
				else if ( data[i] == 29 )
					c++;
			}
			if ( !flg ){
				cout << "NO\n";
				return 0;
			}
		}

		if ( c <= 1 )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}