#include<bits/stdc++.h>
#define maxN 200005
#define x first
#define y second

using namespace std;

#define int long long

vector < int > edge[maxN], data, ps;
set < int > p;
int value[maxN], ans[maxN];
bool prime[maxN];
map < int, set < int > > notPrime;

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return a > b ? b : a;
}

inline bool dfs ( int n, int pss ){
	if ( n == 1 )
		return true;
	for ( auto i: edge[n] ){
		if ( i == pss )
			continue;
		if ( dfs ( i, n ) ){
			if ( !prime[value[i]] ){
				if ( p.find ( value[i] ) == p.end() ){
					ps.push_back ( value[i] );
					p.insert ( value[i] );
				}
			}
			else
				data.push_back ( value[i] );
			return true;
		}
	}

	return false;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	// prime data build
	set < int > stop;

	prime[0] = prime[1] = true;
	for ( int i = 2 ; i < maxN ; i++ )
		if ( !prime[i] ){
			if ( !stop.empty() )
				stop.clear();
			for ( int j = i * 2 ; j < maxN ; j += i ){
				prime[j] = true;
				stop.insert ( j );
			}
			notPrime[i] = stop;
		}

	int n, u, v, g, pa, pb;

	// get data
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> value[i];
	for ( int i = 1 ; i < n ; i++ ){
		cin >> u >> v;
		edge[u].push_back ( v );
		edge[v].push_back ( u );
	}

	// solve
	ans[1] = value[1];
	for ( int i = 2 ; i <= n ; i++ ){
		// memset
		if ( !data.empty() )
			data.clear();
		if ( !p.empty() )
			p.clear();
		if ( !ps.empty() )
			ps.clear();

		if ( prime[value[i]] )
			data.push_back ( value[i] );
		else{
			p.insert ( value[i] );
			ps.push_back ( value[i] );
		}
		dfs ( i, -1 );

		if ( p.empty() ){
			sort ( data.begin(), data.end() );
			g = data[1];
			for ( int i = 2 ; i < data.size() ; i++ )
				g = gcd ( g, data[i] );
		}
		if ( 3 <= p.size() )
			g = 1;
		else if ( p.size() == 1 ){
			g = data[0];
			for ( int i = 1 ; i < data.size() ; i++ )
				g = gcd ( g, data[i] );
		}
		else{
			pa = 0, pb = 0;
			if ( data.empty() )
				g = max ( ps[0], ps[1] );
			else{
				if ( notPrime[ps[0]].find ( data[0] ) != notPrime[ps[0]].end() )
					pa++;
				if ( notPrime[ps[1]].find ( data[0] ) != notPrime[ps[1]].end() )
					pb++;
				g = data[0];
				for ( int i = 1 ; i < data.size() ; i++ ){
					if ( notPrime[ps[0]].find ( data[i] ) != notPrime[ps[0]].end() )
						pa++;
					if ( notPrime[ps[1]].find ( data[i] ) != notPrime[ps[1]].end() )
						pb++;
					g = gcd ( g, data[i] );
				}

				if ( pa == pb )
					g = gcd ( g, max ( ps[0], ps[1] ) );
				else
					g = gcd ( g, ( pa > pb ? ps[0] : ps[1] ) );
			}
		}

		ans[i] = g;
	}

	cout << ans[1];
	for ( int i = 2 ; i <= n ; i++ )
		cout << ' ' << ans[i];
	cout << '\n';
}