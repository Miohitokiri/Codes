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

inline int jobJudger ( char a ){
	switch ( a ){
		case 'e': return 1;
		case 'n': return 2;
		case 'k': return 3;
		case 'w': return 4;
		case 'a': return 5;
		case 'm': return 6;
		case 'd': return 7;
		case 'l': return 8;
	}
	return -1;
}

struct cats{
	int pri, yeard;
	string name;

	cats ( string _job, string _name, int _yeard ): pri ( jobJudger ( _job[0] ) ), name ( _name ), yeard ( _yeard ) {}
};

bool cmp ( cats a, cats b ){
	if ( a.pri != b.pri )
		return a.pri < b.pri;
	else if ( a.pri == 5 && a.pri == 5 && a.yeard != b.yeard )
		return a.yeard < b.yeard;
	else if ( a.yeard != b.yeard && a.pri != 5 && b.pri != 5 )
		return a.yeard > b.yeard;
	return a.name < b.name;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, y;
	string nam, job;
	vec < cats > data;
	while ( cin >> n >> m ){
		CLR ( data );
		REPP ( i, 0, n ){
			cin >> nam >> job >> y;
			data.ep ( job, nam, y );
		}

		sort ( ALL ( data ), cmp );

		m = min ( n, m );

		REPP ( i, 0, m ) cout << data[i].name << '\n';
	}
}