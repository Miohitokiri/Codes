// by. MiohitoKiri5474
#include<bits/stdc++.h>

// #pragma GCC diagnostic ignored "-Wunused-result"
// #pragma GCC diagnostic ignored "-Wunused-function"
// #pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC optimize ( "O3" )
// #pragma GCC optimize ( "Ofast, unroll-loops, no-stack-protector" )
// #pragma loop_opt ( on )

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
typedef vector < int > vi;
typedef vector < LL > vl;
#define pb push_back
#define ep emplace_back
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) ( BEG ( n ), END ( n ) )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) n.find ( Index ) != n.end()

// greph
#define GRE(T,edge) vector < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vector < T > >;
template < class T > using MaxHeap = priority_queue < T >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// create some usefull function
inline int changeStrToInt ( string str ){
	int res = 0;
	REPALL ( i, str ) res *= 10, res += ( int ) i - '0';
	return res;
}

inline string changeIntToStr ( int n ){
	string tmp, res;
	while ( n )
		tmp += ( char ) n % 10 + '0', n /= 10;

	REPM ( i, tmp.size() - 1, 0 ) res += tmp[i];

	return res;
}

#define LCM(a,b) abs ( a * b ) / __gcd ( a, b )

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

// oh, if I'm writing TIOJ, SkyOJ or any one online judge can accept C++ 11, remember delete line 6

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	char data[3][3], flag = ' ';
	REPP ( i, 0, 3 ) REPP ( j, 0, 3 ){
		cin >> data[i][j];
		if ( data[i][j] == '#' )
			flag = '#';
	}

	REPP ( i, 0, 3 ){
		if ( data[i][0] == data[i][1]&&data[i][1] == data[i][2] ){
			flag = data[i][0];
			break;
		}
		if ( data[0][i] == data[1][i]&&data[1][i] == data[2][i] ){
			flag = data[0][i];
			break;
		}
		if ( data[0][0] == data[1][1]&&data[1][1] == data[2][2] ){
			flag = data[0][0];
			break;
		} 
		if ( data[0][2] == data[1][1]&&data[1][1] == data[2][0] ){
			flag = data[0][2];
			break;
		}
	}

	if ( flag == 'O' )
		cout << "A wins.";
	else if ( flag == 'X' )
		cout << "B wins.";
	else if ( flag == '#' )
		cout << "Playing";
	else
		cout << "Draw";
	cout << '\n';
}