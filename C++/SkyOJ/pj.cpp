#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n, stop;
	int data[101];
	scanf ( "%d", &t );
	for ( int times = 0 ; times < t ; times++ ){
		scanf ( "%d", &n );
		memset ( data, 0, sizeof ( data ) );
		for ( int i = 0 ; i < n ; i++ ){
			scanf ( "%d", &stop );
			data[stop]++;
		}
		printf( "Case %d:\n", times + 1 );
		for ( int i = 0 ; i < 101 ; i++ ){
			for ( int j = 0 ; j < data[i] ; j++ )
				printf ( "%d ", i );
		}
		printf ( "\n" );
	}
}