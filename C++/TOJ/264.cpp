#include<bits/stdc++.h>

using namespace std;

#define int long long

bool prime[1000005];
int ans[1000005], n;

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	for ( int i = 2 ; i < 1000005 ; i++ )
		if ( !prime[i] ){
			for ( int j = i * 2 ; j < 1000005 ; j += i )
				prime[j] = true;
		}

	for ( int i = 2 ; i < 1000005 ; i++ )
		if ( !prime[i] )
			for ( int k = i * i ; k < 1000005 ; k *= i )
				prime[k] = false;

	ans[1] = 0;

	for ( int i = 2 ; i < 1000005 ; i++ ){
		if ( prime[i] )
			ans[i] = ans[i - 1];
		else
			ans[i] = ans[i - 1] + 1;
	}

	// for ( int i = 2 ; i < 10 ; i++ ) // del
		// cout << ans[i] << ' '; // del
	// cout << "\n\n"; // del

	while ( cin >> n )
		cout << ans[n] << '\n';
}