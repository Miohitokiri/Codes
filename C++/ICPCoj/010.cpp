#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int data[7], p;
	for ( int i = 0 ; i < 7 ; i++ )
		cin >> data[i];

	for ( auto i: data )
		if ( i > 31 ){
			cout << "Impossible\n";
			return 0;
		}

	p = data[0];
	for ( int i = 1 ; i < 7 ; i++ ){
		if ( p == data[i] ){
			cout << "Impossible\n";
			return 0;
		}
		if ( p + 1 != data[i] && ( p != 31 || p != 30 ) && data[i] != 1 ){
			cout << "Impossible\n";
			return 0;
		}
		p = data[i];
	}

	cout << "Possible\n";
}