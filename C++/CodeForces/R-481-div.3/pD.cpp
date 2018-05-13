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
#define maxN 100005

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	#define int LL

	int n, sum = 0;
	vi data, data2;
	si used;
	cin >> n;
	GETDATA ( data, n );
	REPP ( i, 1, n ){
		used.insert ( data[i] - data[i - 1] );
		data2.pb ( data[i] - data[i - 1] );
		sum += data[i] - data[i - 1];
	}

	if ( SZ ( used ) == 1 ){
		cout << 0 << '\n';
		return 0;
	}

	REPP ( i, 1, SZ ( data2 ) ){
		if ( abs ( data2[i] - data2[i - 1] ) > 4 ){
			cout << -1 << '\n';
			return 0;
		}
	}

	int ww = n - 1;
	if ( sum % ww && ( sum + 1 ) % ww && ( sum + 2 ) % ww && ( sum - 1 ) % ww && ( sum - 2 ) % ww ){
		cout << -1 << '\n';
		return 0;
	}

	int cnt = 0, cnt2 = 0;
	if ( ( sum + 1 ) % ww == 0 || ( sum - 1 ) % ww == 0 ){
		if ( ( sum + 1 ) % ww == 0 )
			sum++;
		else
			sum--;
		cnt++;
	}
	else if ( ( sum + 2 ) % ww == 0 || ( sum - 2 ) % ww == 0 ){
		if ( ( sum + 2 ) % ww == 0 )
			sum += 2;
		else
			sum -= 2;
		cnt += 2;
	}
	sum /= ww;
	REPALL ( i, data2 ){
		if ( abs ( i - sum ) > 4 ){
			cout << -1 << '\n';
			return 0;
		}
		cnt2 += abs ( i - sum );
	}
	cnt2 /= 2;
	cout << cnt + cnt2 << '\n';
}