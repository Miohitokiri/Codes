/************************************/
/* Date		: 2019-11-04 21:40:45	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/


#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;


#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )


typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair


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


typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )


#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )


#define GL(n) getline ( cin, n )


template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;


#define sstr stringstream


#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 10005

int ans[maxN];
int len[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, d, in, sum = 0, idx = 0, dis, swp;
	vec < pii > data;
	bool flag;
	cin >> n >> m >> d;
	for ( int i = 1 ; i <= m ; i++ ){
		cin >> in;
		data.pb ( pii ( in, i ) );
		sum += in;
	}

	if ( sum + d > n ){
		cout << "YES\n";
		for ( int i = 0 ; i < m ; i++ ){
			while ( data[i].F-- )
				cout << data[i].S << ' ';
		}

		n -= sum;
		while ( n-- )
			cout << "0 ";
		cout << '\n';
		return 0;
	}

	if ( ( double ) ( n - sum ) / ( m + 1 ) > d - 1 ){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	if ( n - sum <= m - 1 ){
		int i;
		d = n - sum;
		for ( idx = i = 0 ; i < d ; i++ ){
			idx += 1;
			for ( int cnt = 0 ; cnt < data[i].F ; cnt++, idx++ ){
				ans[idx] = data[i].S;
			}
		}

		for ( i ; i < m ; i++ ){
			for ( int cnt = 0 ; cnt < data[i].F ; cnt++, idx++ ){
				ans[idx] = data[i].S;
			}
		}
	}
	else{
		if ( n - sum == m ){
			flag = false;
			dis = 1;
		}
		else{
			flag = true;
			dis = ( n - sum ) / ( m + 1 );
		}

		swp = ( n - sum ) / dis;
		REPP ( i, 0, swp ){
			len[i] = dis;
		}
		swp = n - sum - dis * ( m + ( int ) flag );

		REPP ( i, 0, swp ){
			++len[i];
		}
		idx = 0;
		for ( int i = 0 ; i < m ; i++ ){
			idx += len[i];
			for ( int cnt = 0 ; cnt < data[i].F ; cnt++, idx++ ){
				ans[idx] = data[i].S;
			}
		}
	}

	for ( int i = 0 ; i < n ; i++ )
		cout << ans[i] << ' ';
	cout << '\n';
}