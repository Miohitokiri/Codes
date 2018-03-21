#include<bits/stdc++.h>
#define maxN 10005

using namespace std;

typedef pair < int, int > pii;

int dist[maxN];
vector < pii > edge[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m, u, v, w, ed;
	memset ( dist, 0x3f3f3f3f, sizeof dist );
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v >> w;
		edge[u].push_back ( pii ( v, w ) );
		edge[v].push_back ( pii ( u, w ) );
	}
	cin >> u >> ed;

	dist[u] = 0;
	priority_queue < pii, vector < pii >, greater < pii > > pq;
	pq.push ( pii ( 0, u ) );
	while ( !pq.empty() ){
		int d = pq.top().first, node = pq.top().second;
		pq.pop();
		if ( dist[node] < d )
			continue;
		for ( int i = 0 ; i < edge[node].size() ; i++ ){
			v = edge[node][i].first;
			int cost = edge[node][i].second;
			if ( dist[v] > d + cost ){
				dist[v] = d + cost;
				pq.push ( pii ( dist[v], v ) );
			}
		}
	}

	cout << dist[ed] << '\n';
}