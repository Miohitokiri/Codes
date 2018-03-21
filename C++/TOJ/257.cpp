#include<bits/stdc++.h>

using namespace std;

int dp[4005][4005];

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int mother, son, g;
	string a, b;
	while ( cin >> a >> b ){
		memset ( dp, 0, sizeof ( dp ) );
		for ( int i = 0 ; i < a.size() ; i++ )
			for ( int j = 0 ; j < b.size() ; j++ )
				if ( a[i] == b[j] )
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max ( dp[i][j + 1], dp[i + 1][j] );
		son = dp[a.size()][b.size()];
		for ( int i = 0 ; i < a.size() ; i++ )
			if ( a[i] == 'T' )
				a[i] = 'A';
			else if ( a[i] == 'C' )
				a[i] = 'G';
			else if ( a[i] == 'A' )
				a[i] = 'T';
			else
				a[i] = 'C';
		// cout << a << '\n' << b << '\n'; // del

		memset ( dp, 0, sizeof ( dp ) );
		mother = a.size() + b.size();
		for ( int i = 0 ; i < a.size() ; i++ )
			for ( int j = 0 ; j < b.size() ; j++ )
				if ( a[i] == b[j] )
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max ( dp[i][j + 1], dp[i + 1][j] );
		
		son = max ( dp[a.size()][b.size()], son );
		son *= 2;
		if ( son != 0 ){
			g = gcd ( mother, son );
			son /= g;
			mother /= g;
		}
		printf ( "%d/%d\n", son, mother );
	}
}