#include<bits/stdc++.h>

using namespace std;

// #define int long long

vector < int > data[100005];
int dis[100005];

inline void dfs ( int x, int p ){
	for ( auto i: data[x] ){
		if ( i == p )
			continue;

		dis[i] = dis[x] + 1;
		dfs ( i, x );
	}
}

// #undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	// #define int long long

	int n, m, a, b;
	cin >> n >> m;
	for ( int i = 0 ; i < m ; i++ ){
		cin >> a >> b;
		data[a].push_back ( b );
		data[b].push_back ( a );
	}

	dis[0] = 0;
	dfs ( 0, -1 );

	int rt = max_element ( dis, dis + n ) - dis;

	dis[rt] = 0;
	dfs ( rt, -1 );

	cout << *max_element ( dis, dis + n ) << '\n';
}