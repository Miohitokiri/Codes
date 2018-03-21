#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	while ( cin >> n ){
		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = n - i - 1 ; j >= 0 ; j-- )
				cout << "_";
			for ( int j = 0 ; j < i * 2 - 1 ; j++ )
				cout << i;
			cout << '\n';
		}
	}
}