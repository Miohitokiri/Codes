#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, m, stop, ma, sum;
	vector < int > data;
	while ( cin >> n >> m ){
		if ( !n && !m )
			break;

		data.resize ( n );
		ma = 0;
		cin >> sum;
		for ( int i = 1 ; i < n ; i++ ){
			cin >> stop;
			sum *= 10;
			sum += stop;
		}

		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = 0 ; j <= i ; j++ )
				stop = sum / pow ( 10, j );
				stop %= ( int ) pow ( 10, n - i );

				if ( gcd ( stop, m ) == 1 )
					ma = max ( ma, ( int ) log10 ( stop ) + 1 );
			}

		cout << ma << '\n';
	}
}