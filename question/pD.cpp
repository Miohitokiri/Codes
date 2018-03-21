#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int t, n, k;
	cin >> t;
	t--;
	while ( t-- ){
		cin >> n >> k;
		while ( k-- ){
			for ( int i = 1 ; i <= n ; i++ ){
				for ( int j = 0 ; j < i ; j++ )
					cout << i;
				cout << '\n';
			}
			for ( int i = n - 1 ; i >= 0 ; i-- ){
				for ( int j = 0 ; j < i ; j++ )
					cout << i;
				cout << '\n';
			}
			// cout << '\n';
		}
	}

	cin >> n >> k;
	k--;
	while ( k-- ){
		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 0 ; j < i ; j++ )
				cout << i;
			cout << '\n';
		}
		for ( int i = n - 1 ; i >= 0 ; i-- ){
			for ( int j = 0 ; j < i ; j++ )
				cout << i;
			cout << '\n';
		}
	}
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 0 ; j < i ; j++ )
			cout << i;
		cout << '\n';
	}
	for ( int i = n - 1 ; i > 0 ; i-- ){
		for ( int j = 0 ; j < i ; j++ )
			cout << i;
		cout << '\n';
	}
	cout << 1;
}