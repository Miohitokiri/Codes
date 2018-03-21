#include<bits/stdc++.h>

using namespace std;

#define int long long

vector < int > edge[100005];
set < int > blue, green;

void dfs ( int x, int p, int size ){
	if ( size & 1 )
		blue.insert ( x );
	else
		green.insert ( x );
	for ( auto i: edge[x] ){
		if ( i == p )
			continue;
		dfs ( i, x, size + 1 );
	}
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, a, b;
	cin >> n;
	for ( int i = 1 ; i < n ; i++ ){
		cin >> a >> b;
		edge[a].push_back ( b );
		edge[b].push_back ( a );
	}

	dfs ( 1, -1, 1 );

	// cout << blue.size() << ' ' << green.size() << '\n';

	cout << blue.size() * green.size() - n + 1 << '\n';
}