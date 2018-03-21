#include<bits/stdc++.h>

using namespace std;

struct e{
	int to, w;
	e ( int a, int b ): to ( a ), w ( b ) {}
};

vector < e > edge[100005];
int dis[100005];

void dfs ( int x, int p ){
	for ( e i: edge[x] ){
		int y = i.to;
		if ( y == p )
			continue;
		dis[y] = dis[x] + i.w;
		dfs ( y, x );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, s, t, w;
	cin >> n >> m;
	while ( m-- ){
		cin >> s >> t >> w;
		edge[s].emplace_back ( t, w );
		edge[t].emplace_back ( s, w );
	}

	dis[0] = 0;
	dfs ( 0, -1 );

	int rt = max_element ( dis, dis + n ) - dis;
	dis[rt] = 0;
	dfs ( rt, -1 );

	cout << *max_element ( dis, dis + n ) << '\n';
}