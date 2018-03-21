#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	while ( cin >> a ){
		for ( int i = 1 ; i <= a ; i++ ){
			for ( int j = 0 ; j < a - i ; j++ )
				cout << ' ';
			for ( int j = 0 ; j < i ; j++ )
				cout << ( char ) ( 65 + j ) ;
			for ( int j = i - 2 ; j >= 0 ; j-- )
				cout << ( char ) ( 65 + j );
			cout << '\n';
		}
		for ( int i = a - 1 ; i >= 1 ; i-- ){
			for ( int j = 0 ; j < a - i ; j++ )
				cout << ' ';
			for ( int j = 0 ; j < i ; j++ )
				cout << ( char ) ( 65 + j ) ;
			for ( int j = i - 2 ; j >= 0 ; j-- )
				cout << ( char ) ( 65 + j );
			cout << '\n';
		}
	}
}