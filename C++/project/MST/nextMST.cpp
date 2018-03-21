#include<bits/stdc++.h>
#define maxN 5005
#define x first
#define y second

using namespace std;

typedef pair < int, int > pii;

struct disjoinSet{
	int dis[maxN];

	inline void Init ( int n ){
		for ( int i = 0 ; i <= n ; i++ )
			dis[i] = i;
	}

	inline int find ( int n ){
		return dis[n] == n ? n : dis[n] = find ( dis[n] );
	}

	inline void Union ( int a, int b ){
		dis[find ( a )] = find ( b );
	}

	inline bool same ( int a, int b ){
		return find ( a ) == find ( b );
	}
} dis;

struct bridge{
	int u, v, value;
};

vector < bridge > data;
vector < pii > edge[maxN];
// first -> node
// second -> value of a to b

inline bool cmp ( bridge a, bridge b ){
	return a.value < b.value;
}

inline void dijkstra ( int n ){
	vector < bridge > noUsed;
	sort ( data.begin(), data.end(), cmp );
	dis.Init ( n );
	for ( auto i: data ){
		if ( dis.same ( i.u, i.v ) ){
			noUsed.push_back ( i );
			continue;
		}
		dis.Union ( i.u, i.v );
		edge[i.u].push_back ( make_pair ( i.v, i.value ) );
		edge[i.v].push_back ( make_pair ( i.u, i.value ) );
	}
	bridge i = noUsed[0];
	if ( edge[i.u].size() > edge[i.v].size() )
		swap ( i.u, i.v );
	for ( int j = 0 ; j < edge[i.u].size() ; j++ )
		if ( edge[i.u][j].first == i.v )
			edge[i.u][j].second = i.vaue;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, ans = 0;
	bridge stop;
	cin >> n >> m;
	while ( m-- ){
		cin >> stop.u >> stop.v >> stop.value;
		data.push_back ( stop );
	}

	dijkstra ( n );

	for ( int i = 1 ; i <= n ; i++ ){
		cout << i << ":";
		for ( auto j: edge[i] ){
			cout << ' ' << j.x;
			ans += j.y;
		}
		cout << '\n';
	}

	ans /= 2;
	cout << ans << '\n';
}