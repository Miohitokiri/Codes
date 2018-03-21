#include<bits/stdc++.h>
#define mod 998244353
#define maxN 5005

using namespace std;

#define int long long

int c[maxN][maxN];

inline int clac ( int x, int y ){
	if ( x > y )
		swap ( x, y );

	int res = 1, basy = 1;

	for ( int i = 1 ; i <= x ; i++ ){
		basy *= ( y - i + 1 );
		basy %= mod;
		res += c[x][i] * basy % mod;
		res %= mod;
	}

	return res;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int a, b, z, ans;
	cin >> a >> b >> z;

	// init
	c[1][0] = c[1][1] = 1;
	for ( int i = 2 ; i < maxN ; i++ ){
		c[i][0] = c[i][i] = 1;
		for ( int j = 1 ; j < i ; j++ ){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= mod;
		}
	}

	// solve
	ans = clac ( a, z ) * clac ( b, z ) % mod * clac ( a, b ) % mod;

	cout << ans << '\n';

	cout << c[100][3] << '\n';
}