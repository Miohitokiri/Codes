#include<iostream>
#include<cmath>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	bool ans;
	while ( cin >> n ){
		ans = true;
		for ( int i = 2 ; i <= sqrt ( n ) && ans ; i++ )
			if ( n % i == 0 )
				ans = false;

		cout << ( ans ? "YES" : "NO" ) << '\n';
	}
}