// 輸出 dfs 順序
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
vector < int > edges[maxN];
vector < int > output;
bool used[maxN];

// 用遞迴來模擬 stack
void dfs ( int n ){
	used[n] = true;
	output.push_back ( n );
	for ( auto i: edges[n] ){
		if ( used[i] )
			continue;
		dfs ( i );
	}
}

int main(){
	int n, m, u, v, w;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v >> w;
		edges[u].push_back ( v );
		edges[v].push_back ( u );
	}
	dfs ( 0 );
	for ( auto i: output )
		cout << i << ' ';
	cout << '\n';
}