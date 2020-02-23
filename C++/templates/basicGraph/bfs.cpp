// 輸出 bfs 順序
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
vector < pair < int, int > > edges[maxN];
vector < int > output;
bool used[maxN];

int main(){
	int n, m, u, v, w, now;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v >> w;
		edges[u].push_back ( make_pair ( v, w ) );
		edges[v].push_back ( make_pair ( u, w ) );
	}
	queue < int > q;
	q.push ( 0 );
	while ( !q.empty() ){
		now = q.front();
		q.pop();
		used[now] = true;
		output.push_back ( now );
		for ( auto i: edges[now] ){
			if ( used[i] )
				continue;
			q.push ( i );
		}
	}
	for ( auto i: output )
		cout << i << ' ';
	cout << '\n';
}