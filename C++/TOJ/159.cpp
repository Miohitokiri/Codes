#include<bits/stdc++.h>

using namespace std;

#define int long long

int bit[100010], in[50005], out[50005], size, cost[50005];
vector < int > edge[50005];

inline void dfs ( int x ){
	in[x] = ++size;
	for ( auto i: edge[x] )
		if ( in[i] == -1 )
			dfs ( i );

	out[x] = ++size;
}

inline void add ( int i, int value ){
	while ( i <= size ){
		bit[i] += value;
		i += i & -i;
	}
}

inline int sum ( int i ){
	int re = 0;
	while ( i ){
		re += bit[i];
		i -= i & -i;
	}
	return re;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m, a, b, ans = 0;
	char type;
	cin >> n >> m;
	for ( int i = 1 ; i < n ; i++ ){
		cin >> a >> b;
		edge[a].push_back ( b );
		edge[b].push_back ( a );
	}

	memset ( in, -1, sizeof ( in ) );

	dfs ( 1 );

	for ( int i = 1 ; i <= n ; i++ ){
		cin >> cost[i];
		add ( in[i], cost[i] );
		add ( out[i], -cost[i] );
	}

	while ( m-- ){
		cin >> type;
		if ( type == 'C' ){
			cin >> a >> b;
			add ( in[a], b - cost[a] );
			add ( out[a], cost[a] - b );
			cost[a] = b;
		}
		else{
			cin >> a;
			ans += sum ( in[a] );
		}
	}

	cout << ans << '\n';
}