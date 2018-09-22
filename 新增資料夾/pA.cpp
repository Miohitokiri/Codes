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
#define maxN 100005
const LL maxLog = log2 ( maxN ) + 5;

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

#define int LL

int value[maxN], dp[maxN][maxLog], D[maxN], pData[maxLog], n;
GRE ( int, edges );

inline void dfs ( int d, int p, int dep ){
    D[d] = dep++;
    dp[d][0] = p;
    REPALL ( i, edges[d] ){
        if ( i == p )
            continue;
        dp[i][0] = d;
        dfs ( i, d, dep );
    }
}

inline void buildLCA ( void ){
    MEM ( dp, -1 );
    MEM ( D, 0 );
    dfs ( 1, -1, 0 );
    REPP ( k, 1, maxLog ){
        for ( int i = 1 ; i <= n ; i++ ){
            if ( dp[i][k - 1] == -1 )
                continue;
            dp[i][k] = dp[dp[i][k - 1]][k - 1];
        }
    }
}

int check1 ( int x, int m, int sum, int turn ){
//	sum = value[x];
	for ( turn = 1 ; turn < maxLog && x != -1 ; turn++ ){
//		cout << x << ' '; // del
		sum += value[x];
		x = dp[x][1];
		if ( sum == m ){
			return sum;
		}
	}
	
	if ( x == -1 ){
		return -1 * m;
	}
	
	return sum;
}

int check2 ( int x, int m, int sum, int turn ){
//	sum = value[x];
	for ( turn = 1 ; turn < maxLog && x != -1 ; turn++ ){
//		cout << x << ' '; // del
		sum += value[x];
		x = dp[x][1];
		if ( sum == m ){
			return turn;
		}
	}
	
	if ( x == -1 ){
		return INF;
	}
	
	return INF;
}

#undef int

int main(){
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );
    #define int LL

	for ( int i = 1 ; i < maxLog ; i++ ){
		pData[i] = 1 << i;
	}
	int m, k, u, v;
	bool tf = true;
	cin >> n >> m >> k;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> value[i];
		if ( m == value[i] && k == 1 ){
			cout << "yes\n";
			return 0;
		}
		if ( m == value[i] && k == 2 ){
			cout << "yes\n1\n";
			return 0;
		}
	}
	for ( int i = 1 ; i < n ; i++ ){
		cin >> u >> v;
		if ( v - u != 1 ){
			tf = false;
		}
		UNI ( u, v, edges );
	}
	
	if ( tf ){
		vl data[2];
		int mi = INF;
		for ( int i = 1 ; i <= n ; i++ ){
			data[i % 2].pb ( value[i] );
		}
		for ( int i = 0 ; i < 2 ; i++ ){
			REV ( ALL ( data[i] ) );
			int sum = 0;
			for ( int j = 1 ; j < SZ ( data[i] ) ; j++ ){
				data[i][j] += data[i][j];
			}
			for ( int j = 0 ; j < SZ ( data[i] ) ; j++ ){
//				sum = 0;
				for ( int k = 0 ; k <= j ; k++ ){
					if ( data[i][j] - data[i][k - 1] == m ){
						cout << "yes\n";
						return 0;
					}
				}
			}
		}
	}
	
	buildLCA();
	
	if ( k == 1 ){
		for ( int i = 1 ; i <= n ; i++ ){
			int swp = check1 ( i, m, 0, 0 );
			if ( swp == m ){
				cout << "yes\n";
				return 0;
			}
		}
		cout << "no\n";
	}
	else{
		int mi = INF;
		for ( int i = 1 ; i <= n ; i++ ){
			mi = min ( mi, check2 ( i, m, 0, 0 ) );
		}
		if ( mi != INF ){
			cout << "yes\n" << mi << '\n';
		}
		else{
			cout << "-1\n";
		}
	}
}
