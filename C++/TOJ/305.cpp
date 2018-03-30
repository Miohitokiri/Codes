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

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

inline int count ( int y, int m, int d ){
	if ( m <= 2 )
		m += 12, y--;
	return ( d + 2 * m + 3 * ( m + 1 ) / 5 + y + y / 4 - y / 100 + y / 400 + 1 ) % 7;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	int y, m, d, t, limit;
    bool flag;
    char c;
    while ( cin >> c >> y >> m >> d ){
        flag = false;
        switch ( c ){
        	case 'Y': REPP ( i, 2001, 2101 ) if ( d == count ( i, y, m ) ){
        		if ( flag )
        			cout << ' ' << i;
        		else{
        			cout << i;
        			flag = true;
        		}
        	}
        	break;
        	case 'M': REPP ( i, 1, 13 ) if ( d == count ( y, i, m ) ){
        		if ( flag )
        			cout << ' ' << i;
        		else{
        			flag = true;
        			cout << i;
        		}
        	}
        	break;
        	case 'D': t = ( d - count ( y, m, 1 ) + 7 ) % 7;
        	if ( m & 1 )
        		limit = ( m < 8 ? 31 : 30 );
        	else
        		limit = ( m >= 8 ? 31 : 30 );
        	if ( m == 2 ){
        		limit = 28;
        		if ( ( y % 4 == 0 && y % 100 ) || y % 400 == 0 )
        			limit++;
        	}

        	cout << t + 1;
        	for ( int i = t + 8 ; i <= limit ; i+= 7 )
        		cout << ' ' << i;
        	break;
        	default: cout << count ( y, m, d );
        }

        cout << '\n';
    }
}
