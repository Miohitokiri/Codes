#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

#define int long long

typedef pair < int, int > pii;

int dis[5005];
vector < pair < int, pii > > data;

inline void Init ( int n ){
	for ( int i = 0 ; i <= n ; i++ )
		dis[i] = i;
}

inline int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ){
	dis[a] = b;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m, k, w, x, y, ans = 0;
	pii node;

	cin >> n >> m >> k;
	Init ( n );
	while ( m-- ){
		cin >> node.x >> node.y >> w;;
		data.push_back ( make_pair ( w, node ) );
	}

	if ( k == -1 )
		k = n;

	sort ( data.begin(), data.end() );

	for ( int i = 0, used = 0 ; i < data.size() ; i++ ){
		if ( used >= ( n - k ) && data[i].x > 0 )
			break;

		x = find ( data[i].y.x ), y = find ( data[i].y.y );
		if ( x != y ){
			Union ( x, y );
			used++;
			ans += data[i].x;
		}
	}

	cout << ans << '\n';
}