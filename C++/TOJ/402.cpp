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

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str, be, en, tmp, num;
	int ans = 0, n;
	bool check = true, now;
	cin >> str;

	be += str[0];
	be += str[1];
	be += str[2];
	en += str[3];
	en += str[4];
	en += str[5];
	char p = str[6];
	tmp += p;
	REPP ( i, 7, SZ ( str ) ){
		if ( 'A' <= str[i] && str[i] <= 'Z' ){
			tmp += str[i];
			p = str[i];
		}
		else{
			while ( '0' <= str[i] && str[i] <= '9' && i < SZ ( str ) ){
				if ( SZ ( num ) < 2 ) num += str[i];
				i++;
			}
			if ( i != SZ ( str ) - 1 ) i--;
			if ( SZ ( num ) > 1 )
				n = 2;
			else{
				if ( num[0] >= '3' )
					n = 3;
				else
					n = ( int ) num[0] - '0';
			}
			num = "";
			while ( n-- )
				tmp += p;
		}
	}
	str = tmp;
	REPP ( i, 0, SZ ( str ) ){
		if ( !now && str[i] == be[0] && str[i + 1] == be[1] && str[i + 2] == be[2] ){
			now = 1;
		}
		else if ( now && str[i] == en[0] && str[i + 1] == en[1] && str[i + 2] == en[2] ){
			now = 0;
			ans++;
		}
	}
	cout << ans << '\n';
}