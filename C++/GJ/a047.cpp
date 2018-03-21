#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	while ( cin >> n ){
		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 1 ; j <= i ; j++ )
				cout << i;
			cout << '\n';
		}
	}
}