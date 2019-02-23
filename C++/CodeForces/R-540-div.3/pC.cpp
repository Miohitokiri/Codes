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
#define maxN 1005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int cnt[maxN], ans[25][25];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, in, idx = 0;
	cin >> n;
	REPP ( i, 0, n * n ){
		cin >> in;
		cnt[in]++;
	}
	vi c4, c2, c1;
	REPP ( i, 1, 1001 ){
		while ( cnt[i] >= 4 ){
			c4.pb ( i );
			cnt[i] -= 4;
		}
		while ( cnt[i] >= 2 ){
			c2.pb ( i );
			cnt[i] -= 2;
		}
		while ( cnt[i] >= 1 ){
			c1.pb ( i );
			cnt[i]--;
		}
	}

	// cout << SZ ( c4 ) << ' ' << SZ ( c2 ) << ' ' << SZ ( c1 ) << '\n';

	if ( n % 2 == 0 ){
		if ( !EMP ( c2 ) || !EMP ( c1 ) ){
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		REPP ( i, 0, n / 2 ){
			REPP ( j, 0, n / 2 ){
				ans[i][j] = c4[idx++];
			}
		}

		idx = 0;
		REPP ( i, 0, n / 2 ){
			REPM ( j, n - 1, n / 2 ){
				ans[i][j] = c4[idx++];
			}
		}

		idx = 0;
		REPM ( i, n - 1, n / 2 ){
			REPP ( j, 0, n / 2 ){
				ans[i][j] = c4[idx++];
			}
		}

		idx = 0;
		REPM ( i, n - 1, n / 2 ){
			REPM ( j, n - 1, n / 2 ){
				ans[i][j] = c4[idx++];
			}
		}

		REPP ( i, 0, n ){
			REPP ( j, 0, n ){
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else{
		if ( SZ ( c1 ) != 1 || SZ ( c2 ) > n - 1 ){
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		REPP ( i, 0, n / 2 ){
			REPP ( j, 0, n / 2 ){
				ans[i][j] = c4[idx++];
			}
		}

		idx = 0;
		REPP ( i, 0, n / 2 ){
			for ( int j = n - 1 ; j > n / 2 ; j-- ){
				ans[i][j] = c4[idx++];
			}
		}

		idx = 0;
		for ( int i = n - 1 ; i > n / 2 ; i-- ){
			REPP ( j, 0, n / 2 ){
				ans[i][j] = c4[idx++];
			}
		}

		idx = 0;
		for ( int i = n - 1 ; i > n / 2 ; i-- ){
			for ( int j = n - 1 ; j > n / 2 ; j-- ){
				ans[i][j] = c4[idx++];
			}
		}
		// cout << SZ ( c4 ) << ' ' << idx << '\n';
		while ( idx != SZ ( c4 ) ){
			c2.pb ( c4[idx] );
			c2.pb ( c4[idx] );
			idx++;
		}
		// cout << '\n';
        ans[n / 2][n / 2] = c1[0];
        idx = 0;
        REPP ( i, 0, n / 2 ){
            if(i != n / 2 ){
                ans[i][n / 2] = ans[n - i - 1][n / 2] = c2[idx];
                idx++;
                ans[n / 2][i] = ans[n / 2][n - i - 1] = c2[idx];
                idx++;
            }
        }
        REPP ( i, 0, n ){
        	REPP ( j, 0, n ){
        		cout << ans[i][j] << ' ';
        	}
        	cout << '\n';
        }
	}
}