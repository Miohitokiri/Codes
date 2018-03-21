#include<bits/stdc++.h>
#define maxN 100005

using namespace std;

struct disjoinSet{
	int dis[maxN], rank[maxN];

	inline void Init ( int n ){
		for ( int i = 0 ; i <= n ; i++ ){
			dis[i] = i;
			rank[i] = 1;
		}
	}

	inline int find ( int n ){
		return dis[n] == n ? n : dis[n] = find ( dis[n] );
	}

	inline void Union ( int a, int b ){
		a = find ( a ), b = find ( b );
		if ( a == b )
			return;
		dis[b] = a;
		rank[a] += rank[b];
	}

	inline bool same ( int a, int b ){
		return find ( a ) == find ( b );
	}
} dis;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, q, a, b, cnt = 0;
	char type;
	cin >> t;
	while ( t-- ){
		cout << "Case " << ++cnt << ":\n";
		cin >> n >> q;
		dis.Init ( n );

		while ( q-- ){
			cin >> type;
			if ( type == 'M' ){
				cin >> a >> b;
				dis.Union ( a, b );
			}
			else if ( type == 'Q' ){
				cin >> a >> b;
				cout << ( dis.same ( a, b ) ? "YES" : "NO" ) << '\n';
			}
			else{
				cin >> a;
				cout << dis.rank[dis.find ( a )] << '\n';
			}
		}
	}
}