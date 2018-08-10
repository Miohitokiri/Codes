// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPALL(i,n) for ( auto &i: n )
#define MEM(n,i) memset ( n, i, sizeof n )

typedef set < int > si;
#define CLR(n) n.clear()

#define GL(n) getline ( cin, n )

si edge[30];
bool go[30];

inline void dfs ( int n ){
	go[n] = true;
	REPALL ( i, edge[n] )
		if ( !go[i] )
			dfs ( i );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str;
	int n, u, v, ans, cnt = 0, t;
	cin >> t;
	t++;
	while ( t-- ){
		GL ( str );
		MEM ( go, 0 );
		REPP ( i, 0, 30 )
			CLR ( edge[i] );

		n = str[0] - 'A';
		ans = 0;
		while ( GL ( str ) ){
			if ( EMP ( str ) )
				break;

			u = str[0] - 'A', v = str[1] - 'A';
			edge[u].insert ( v );
			edge[v].insert ( u );
		}

		n++;
		REPP ( i, 0, n )
			if ( !go[i] ){
				ans++;
				dfs ( i );
			}

		if ( !cnt++ )
			continue;
		if ( cnt++ > 2 )
			cout << '\n';

		cout << ans << "\n";
	}
}