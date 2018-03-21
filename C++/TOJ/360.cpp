#include<bits/stdc++.h>
#define maxN 5005

using namespace std;

vector < int > edge[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, u, v;
	cin >> n;
	while ( n-- ){
		cin >> u >> v;
		edge[u].push_back ( v );
		edge[v].push_back ( u );
	}

	dfs ( i, -1 );
}