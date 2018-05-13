// by. MiohitoKiri5474
#include<iostream>
#include<vector>
#include<set>

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
#define vec vector
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

int cnt[25];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int in, n, ma = -1, idx;
	set < int > used;
	vi lib, data;
	cin >> n;
	REPP ( i, 0, n ){
		cin >> in;
		data.pb ( in );
	}
	REPP ( i, 0, SZ ( data ) ){
		if ( used.find ( data[i] ) == used.end() ){
			used.insert ( data[i] );
			lib.pb ( data[i] );
		}
	}

	sort ( ALL ( lib ) );

	REPP ( i, 0, SZ ( data ) ){
		cnt[lower_bound ( ALL ( lib ), data[i] ) - BEG ( lib )]++;
	}

	REPP ( i, 0, SZ ( used ) ){
		if ( ma < cnt[i] )
			ma = cnt[i], idx = i;
	}

	cout << lib[idx] << ' ' << ma << '\n';
}