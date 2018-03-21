#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a, t;
	string data = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", data2;
	cin >> t;
	for ( int times = 0 ; times < t ; times++ ){
		cin >> a;
		data2 = "";
		for ( int i = a - 1 ; i >= 0 ; i-- )
			data2 += data[i];
		for ( int i = 1 ; i <= a ; i++ ){
			for ( int j = 0 ; j < a - i ; j++ )
				printf ( " " );
			for ( int j = 0 ; j < i ; j++ )
				printf ( "%c", data2[j] );
			for ( int j = i - 2 ; j >= 0 ; j-- )
				printf( "%c", data2[j] );
			printf ( "\n" );
		}
		for ( int i = a - 1 ; i > 0 ; i-- ){
			for ( int j = 0 ; j < a - i ; j++ )
				printf ( " " );
			for ( int j = 0 ; j < i ; j++ )
				printf ( "%c", data2[j] );
			for ( int j = i - 2 ; j >= 0 ; j-- )
				printf( "%c", data2[j] );
			printf ( "\n" );
		}
	}
}