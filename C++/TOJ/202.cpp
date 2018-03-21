#include<bits/stdc++.h>
#define maxN 105

using namespace std;

typedef pair < int, int > pii;
vector < pii > edge[maxN];
int s, now, Index;
bool used[maxN];

inline void dfs ( int n ){
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, u, v, w, q;
	cin >> n >> m >> s;
	while ( m-- ){
		cin >> u >> v >> w;
		edge[u].push_back ( pii ( u, w ) );
		edge[v].push_back ( pii ( v, w ) );
	}

	cin >> q;
	while ( q-- ){
		cin >> u >> Index;
		now = s;
		dfs ( s );
	}
}